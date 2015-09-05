#include "oSDL_Vector2.h"


oSDL::Vector2::Vector2(float x,float y)
{
	this->x = x;
	this->y = y;
}

oSDL::Vector2::Vector2(const oSDL::Vector2& copy)
{
	x = copy.x;
	y = copy.y;
}
oSDL::Vector2::~Vector2()
{
	this->Destroy();
}

SDL_Point oSDL::Vector2::GetPoint()
{
	SDL_Point pt;
	pt.x = (int)x;
	pt.y = (int)y;
	return pt;
}

oSDL::Vector2& oSDL::Vector2::Set(float x, float y)
{
	this->x = x;
	this->y = y;
	return *this;
}
float oSDL::Vector2::Scalar(oSDL::Vector2& other) const
{
	return x * other.x + y * other.y;
}
float oSDL::Vector2::Dot(oSDL::Vector2& other) const
{
	return this->Scalar(other) / (this->Length() + other.Length() );
}
float oSDL::Vector2::Distance(oSDL::Vector2 &other) const
{
	return (other - (*this)).Length();
}
float oSDL::Vector2::DistanceSquared(oSDL::Vector2 &other) const
{
	return (other - (*this)).LengthSquared();
}
float oSDL::Vector2::Length() const
{
	return (float)SDL_sqrt(x*x + y*y);
}
float oSDL::Vector2::LengthSquared() const
{
	return x*x + y*y;
}

oSDL::Vector2 oSDL::Vector2::operator+(const oSDL::Vector2& other) const
{
	return oSDL::Vector2(x+other.x, y+other.y);
}
oSDL::Vector2& oSDL::Vector2::operator+=(const oSDL::Vector2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}
oSDL::Vector2 oSDL::Vector2::operator-(const oSDL::Vector2& other) const
{
	return oSDL::Vector2(x - other.x, y - other.y);
}
oSDL::Vector2& oSDL::Vector2::operator-=(const oSDL::Vector2& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

oSDL::Vector2 oSDL::Vector2::operator*(const oSDL::Vector2& other) const
{
	return oSDL::Vector2(x * other.x, y * other.y);
}
oSDL::Vector2& oSDL::Vector2::operator*=(const oSDL::Vector2& other)
{
	x *= other.x;
	y *= other.y;
	return *this;
}
oSDL::Vector2 oSDL::Vector2::operator*(float scale) const
{
	return oSDL::Vector2(x * scale, y * scale);
}
oSDL::Vector2& oSDL::Vector2::operator*=(float scale)
{
	x *= scale;
	y *= scale;
	return *this;
}

oSDL::Vector2 oSDL::Vector2::operator/(const oSDL::Vector2& other) const
{
	return oSDL::Vector2(x / other.x, y / other.y);
}
oSDL::Vector2& oSDL::Vector2::operator/=(const oSDL::Vector2& other)
{
	x /= other.x;
	y /= other.y;
	return *this;
}
oSDL::Vector2 oSDL::Vector2::operator/(float scale) const
{
	return oSDL::Vector2(x / scale, y / scale);
}
oSDL::Vector2& oSDL::Vector2::operator/=(float scale)
{
	x /= scale;
	y /= scale;
	return *this;
}

float& oSDL::Vector2::operator[](Uint8 pos)
{
	pos %= 2;
	if (pos == 0)
		return x;
	return y;
}

void oSDL::Vector2::Destroy()
{
	x = 0; y = 0;
}