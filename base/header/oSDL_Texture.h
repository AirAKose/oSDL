#ifndef _MY_TEXTURE_HEADER_

#define _MY_TEXTURE_HEADER_

#include <SDL.h>
#include <string>


namespace oSDL
{
	class Renderer2D;
	class Vector2;
	class Rect;
	class Point;
	class Color;

	class Texture
	{
	private:
		SDL_Texture* _texture;
		SDL_Renderer* _renderer;
		oSDL::Color* _color;

		int _width = 0, _height = 0,
			_access = SDL_TEXTUREACCESS_TARGET;

		Uint32 _format = SDL_PIXELFORMAT_RGBA8888;
	public:
		Texture(oSDL::Renderer2D* render, int access = SDL_TEXTUREACCESS_TARGET, Uint32 format = SDL_PIXELFORMAT_RGBA8888);
		Texture(oSDL::Texture& copy);
		~Texture();

		int FromFile(std::string path);		// Unmanaged. Use ContentManager for managed texture loading.
		int FromSurface(SDL_Surface* surface);		// Unmanaged. Use ContentManager for managed texture loading.

		void SetBlendMode(SDL_BlendMode mode);

		void SetColorMod(const oSDL::Color& color);
		void SetColorMod(const SDL_Color& color);
		void SetColorMod(unsigned int colorHex);
		void SetColorMod(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);

		oSDL::Color GetColorMod();
		SDL_BlendMode GetBlendMode();
		int GetWidth();
		int GetHeight();
		int GetAccess();
		int GetFormat();

		SDL_Texture* BaseTexture();

		SDL_Color* Lock();
		void Unlock(SDL_Color* color);

		void Clone(oSDL::Texture* tex);				// Makes this texture a copy of the provided texture. Does not work if SDL_TEXTUREACCESS_TARGET is not enabled
		virtual void Destroy();

		int Draw( int x, int y); // Texture and position, draws entire texture in full-resolution
		int Draw( const oSDL::Vector2& pos); // Texture and position, draws entire texture in full-resolution

		int Draw( int x, int y, float scale); // Texture, position, and uniform scale
		int Draw( const oSDL::Vector2& pos, float scale); // Texture, position, and uniform scale

		int Draw( int x, int y, int w, int h); // Texture, position, and scale along X and Y
		int Draw( const oSDL::Vector2& pos, const oSDL::Vector2& size); // Texture, position, and scale along X and Y
		int Draw( const oSDL::Rect& rect); // Texture, position, and scale along X and Y



		/********************************************************************************************/
		/*					Here begins the Texture Source / Destination overloads					*/
		/********************************************************************************************/
		int Draw( int sourceX, int sourceY, int sourceW, int sourceH, int destinX, int destinY);
		int Draw( const oSDL::Vector2& sourcePos, const oSDL::Vector2& sourceSize, const oSDL::Vector2& destinPos);
		int Draw( const oSDL::Rect& sourceRect, const oSDL::Vector2& destinPos);

		int Draw( int sourceX, int sourceY, int sourceW, int sourceH, int destinX, int destinY, int destinW, int destinH);
		int Draw( const oSDL::Vector2& sourcePos, const oSDL::Vector2& sourceSize, const oSDL::Vector2& destinPos, const oSDL::Vector2& destinSize);
		int Draw( const oSDL::Rect& sourceRect, const oSDL::Rect& destinRect);


		int Draw( int sourceX, int sourceY, int sourceW, int sourceH, int destinX, int destinY, int destinW, int destinH, int pivotX, int pivotY, double rotation, SDL_RendererFlip flip = SDL_FLIP_NONE);
		int Draw( oSDL::Vector2 sourcePos, oSDL::Vector2 sourceSize, oSDL::Vector2 destinPos, oSDL::Vector2 destinSize, oSDL::Point& pivot, double rotation, SDL_RendererFlip flip = SDL_FLIP_NONE);
		int Draw( const oSDL::Rect& source, const oSDL::Rect& destination, const oSDL::Point& pivot, double rotation, SDL_RendererFlip flip = SDL_FLIP_NONE);
	};
}

#endif