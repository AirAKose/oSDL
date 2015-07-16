#include <SDL.h>
#include "oSDL_Window.h"
#include "oSDL_Renderer2D.h"
#include "oSDL_Utilities.h"



oSDL::Renderer2D::Renderer2D(oSDL::Window* window, SDL_RendererFlags flags)
{
	_window = window->BaseWindow();
	_renderer = SDL_CreateRenderer(_window, -1, flags);
}
oSDL::Renderer2D::Renderer2D(oSDL::Renderer2D& copy)
{
	SDL_RendererInfo* info=NULL;
	SDL_GetRendererInfo(copy._renderer,info);
	_renderer = SDL_CreateRenderer(copy._window,-1,info->flags);
	_window = copy._window;
	SDL_SetRenderTarget(_renderer, SDL_GetRenderTarget(copy._renderer));
}
oSDL::Renderer2D::~Renderer2D()
{
	Destroy();
	_window = NULL;
}

void oSDL::Renderer2D::SetViewport(int x, int y, int w, int h)
{
	oSDL::Rect rect(x,y,w,h);
	SDL_RenderSetViewport(_renderer, &rect);
}
void oSDL::Renderer2D::SetViewport(oSDL::Vector2 pos, oSDL::Vector2 size)
{
	oSDL::Rect rect((int)pos.x, (int)pos.y, (int)size.x, (int)size.y);
	SDL_RenderSetViewport(_renderer, &rect);
}
void oSDL::Renderer2D::SetViewport(oSDL::Rect area)
{
	SDL_RenderSetViewport(_renderer,&area);
}

int oSDL::Renderer2D::SetTarget(SDL_Texture* texture)
{
	return SDL_SetRenderTarget(_renderer,texture);
}



/********************************************************
*	Start SetDrawColor Overloads
*********************************************************/
int oSDL::Renderer2D::SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	return SDL_SetRenderDrawColor(_renderer,r,g,b,a);
}
int oSDL::Renderer2D::SetDrawColor(unsigned int color)
{
	return SDL_SetRenderDrawColor(_renderer, oSDL::Color::GetRedFromHex(color), oSDL::Color::GetGreenFromHex(color), oSDL::Color::GetBlueFromHex(color), oSDL::Color::GetAlphaFromHex(color));
}
int oSDL::Renderer2D::SetDrawColor(const oSDL::Color& color)
{
	return SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
}
int oSDL::Renderer2D::SetDrawColor(const SDL_Color& color)
{
	return SDL_SetRenderDrawColor(_renderer, color.r, color.g, color.b, color.a);
}
int oSDL::Renderer2D::SetDrawBlendMode(SDL_BlendMode mode)
{
	return SDL_SetRenderDrawBlendMode(_renderer, mode);
}


oSDL::Color oSDL::Renderer2D::GetDrawColor()
{
	Uint8 r = 0, g = 0, b = 0, a = 255;
	SDL_GetRenderDrawColor(_renderer, &r, &g, &b, &a);
	return oSDL::Color(r,g,b,a);
}

SDL_BlendMode oSDL::Renderer2D::GetDrawBlendMode()
{
	SDL_BlendMode blend;
	SDL_GetRenderDrawBlendMode(_renderer, &blend);
	return blend;
}

SDL_Texture* oSDL::Renderer2D::GetTarget()
{
	return SDL_GetRenderTarget(_renderer);
}







/********************************************************
*	Additional rendering methods
*********************************************************/

/********************************************************
*	Begin FillRect overloads
*********************************************************/
int oSDL::Renderer2D::FillRect(const oSDL::Rect& rect)
{
	return SDL_RenderFillRect(_renderer, &rect);
}
int oSDL::Renderer2D::FillRect(int x, int y, int w, int h)
{
	oSDL::Rect rect(x,y,w,h);
	return SDL_RenderFillRect(_renderer, &rect);
}
int oSDL::Renderer2D::FillRects(const oSDL::Rect* rects, int count)
{
	return SDL_RenderFillRects(_renderer, rects, count);
}


/********************************************************
*	Begin DrawRect overloads
*********************************************************/
int oSDL::Renderer2D::DrawRect(const oSDL::Rect& rect)
{
	return SDL_RenderDrawRect(_renderer, &rect);
}
int oSDL::Renderer2D::DrawRect(int x, int y, int w, int h)
{
	oSDL::Rect rect(x, y, w, h);
	return SDL_RenderDrawRect(_renderer, &rect);
}
int oSDL::Renderer2D::DrawRects(const oSDL::Rect* rects, int count)
{
	return SDL_RenderDrawRects(_renderer, rects, count);
}

/********************************************************
*	Begin DrawLine overloads
*********************************************************/
int oSDL::Renderer2D::DrawLine(int x1, int y1, int x2, int y2)
{
	return SDL_RenderDrawLine(_renderer, x1, y1, x2, y2);
}
int oSDL::Renderer2D::DrawLine(const oSDL::Point& p1, const oSDL::Point& p2)
{
	return SDL_RenderDrawLine(_renderer, p1.x, p1.y, p2.x, p2.y);
}
int oSDL::Renderer2D::DrawLines(const oSDL::Point* points, int count)
{
	return SDL_RenderDrawLines(_renderer, points, count);
}

/********************************************************
*	Begin DrawPoint overloads
*********************************************************/
int oSDL::Renderer2D::DrawPoint(int x, int y)
{
	return SDL_RenderDrawPoint(_renderer, x, y);
}
int oSDL::Renderer2D::DrawPoint(const oSDL::Point& p)
{
	return SDL_RenderDrawPoint(_renderer, p.x, p.y);
}
int oSDL::Renderer2D::DrawPoints(const oSDL::Point* pts, int count)
{
	return SDL_RenderDrawPoints(_renderer,pts,count);
}


/********************************************************
*	Important rendering functionality
*********************************************************/
void oSDL::Renderer2D::Present()
{
	SDL_RenderPresent(_renderer);
}
int oSDL::Renderer2D::Clear()
{
	return SDL_RenderClear(_renderer);
}
void oSDL::Renderer2D::Destroy()
{
	SDL_DestroyRenderer(_renderer);
	_renderer	= NULL;
	_window		= NULL;
}


SDL_Renderer* oSDL::Renderer2D::BaseRenderer()
{
	return _renderer;
}