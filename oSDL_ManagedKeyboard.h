#include <SDL.h>

namespace oSDL
{
	class ManagedKeyboard
	{
		Uint8 *_states, *_lastStates;
	public:
		ManagedKeyboard();
		~ManagedKeyboard();

		Uint8 GetKeyState(SDL_Scancode key);
		bool GetKeyDown(SDL_Scancode key);
		bool GetKeyUp(SDL_Scancode key);
		bool GetKeyPressed(SDL_Scancode key);
		bool GetKeyReleased(SDL_Scancode key);
		bool GetKeyHeld(SDL_Scancode key);
	};

}
