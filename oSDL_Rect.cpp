#include "oSDL_Rect.h"

oSDL::Rect::Rect(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}
oSDL::Rect::Rect(oSDL::Vector2 pos, oSDL::Vector2 size)
{
	this->x = (int)pos.x;
	this->y = (int)pos.y;
	this->w = (int)size.x;
	this->h = (int)size.y;
}
oSDL::Rect::Rect(oSDL::Rect& copy)
{
	this->x = copy.x;
	this->y = copy.y;
	this->w = copy.w;
	this->h = copy.h;
}
oSDL::Rect::~Rect()
{
	this->Destroy();
}

SDL_Rect oSDL::Rect::GetSDLRect() const
{
	SDL_Rect r;
	r.x = this->x;
	r.y = this->y;
	r.w = this->w;
	r.h = this->h;
	return r;
}

oSDL::Vector2 oSDL::Rect::SetPos(const oSDL::Vector2& pos)
{
	x = (int)pos.x;
	y = (int)pos.y;
	return pos;
}
oSDL::Vector2 oSDL::Rect::SetPos(int x, int y)
{
	return oSDL::Vector2((float)(this->x = x), (float)(this->y = y));
}
oSDL::Vector2 oSDL::Rect::GetPos() const
{
	return oSDL::Vector2((float)x, (float)y);
}

oSDL::Vector2 oSDL::Rect::SetSize(const oSDL::Vector2& size)
{
	this->w = (int)size.x;
	this->h = (int)size.y;
	return size;
}
oSDL::Vector2 oSDL::Rect::SetSize(int w, int h)
{
	return oSDL::Vector2((float)(this->w = w), (float)(this->h = h));
}
oSDL::Vector2 oSDL::Rect::GetSize() const
{
	return oSDL::Vector2((float)w, (float)h);
}

oSDL::Rect& oSDL::Rect::Set(oSDL::Vector2& pos, oSDL::Vector2& size)
{
	this->x = (int)pos.x; this->y = y = (int)pos.y;
	this->w = (int)size.x; this->h = (int)size.y;
	return *this;
}
oSDL::Rect& oSDL::Rect::Set(int x, int y, int w, int h)
{
	this->x = x; this->y = y;
	this->w = w; this->h = h;
	return *this;
}



float oSDL::Rect::Length() const
{
	return (float)SDL_sqrt(w*w + h*h);
}
float oSDL::Rect::LengthSquared() const
{
	return (float)(w*w + h*h);
}

oSDL::Rect oSDL::Rect::operator+(const oSDL::Rect& other) const
{
	return oSDL::Rect(this->x+other.x,this->y+other.y,this->w+other.w,this->h+other.h);
}
oSDL::Rect oSDL::Rect::operator-(const oSDL::Rect& other) const
{
	return oSDL::Rect(this->x - other.x, this->y - other.y, this->w - other.w, this->h - other.h);
}

oSDL::Rect oSDL::Rect::operator*(float scale) const
{
	return oSDL::Rect((int)(this->x * scale), (int)(this->y * scale), (int)(this->w * scale), (int)(this->h * scale));
}
oSDL::Rect oSDL::Rect::operator*(const oSDL::Vector2& scalar) const
{
	return oSDL::Rect((int)(this->x * scalar.x), (int)(this->y * scalar.y), (int)(this->w * scalar.x), (int)(this->h * scalar.y));
}
oSDL::Rect oSDL::Rect::operator*(const oSDL::Rect& scalar) const
{
	return oSDL::Rect(this->x * scalar.x, this->y * scalar.y, this->w * scalar.w, this->h * scalar.h);
}

oSDL::Rect oSDL::Rect::operator/(float scale) const
{
	return oSDL::Rect((int)(this->x / scale), (int)(this->y / scale), (int)(this->w / scale), (int)(this->h / scale));
}
oSDL::Rect oSDL::Rect::operator/(const oSDL::Vector2& scalar) const
{
	return oSDL::Rect((int)(this->x / scalar.x), (int)(this->y / scalar.y), (int)(this->w / scalar.x), (int)(this->h / scalar.y));
}
oSDL::Rect oSDL::Rect::operator/(const oSDL::Rect& scalar) const
{
	return oSDL::Rect(this->x / scalar.x, this->y / scalar.y, this->w / scalar.w, this->h / scalar.h);
}

int& oSDL::Rect::operator[](int pos)
{
	pos %= 4;
	switch (pos)
	{
	case 0:
		return this->x;
	case 1:
		return this->y;
	case 2:
		return this->w;
	}
	return this->h;
}

void oSDL::Rect::Destroy()
{
	x = y = w = h = 0;
}