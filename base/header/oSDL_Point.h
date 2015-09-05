#ifndef _MY_oSDL_POINT_HEADER_
#define _MY_oSDL_POINT_HEADER_

#include <SDL.h>
#include "oSDL_Vector2.h"

namespace oSDL
{
	class Point: public SDL_Point
	{
	public:
		Point(int x,int y);
		~Point();

		oSDL::Point operator+(const oSDL::Point pt)const;
		oSDL::Point operator-(const oSDL::Point pt)const;
		oSDL::Point operator*(const oSDL::Point pt)const;
		oSDL::Point operator*(float scale)const;
		oSDL::Point operator/(const oSDL::Point pt)const;
		oSDL::Point operator/(float scale)const;

		oSDL::Point& operator+=(const oSDL::Point pt);
		oSDL::Point& operator-=(const oSDL::Point pt);
		oSDL::Point& operator*=(const oSDL::Point pt);
		oSDL::Point& operator*=(float scale);
		oSDL::Point& operator/=(const oSDL::Point pt);
		oSDL::Point& operator/=(float scale);



		oSDL::Point operator+(const oSDL::Vector2 pt)const;
		oSDL::Point operator-(const oSDL::Vector2 pt)const;
		oSDL::Point operator*(const oSDL::Vector2 pt)const;
		oSDL::Point operator/(const oSDL::Vector2 pt)const;

		oSDL::Point& operator+=(const oSDL::Vector2 pt);
		oSDL::Point& operator-=(const oSDL::Vector2 pt);
		oSDL::Point& operator*=(const oSDL::Vector2 pt);
		oSDL::Point& operator/=(const oSDL::Vector2 pt);
	};
}

#endif