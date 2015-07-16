#include <SDL.h>
#include <SDL_image.h>
#include "oSDL_Texture.h"
#include "oSDL_Renderer2D.h"
#include "oSDL_Utilities.h"



oSDL::Texture::Texture(oSDL::Renderer2D* render, int access, Uint32 format)
{
	_renderer	= render->BaseRenderer();
	_access		= access;
	_format		= format;
	_color		= new oSDL::Color(255,255,255,255);
}


oSDL::Texture::Texture(oSDL::Texture& copy)
{
	this->Clone(&copy);
}


oSDL::Texture::~Texture()
{
	this->Destroy();
}

int oSDL::Texture::FromFile(std::string path)
{
	// First destroy the SDL_Texture if it already has one
	if (_texture != NULL)
		SDL_DestroyTexture(_texture);

	_texture = IMG_LoadTexture(_renderer, path.c_str());
	if (SDL_QueryTexture(_texture, &_format, &_access, &_width, &_height) != 0)
		return -1;
	SetColorMod(255,255,255);
	return 0;
}
int oSDL::Texture::FromSurface(SDL_Surface* surface)
{
	// Clean up any textures that may already exist
	if (_texture != NULL)
		SDL_DestroyTexture(_texture);

	_texture = SDL_CreateTextureFromSurface(_renderer,surface);
	if (SDL_QueryTexture(_texture, &_format, &_access, &_width, &_height) != 0)
		return -1;
	SetColorMod(255, 255, 255);
	return 0;
}

void oSDL::Texture::SetBlendMode(SDL_BlendMode mode)
{
	SDL_SetTextureBlendMode(_texture, mode);
}


inline void SetTextureColor(SDL_Texture* tex,Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetTextureColorMod(tex, r, g, b);
	SDL_SetTextureAlphaMod(tex, a);
}
void oSDL::Texture::SetColorMod(Uint8 r,Uint8 g, Uint8 b, Uint8 a)
{
	_color->Set(r, g, b, a);
	SetTextureColor(_texture,_color->r, _color->g, _color->b,_color->a);
}
void oSDL::Texture::SetColorMod(const oSDL::Color& color)
{
	_color->Set(color);
	SetTextureColor(_texture, _color->r, _color->g, _color->b, _color->a);
}
void oSDL::Texture::SetColorMod(const SDL_Color& color)
{
	_color->Set(color);
	SetTextureColor(_texture, _color->r, _color->g, _color->b, _color->a);
}
void oSDL::Texture::SetColorMod(unsigned int colorHex)
{
	_color->Set(colorHex);
	SetTextureColor(_texture, _color->r, _color->g, _color->b, _color->a);
}

oSDL::Color oSDL::Texture::GetColorMod()
{
	return *_color;
}

SDL_BlendMode oSDL::Texture::GetBlendMode()
{
	SDL_BlendMode val;
	SDL_GetTextureBlendMode(_texture,&val);
	return val;
}
int oSDL::Texture::GetWidth()
{
	return _width;
}
int oSDL::Texture::GetHeight()
{
	return _height;
}
int oSDL::Texture::GetAccess()
{
	return _access;
}
int oSDL::Texture::GetFormat()
{
	return _format;
}
SDL_Texture* oSDL::Texture::BaseTexture()
{
	return _texture;
}




void oSDL::Texture::Clone(oSDL::Texture* tex)
{
	// Copy all of the properties of the provided Texture
	_renderer = tex->_renderer;
	_format = tex->_format;
	_access = tex->_access | SDL_TEXTUREACCESS_TARGET;
	_width = tex->_width;
	_height = tex->_height;

	_color->Set(*tex->_color);


	// If this texture already has an SDL_Texture defined, Destroy it
	if (_texture != NULL)
	{
		SDL_DestroyTexture(_texture);
		_texture = NULL;
	}

	// If the texture to copy is null, no need to go further
	if (tex->_texture == NULL)
		return;

	// Create a new Texture using the new properties
	_texture = SDL_CreateTexture(_renderer, _format, _access, _width, _height);

	// Store the renderer's current target
	SDL_Texture* oldTarget = SDL_GetRenderTarget( _renderer );

	// Set the render target to the new Texture
	SDL_SetRenderTarget( _renderer, _texture);

	// Draw the texture to be copied onto the new Texture
	Draw(0,0,_width,_height);

	// Set the render target back to what it was before
	SDL_SetRenderTarget(_renderer, oldTarget);
}

void oSDL::Texture::Destroy()
{
	// If the texture exists, delete it
	if (_texture != NULL)
		SDL_DestroyTexture(_texture);
	_texture = NULL;

	// Null the renderer, it may be in use else-where
	_renderer = NULL;

	if (_color != NULL)
		delete _color;
	_color = NULL;

	// LEAVE NOTHING TO BE SALVAGED. RUIN THEIR CHANCES
	_format = 0;
	_access = 0;
	_width = 0;
	_height = 0;

}

/********************************************************
*	Start DrawTexture Overloads
*		First by destination
*		Then by source, destination
*		Then by source, destination, rotation
*********************************************************/


/********************************************************
*	Destination-based rendering
*********************************************************/
int oSDL::Texture::Draw( int x, int y)
{
	oSDL::Rect rect(x, y, this->GetWidth(), this->GetHeight());
	return SDL_RenderCopy(_renderer, this->BaseTexture(), NULL, &rect);
}
int oSDL::Texture::Draw( const oSDL::Vector2& pos)
{
	oSDL::Rect rect((int)pos.x, (int)pos.y, this->GetWidth(), this->GetHeight());
	return SDL_RenderCopy(_renderer, this->BaseTexture(), NULL, &rect);
}

int oSDL::Texture::Draw( int x, int y, float scale)
{
	oSDL::Rect rect(x, y, (int)(this->GetWidth()*scale), (int)(this->GetHeight()*scale));
	return SDL_RenderCopy(_renderer, this->BaseTexture(), NULL, &rect);
}
int oSDL::Texture::Draw( const oSDL::Vector2& pos, float scale)
{
	oSDL::Rect rect((int)pos.x, (int)pos.y, (int)(this->GetWidth()*scale), (int)(this->GetHeight()*scale));
	return SDL_RenderCopy(_renderer, this->BaseTexture(), NULL, &rect);
}

int oSDL::Texture::Draw( int x, int y, int w, int h)
{
	oSDL::Rect rect(x, y, w, h);
	return SDL_RenderCopy(_renderer, this->BaseTexture(), NULL, &rect);
}
int oSDL::Texture::Draw( const oSDL::Vector2& pos, const oSDL::Vector2& size)
{
	oSDL::Rect rect((int)pos.x, (int)pos.y, (int)size.x, (int)size.y);
	return SDL_RenderCopy(_renderer, this->BaseTexture(), NULL, &rect);
}
int oSDL::Texture::Draw( const oSDL::Rect& rect)
{
	return SDL_RenderCopy(_renderer, this->BaseTexture(), NULL, &rect);
}



/********************************************************************************************
*	Source AND Destination-based rendering
********************************************************************************************/
int oSDL::Texture::Draw( int sourceX, int sourceY, int sourceW, int sourceH, int destinX, int destinY)
{
	oSDL::Rect src(sourceX, sourceY, sourceW, sourceH);
	oSDL::Rect dst(destinX, destinY, this->GetWidth(), this->GetHeight());
	return SDL_RenderCopy(_renderer, this->BaseTexture(), &src, &dst);
}
int oSDL::Texture::Draw( const oSDL::Vector2& sourcePos, const oSDL::Vector2& sourceSize, const oSDL::Vector2& destinPos)
{
	oSDL::Rect src((int)sourcePos.x, (int)sourcePos.y, (int)sourceSize.x, (int)sourceSize.y);
	oSDL::Rect dst((int)destinPos.x, (int)destinPos.y, (int)this->GetWidth(), (int)this->GetHeight());
	return SDL_RenderCopy(_renderer, this->BaseTexture(), &src, &dst);
}
int oSDL::Texture::Draw( const oSDL::Rect& sourceRect, const oSDL::Vector2& destinPos)
{
	oSDL::Rect dst((int)destinPos.x, (int)destinPos.y, (int)this->GetWidth(), (int)this->GetHeight());
	return SDL_RenderCopy(_renderer, this->BaseTexture(), &sourceRect, &dst);
}

int oSDL::Texture::Draw( int sourceX, int sourceY, int sourceW, int sourceH, int destinX, int destinY, int destinW, int destinH)
{
	oSDL::Rect src(sourceX, sourceY, sourceW, sourceH);
	oSDL::Rect dst(destinX, destinY, destinW, destinH);
	return SDL_RenderCopy(_renderer, this->BaseTexture(), &src, &dst);
}
int oSDL::Texture::Draw( const oSDL::Vector2& sourcePos, const oSDL::Vector2& sourceSize, const oSDL::Vector2& destinPos, const oSDL::Vector2& destinSize)
{
	oSDL::Rect src((int)sourcePos.x, (int)sourcePos.y, (int)sourceSize.x, (int)sourceSize.y);
	oSDL::Rect dst((int)destinPos.x, (int)destinPos.y, (int)destinSize.x, (int)destinSize.y);
	return SDL_RenderCopy(_renderer, this->BaseTexture(), &src, &dst);
}
int oSDL::Texture::Draw( const oSDL::Rect& sourceRect, const oSDL::Rect& destinRect)
{
	return SDL_RenderCopy(_renderer, this->BaseTexture(), &sourceRect, &destinRect);
}



/********************************************************
*	Source, Destination, AND rotation-based rendering
*********************************************************/
int oSDL::Texture::Draw( int sourceX, int sourceY, int sourceW, int sourceH, int destinX, int destinY, int destinW, int destinH, int pivotX, int pivotY, double rotation, SDL_RendererFlip flip)
{
	oSDL::Rect src(sourceX, sourceY, sourceW, sourceH);
	oSDL::Rect dst(destinX, destinY, destinW, destinH);
	oSDL::Point pivot(pivotX, pivotY);
	return SDL_RenderCopyEx(_renderer, this->BaseTexture(), &src, &dst, rotation, &pivot, flip);
}
int oSDL::Texture::Draw( oSDL::Vector2 sourcePos, oSDL::Vector2 sourceSize, oSDL::Vector2 destinPos, oSDL::Vector2 destinSize, oSDL::Point& pivot, double rotation, SDL_RendererFlip flip)
{
	oSDL::Rect src((int)sourcePos.x, (int)sourcePos.y, (int)sourceSize.x, (int)sourceSize.y);
	oSDL::Rect dst((int)destinPos.x, (int)destinPos.y, (int)destinSize.x, (int)destinSize.y);
	return SDL_RenderCopyEx(_renderer, this->BaseTexture(), &src, &dst, rotation, &pivot, flip);
}
int oSDL::Texture::Draw( const oSDL::Rect& source, const oSDL::Rect& destination, const oSDL::Point& pivot, double rotation, SDL_RendererFlip flip)
{
	return SDL_RenderCopyEx(_renderer, this->BaseTexture(), &source, &destination, rotation, &pivot, flip);
}