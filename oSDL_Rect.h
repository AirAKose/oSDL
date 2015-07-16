#ifndef _MY_oSDL_RECTANGLE_HEADER_
#define _MY_oSDL_RECTANGLE_HEADER_

#include <SDL_rect.h>
#include "oSDL_Vector2.h"

namespace oSDL
{
	class Rect: public SDL_Rect
	{
	public:
		Rect(int x, int y, int w, int h);
		Rect(oSDL::Vector2 pos, oSDL::Vector2 size);
		Rect(oSDL::Rect& copy);								// Copy _rect here
		~Rect();

		SDL_Rect GetSDLRect() const;

		oSDL::Vector2 SetPos(const oSDL::Vector2& pos);
		oSDL::Vector2 SetPos(int x,int y);
		oSDL::Vector2 GetPos() const;

		oSDL::Vector2 SetSize(const oSDL::Vector2& size);	// X is width, Y is height
		oSDL::Vector2 SetSize(int w, int h);
		oSDL::Vector2 GetSize() const;

		oSDL::Rect& Set(oSDL::Vector2& pos, oSDL::Vector2& size);
		oSDL::Rect& Set(int x,int y,int w,int h);



		float Length() const;													// Distance of the width and height from 0
		float LengthSquared() const;											// Distance of the width and height from 0

		oSDL::Rect operator+(const oSDL::Rect& other) const;			// Adds values 1-to-1. x+x, y+y, w+w, h+h
		oSDL::Rect operator-(const oSDL::Rect& other) const;			// Subtracts values 1-to-1. x-x, y-y, w-w, h-h

		oSDL::Rect operator*(float scale) const;						// Scales linearly all values.
		oSDL::Rect operator*(const oSDL::Vector2& scalar) const;		// Scales X and Width by the point's X, and Y and Height by the point's Y
		oSDL::Rect operator*(const oSDL::Rect& scalar) const;			// Scales values 1-to-1. x*x, y*y, w*w, h*h

		oSDL::Rect operator/(float scale) const;						// Scales linearly all values.
		oSDL::Rect operator/(const oSDL::Vector2& scalar) const;		// Scales X and Width by the point's X, and Y and Height by the point's Y
		oSDL::Rect operator/(const oSDL::Rect& scalar) const;			// Scales values 1-to-1. x/x, y/y, w/w, h/h

		int& operator[](int pos);										// Just in case someone wants to interface with this like an array. 0 is x, 1 is y, 2 is width, 3 is height. Anything else will loop through as if modulated

		void Destroy();													// Gets called internally by the destructor. No need to call.
	};
}

#endif