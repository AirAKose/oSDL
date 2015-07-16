#include "oSDL_Window.h"
#include <map>

std::map<Uint32, oSDL::Window*> windows;


oSDL::Window::Window()
{
}

oSDL::Window::Window(const char* windowTitle, int posX, int posY, int sizeW, int sizeH, Uint32 flags)
{
	Create(windowTitle,posX,posY,sizeW,sizeH,flags);
	windows[GetID()] = this;
	printf("Window created! ID: %d\nWindows in existance:%d\n",GetID(),windows.size());
}
oSDL::Window::Window(oSDL::Window& copy)
{
	
}
oSDL::Window::~Window()
{
	Uint32 id = GetID();
	if (windows.find(id) != windows.end()) // If we weren't somehow magically removed from the map
		windows.erase(id);
}

bool oSDL::Window::Create(const char* windowTitle, int posX, int posY, int sizeW, int sizeH, Uint32 flags )
{
	_window = SDL_CreateWindow(windowTitle,posX,posY,sizeW,sizeH,flags);
	OnCreate();
	return _window == 0;
}
void oSDL::Window::Destroy()
{
	OnDestroy();
	SDL_DestroyWindow(_window);
	_window = NULL;
}


bool oSDL::Window::OnCreate()
{
	return true;
}
bool oSDL::Window::OnVisibilityChange(bool val)
{
	return true;
}
bool oSDL::Window::OnDestroy()
{
	return true;
}
bool oSDL::Window::OnResize()
{
	return true;
}
bool oSDL::Window::OnMove()
{
	return true;
}


Uint32 oSDL::Window::GetFlags()
{
	return SDL_GetWindowFlags(_window);
}
std::string oSDL::Window::GetError()
{
	return SDL_GetError();
}

void oSDL::Window::SetTitle(std::string title)
{
	SDL_SetWindowTitle(_window,title.c_str());
}
void oSDL::Window::SetPosition(int x, int y)
{
	SDL_SetWindowPosition(_window,x,y);
}
void oSDL::Window::SetSize(int w, int h)
{
	SDL_SetWindowSize(_window,w,h);
}
void oSDL::Window::SetFullscreen(bool val)
{
	SDL_SetWindowFullscreen(_window,val ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

std::string oSDL::Window::GetTitle(void)
{
	return SDL_GetWindowTitle(_window);
}
void oSDL::Window::GetTitle(std::string* str)
{
	str = &((std::string)SDL_GetWindowTitle(_window));
}
oSDL::Vector2 oSDL::Window::GetPosition(void)
{
	int x = 0; int y = 0;
	SDL_GetWindowPosition(_window,&x,&y);
	return oSDL::Vector2((float)x,(float)y);
}
void oSDL::Window::GetPosition(int* x, int* y)
{
	SDL_GetWindowPosition(_window,x,y);
}
oSDL::Vector2 oSDL::Window::GetSize(void)
{
	int w = 0; int h = 0;
	SDL_GetWindowSize(_window,&w,&h);
	return oSDL::Vector2((float)w,(float)h);
}
void oSDL::Window::GetSize(int* w, int* h)
{
	SDL_GetWindowSize(_window, w, h);
}
Uint32 oSDL::Window::GetID()
{
	return SDL_GetWindowID(_window);
}
bool oSDL::Window::IsFullscreen(void)
{
	Uint32 flags = GetFlags();
	return (flags & (SDL_WINDOW_FULLSCREEN | SDL_WINDOW_FULLSCREEN_DESKTOP)) > 0;
}


bool oSDL::Window::IsVisible()
{
	Uint32 flags = GetFlags();
	return (flags & SDL_WINDOW_SHOWN) == SDL_WINDOW_SHOWN;
}
bool oSDL::Window::ToggleVisibility()
{
	if (IsVisible())
		return Hide();
	return Show();
}
bool oSDL::Window::Show()
{
	SDL_ShowWindow(_window);
	return true;
}
bool oSDL::Window::Hide()
{
	SDL_HideWindow(_window);
	return false;
}
bool oSDL::Window::Close()
{
	SDL_DestroyWindow(_window);
	if (SDL_GetError())
	_window = NULL;
	return true;
}


SDL_Window* oSDL::Window::BaseWindow()
{
	return _window;
}



bool oSDL::WindowExists(Uint32 id)
{
	return windows.find(id) != windows.end();
}
oSDL::Window* oSDL::GetWindowByID(Uint32 id)
{
	if (windows.find(id) != windows.end())	// If the provided key exists, return its value
		return windows.at(id);
	return NULL;
}
oSDL::Window* oSDL::GetWindowByTitle(std::string title)
{
	for (std::map<Uint32, oSDL::Window*>::iterator iter = windows.begin(); iter != windows.end(); iter++)
	{
		if (iter->second->GetTitle() == title)
			return iter->second;
	}
	return NULL;
}
oSDL::Window* oSDL::GetWindowByBaseWindow(SDL_Window* wind)
{
	Uint32 id = SDL_GetWindowID(wind);
	if (windows.find(id) != windows.end())
		return windows[id];
	return NULL;
}