#ifndef _MY_oSDL_VECTOR2_HEADER_
#define _MY_oSDL_VECTOR2_HEADER_

#include <SDL.h>

namespace oSDL
{
	class Vector2
	{
	public:
		float x = 0, y = 0;

		Vector2(float x=0,float y=0);
		Vector2(const oSDL::Vector2& copy);						// Copy x and y here
		~Vector2();

		SDL_Point GetPoint();						// Get the base SDL_Point object. For Advanced Usage

		oSDL::Vector2& Set(float x, float y);
		float Scalar(oSDL::Vector2& other) const;			// Like the dot product, but not normalized
		float Dot(oSDL::Vector2& other) const;			// Value from 1 to -1 that tells how similar the points are (as vectors)
		float Distance(oSDL::Vector2 &other) const;		
		float DistanceSquared(oSDL::Vector2 &other) const;
		float Length() const;									// Distance from 0
		float LengthSquared() const;							// Distance from 0 squared. Less processing, as it doesn't call sqrt

		oSDL::Vector2 operator+(const oSDL::Vector2& other) const;
		oSDL::Vector2& operator+=(const oSDL::Vector2& other);
		oSDL::Vector2 operator-(const oSDL::Vector2& other) const;
		oSDL::Vector2& operator-=(const oSDL::Vector2& other);

		oSDL::Vector2 operator*(const oSDL::Vector2& other) const;		// Cross-product
		oSDL::Vector2& operator*=(const oSDL::Vector2& other);	// Cross-product and Assignment
		oSDL::Vector2 operator*(float scale) const;				// Scalar
		oSDL::Vector2& operator*=(float scale);			// Scalar and Assignment

		oSDL::Vector2 operator/(const oSDL::Vector2& other) const;		// Not real division, just x/x and y/y
		oSDL::Vector2& operator/=(const oSDL::Vector2& other);	// Not real division, just x/x and y/y and Assignment
		oSDL::Vector2 operator/(float scale) const;				// Scalar
		oSDL::Vector2& operator/=(float scale);			// Scalar and Assignment

		float& operator[](Uint8 pos);			// Just in case someone wants to interface with this like an array. 0 is x, 1 is y, anything else will always return 0

		void Destroy();									// Gets called internally by the destructor. No need to call
	};
}
#endif