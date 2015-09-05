#ifndef _oSDL_RENDERER_2D_HEAD_
#define _oSDL_RENDERER_2D_HEAD_

#include <SDL.h>

namespace oSDL
{
	class Vector2;
	class Point;
	class Color;
	class Rect;
	class Window;

	class Renderer2D
	{
		SDL_Renderer* _renderer;
		SDL_Window* _window;
	public:
		Renderer2D(oSDL::Window* window, SDL_RendererFlags flags = (SDL_RendererFlags)0);
		Renderer2D(oSDL::Renderer2D& copy);
		~Renderer2D();

		void SetViewport(int x, int y, int w, int h);
		void SetViewport(oSDL::Vector2 pos, oSDL::Vector2 size);
		void SetViewport(oSDL::Rect area);

		int SetTarget(SDL_Texture* texture);

		int SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255); // Red, Green, Blue, Alpha
		int SetDrawColor(Uint32 color); // Hex color
		int SetDrawColor(const oSDL::Color& color);
		int SetDrawColor(const SDL_Color& color); // SDL Color inclusion for advanced users

		int SetDrawBlendMode(SDL_BlendMode mode);

		oSDL::Color GetDrawColor();
		SDL_BlendMode GetDrawBlendMode();

		SDL_Texture* GetTarget();


		int FillRect(const oSDL::Rect& rect);
		int FillRect(int x, int y, int w, int h);
		int FillRects(const oSDL::Rect* rects, int count);

		int DrawRect(const oSDL::Rect& rect);
		int DrawRect(int x, int y, int w, int h);
		int DrawRects(const oSDL::Rect* rects, int count);

		int DrawLine(int x1, int y1, int x2, int y2);
		int DrawLine(const oSDL::Point& p1, const oSDL::Point& p2);
		int DrawLines(const oSDL::Point* points, int count);

		int DrawPoint(int x, int y);
		int DrawPoint(const oSDL::Point& p);
		int DrawPoints(const oSDL::Point* p, int count);

		void Present();
		int Clear();
		void Destroy();

		SDL_Renderer* BaseRenderer();
	};
}

#endif