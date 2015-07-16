#include "oSDL_Base.h"

int oSDL::Init(Uint32 flags)
{
	return SDL_Init(flags);
}
int oSDL::InitSubSystem(Uint32 flags)
{
	return SDL_InitSubSystem(flags);
}
void oSDL::QuitSubSystem(Uint32 flags)
{
	SDL_QuitSubSystem(flags);
}
void oSDL::Quit()
{
	SDL_Quit();
}
int oSDL::PollEvent(SDL_Event* evt)
{
	return SDL_PollEvent(evt);
}

const char* oSDL::GetError()
{
	return SDL_GetError();
}