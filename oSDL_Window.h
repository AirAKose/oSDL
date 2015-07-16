#ifndef _MY_oSDL_WINDOW_CLASS_
#define _MY_oSDL_WINDOW_CLASS_

#include <SDL.h>
#include <string>
#include "oSDL_Vector2.h"


namespace oSDL
{
	class Window
	{
	private:
		SDL_Window* _window = NULL;

	public:
		Window();
		Window(const char* windowTitle, int posX, int posY, int sizeW, int sizeH, Uint32 flags = 0);
		Window(oSDL::Window& copy);
		~Window();

		bool Create(const char* windowTitle, int posX, int posY, int sizeW, int sizeH, Uint32 flags = 0);
		void Destroy();

		virtual bool OnCreate();
		virtual bool OnVisibilityChange(bool vis);
		virtual bool OnResize();
		virtual bool OnMove();
		virtual bool OnDestroy();

		Uint32 GetFlags();
		std::string GetError();

		void SetTitle(std::string title);		// Sets the window title. Returns false on failure
		void SetPosition(int x, int y);			// Sets the window position. Returns false on failure
		void SetSize(int w, int h);				// Sets the window size. Returns false on failure
		void SetFullscreen(bool val);			// Sets whether or not this window is in fullscreen. Returns the state it's in.

		std::string GetTitle(void);
		void GetTitle(std::string* str);
		oSDL::Vector2 GetPosition(void);
		void GetPosition(int* x,int* y);
		oSDL::Vector2 GetSize(void);
		void GetSize(int* w, int* h);
		Uint32 GetID();
		bool IsFullscreen(void);

		
		bool IsVisible();
		bool ToggleVisibility();				// Swaps between enabling and disabling the Draw function / loop. Update will continue regardless. Also swaps flags between SDL_WINDOW_HIDDEN and SDL_WINDOW_SHOWN
		bool Show();							// Enables the Draw function / loop. Also sets flag SDL_WINDOW_SHOWN
		bool Hide();							// Disabled the Draw function / loop. Will continue to Update. Also sets flag SDL_WINDOW_HIDDEN
		bool Close();							// Destroy the window and its content. Will no longer Update or Draw. Must call Create before continuing to use this object.

		SDL_Window* BaseWindow();
	};

	bool WindowExists(Uint32 id);
	oSDL::Window* GetWindowByID(Uint32 id);
	oSDL::Window* GetWindowByTitle(std::string title);
	oSDL::Window* GetWindowByBaseWindow(SDL_Window* wind);
}


#endif
