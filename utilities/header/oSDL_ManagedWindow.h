#ifndef _oSDL_MANAGED_WINDOW_HEADER_
#define _oSDL_MANAGED_WINDOW_HEADER_


#include "oSDL_Window.h"
#include "oSDL_MouseState.h"

namespace oSDL
{
	class ManagedWindow : public oSDL::Window
	{
	private:
		oSDL::MouseState* _mouse;
	public:
		ManagedWindow();
		~ManagedWindow();

		oSDL::MouseState* GetMouseState();
		//oSDL::KeyboardState* GetKeyboardState();
	};
}

#endif