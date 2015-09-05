#ifndef _oSDL_MOUSE_STATE_HEADER_
#define _oSDL_MOUSE_STATE_HEADER_

namespace oSDL
{
	class ManagedWindow;
	class Point;
	int UpdateManagedInputStates(oSDL::ManagedWindow* wind);

	enum MouseButtons
	{
		MOUSEBUTTON_LEFT, MOUSEBUTTON_RIGHT, MOUSEBUTTON_MIDDLE
	};

	class MouseState
	{
	private:
		oSDL::Point *_pos, *_deltaPos;
		int *_buttonStates, *_lastButtonStates;
		int _wheel, _lastWheel;


	public:

		MouseState();
		~MouseState();

		const oSDL::Point* GetPos();
		const oSDL::Point* GetDeltaPos();

		int GetButtonState(int button);
		bool GetButtonDown(int button);
		bool GetButtonUp(int button);
		bool GetButtonPressed(int button);
		bool GetButtonReleased(int button);

		int GetWheel();
		int GetWheelDelta();

		friend int UpdateManagedInputStates(oSDL::ManagedWindow* wind);
	};
}

#endif