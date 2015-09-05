#include "oSDL_Point.h"


oSDL::Point::Point(int x,int y)
{
	this->x = x;
	this->y = y;
}


oSDL::Point::~Point()
{
	this->x = this->y = 0;
}

oSDL::Point oSDL::Point::operator+(const oSDL::Point pt)const
{
	return oSDL::Point(x + pt.x, y + pt.y);
}
oSDL::Point oSDL::Point::operator-(const oSDL::Point pt)const
{
	return oSDL::Point(x - pt.x, y - pt.y);
}
oSDL::Point oSDL::Point::operator*(const oSDL::Point pt)const
{
	return oSDL::Point(x * pt.x, y * pt.y);
}
oSDL::Point oSDL::Point::operator*(float scale)const
{
	return oSDL::Point((int)(x *scale), (int)(y *scale));
}
oSDL::Point oSDL::Point::operator/(const oSDL::Point pt)const
{
	return oSDL::Point(x / pt.x, y / pt.y);
}
oSDL::Point oSDL::Point::operator/(float scale)const
{
	return oSDL::Point((int)(x / scale), (int)(y / scale));
}






oSDL::Point& oSDL::Point::operator+=(const oSDL::Point pt)
{
	this->x += pt.x;
	this->y += pt.y;
	return *this;
}
oSDL::Point& oSDL::Point::operator-=(const oSDL::Point pt)
{
	this->x -= pt.x;
	this->y -= pt.y;
	return *this;
}
oSDL::Point& oSDL::Point::operator*=(const oSDL::Point pt)
{
	this->x *= pt.x;
	this->y *= pt.y;
	return *this;
}
oSDL::Point& oSDL::Point::operator*=(float scale)
{
	this->x = (int)(this->x * scale);
	this->y = (int)(this->x * scale);
	return *this;
}
oSDL::Point& oSDL::Point::operator/=(const oSDL::Point pt)
{
	this->x /= pt.x;
	this->y /= pt.y;
	return *this;
}
oSDL::Point& oSDL::Point::operator/=(float scale)
{
	this->x = (int)(this->x / scale);
	this->y = (int)(this->x / scale);
	return *this;
}






oSDL::Point oSDL::Point::operator+(const oSDL::Vector2 pt)const
{
	return oSDL::Point((int)(x + pt.x), (int)(y + pt.y));
}
oSDL::Point oSDL::Point::operator-(const oSDL::Vector2 pt)const
{
	return oSDL::Point((int)(x - pt.x), (int)(y - pt.y));
}
oSDL::Point oSDL::Point::operator*(const oSDL::Vector2 pt)const
{
	return oSDL::Point((int)(x * pt.x), (int)(y * pt.y));
}
oSDL::Point oSDL::Point::operator/(const oSDL::Vector2 pt)const
{
	return oSDL::Point((int)(x / pt.x), (int)(y / pt.y));
}



oSDL::Point& oSDL::Point::operator+=(const oSDL::Vector2 pt)
{
	this->x = (int)(this->x+pt.x);
	this->y = (int)(this->y+pt.y);
	return *this;
}
oSDL::Point& oSDL::Point::operator-=(const oSDL::Vector2 pt)
{
	this->x = (int)(this->x-pt.x);
	this->y = (int)(this->y-pt.y);
	return *this;
}
oSDL::Point& oSDL::Point::operator*=(const oSDL::Vector2 pt)
{
	this->x = (int)(this->x*pt.x);
	this->y = (int)(this->y*pt.y);
	return *this;
}
oSDL::Point& oSDL::Point::operator/=(const oSDL::Vector2 pt)
{
	this->x = (int)(this->x/pt.x);
	this->y = (int)(this->y/pt.y);
	return *this;
}