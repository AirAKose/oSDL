#include "oSDL_ManagedInput.h"
#include "oSDL_ManagedWindow.h"
#include "oSDL_MouseState.h"
#include "oSDL_Point.h"

int oSDL::UpdateManagedInputStates(oSDL::ManagedWindow* wind)
{
	int keyLength			= 0;
	const Uint8* keyStates	= SDL_GetKeyboardState(&keyLength);
	oSDL::MouseState* mouse = wind->GetMouseState();

	SDL_GetMouseState(&(mouse->_pos->x), &(mouse->_pos->y));
	//mouse->_buttonStates[0] = keyStates[SDL_SCANCODE];

}