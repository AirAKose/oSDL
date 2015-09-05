#ifndef _oSDL_BASE_HEADER_
#define _oSDL_BASE_HEADER_

#include <SDL.h>

namespace oSDL
{
	int Init(Uint32 flags);
	int InitSubSystem(Uint32 flags);
	void QuitSubSystem(Uint32 flags);
	void Quit();

	int PollEvent(SDL_Event* evt);

	const char* GetError();
};

#endif