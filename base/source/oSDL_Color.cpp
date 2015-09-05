#include <sstream>
#include "oSDL_Color.h"


oSDL::Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
oSDL::Color::Color(SDL_Color col)
{
	this->r = col.r;
	this->g = col.g;
	this->b = col.b;
	this->a = col.a;
}
oSDL::Color::Color(oSDL::Color& copy)
{
	this->r = copy.r;
	this->g = copy.g;
	this->b = copy.b;
	this->a = copy.a;
}
oSDL::Color::~Color()
{
	this->Destroy();
}

/***************************************************
*			Color accessors and Modifiers
***************************************************
Uint8 oSDL::Color::rconst
{
	return this->r;
}
Uint8 oSDL::Color::r =Uint8 r)
{
	return this->r = r;
}

Uint8 oSDL::Color::gconst
{
	return this->g;
}
Uint8 oSDL::Color::g =Uint8 g)
{
	return this->g = g;
}

Uint8 oSDL::Color::bconst
{
	return this->b;
}
Uint8 oSDL::Color::b =Uint8 b)
{
	return this->b = b;
}

Uint8 oSDL::Color::aconst
{
	return this->a;
}
Uint8 oSDL::Color::a =Uint8 a)
{
	return this->a = a;
}*/

void oSDL::Color::Set(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
void oSDL::Color::Set(Uint32 hexColor)
{
	this->r = GetRedFromHex(hexColor);
	this->g = GetGreenFromHex(hexColor);
	this->b = GetBlueFromHex(hexColor);
	this->a = GetAlphaFromHex(hexColor);
}
void oSDL::Color::Set(oSDL::Colors color)
{
	this->r = GetRedFromHex((Uint32)color);
	this->g = GetGreenFromHex((Uint32)color);
	this->b = GetBlueFromHex((Uint32)color);
	this->a = GetAlphaFromHex((Uint32)color);
}
void oSDL::Color::Set(const SDL_Color& color)
{
	this->r = color.r;
	this->g = color.g;
	this->b = color.b;
	this->a = color.a;
}
void oSDL::Color::Set(const oSDL::Color& color)
{
	this->r = color.r;
	this->g = color.g;
	this->b = color.b;
	this->a = color.a;
}





/****************************************************
*			Color Math Expressions
*****************************************************/
oSDL::Color oSDL::Color::Add(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	Uint16 rt = this->r + (Uint16)r;
	Uint16 gt = this->g + (Uint16)g;
	Uint16 bt = this->b + (Uint16)b;
	Uint16 at = this->a + (Uint16)a;
	oSDL::Color color((Uint8)(rt>255 ? 255 : rt), (Uint8)(gt>255 ? 255 : gt), (Uint8)(bt>255 ? 255 : bt), (Uint8)(at>255 ? 255 : at));
	return color;
}
oSDL::Color& oSDL::Color::AddTo(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	Uint16 rt = this->r + (Uint16)r;
	Uint16 gt = this->g + (Uint16)g;
	Uint16 bt = this->b + (Uint16)b;
	Uint16 at = this->a + (Uint16)a;

	this->r =	(Uint8)(rt > 255 ? 255 : rt);
	this->g =	(Uint8)(gt > 255 ? 255 : gt);
	this->b =	(Uint8)(bt > 255 ? 255 : bt);
	this->a =	(Uint8)(at > 255 ? 255 : at);
	return *this;
}
oSDL::Color oSDL::Color::Subtract(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	Sint16 rt = this->r	- (Sint16)r;
	Sint16 gt = this->g- (Sint16)g;
	Sint16 bt = this->b	- (Sint16)b;
	Sint16 at = this->a- (Sint16)a;
	oSDL::Color color((Uint8)(rt<0 ? 0 : rt), (Uint8)(gt<0 ? 0 : gt), (Uint8)(bt<0 ? 0 : bt), (Uint8)(at<0 ? 0 : at));
	return color;
}
oSDL::Color& oSDL::Color::SubtractFrom(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	Sint16 rt = this->r - (Sint16)r;
	Sint16 gt = this->g - (Sint16)g;
	Sint16 bt = this->b - (Sint16)b;
	Sint16 at = this->a - (Sint16)a;

	this->r =(Uint8)(rt < 0 ? 0 : rt);
	this->g =(Uint8)(gt < 0 ? 0 : gt);
	this->b =(Uint8)(bt < 0 ? 0 : bt);
	this->a =(Uint8)(at < 0 ? 0 : at);
	return *this;
}

oSDL::Color oSDL::Color::Multiply(float r, float g, float b, float a)
{
	float rt = this->r	* r;
	if (rt > 255) rt = 255;
	else if (rt < 0) rt = 0;

	float gt = this->g	* g;
	if (gt > 255) gt = 255;
	else if (gt < 0) gt = 0;

	float bt = this->b	* b;
	if (bt > 255) bt = 255;
	else if (bt < 0) bt = 0;

	float at = this->a	* a;
	if (at > 255) at = 255;
	else if (at < 0) at = 0;

	oSDL::Color color((Uint8)rt, (Uint8)gt, (Uint8)bt, (Uint8)at);
	return color;
}
oSDL::Color& oSDL::Color::MultiplyBy(float r, float g, float b, float a)
{
	float rt = this->r	* r;
	if (rt > 255) rt = 255;
	else if (rt < 0) rt = 0;

	float gt = this->g	* g;
	if (gt > 255) gt = 255;
	else if (gt < 0) gt = 0;

	float bt = this->b	* b;
	if (bt > 255) bt = 255;
	else if (bt < 0) bt = 0;

	float at = this->a	* a;
	if (at > 255) at = 255;
	else if (at < 0) at = 0;

	this->r =(Uint8)rt;
	this->g =(Uint8)gt;
	this->b =(Uint8)bt;
	this->a =(Uint8)at;

	return *this;
}
oSDL::Color oSDL::Color::Divide(float r, float g, float b, float a)
{
	float rt = this->r	/ r;
	if (rt > 255) rt = 255;
	else if (rt < 0) rt = 0;

	float gt = this->g	/ g;
	if (gt > 255) gt = 255;
	else if (gt < 0) gt = 0;

	float bt = this->b	/ b;
	if (bt > 255) bt = 255;
	else if (bt < 0) bt = 0;

	float at = this->a	/ a;
	if (at > 255) at = 255;
	else if (at < 0) at = 0;

	oSDL::Color color((Uint8)rt, (Uint8)gt, (Uint8)bt, (Uint8)at);
	return color;
}
oSDL::Color& oSDL::Color::DivideBy(float r, float g, float b, float a)
{
	float rt = this->r	/ r;
	if (rt > 255) rt = 255;
	else if (rt < 0) rt = 0;

	float gt = this->g / g;
	if (gt > 255) gt = 255;
	else if (gt < 0) gt = 0;

	float bt = this->b	/ b;
	if (bt > 255) bt = 255;
	else if (bt < 0) bt = 0;

	float at = this->a	/ a;
	if (at > 255) at = 255;
	else if (at < 0) at = 0;

	this->r =(Uint8)rt;
	this->g =(Uint8)gt;
	this->b =(Uint8)bt;
	this->a =(Uint8)at;

	return *this;
}






/***************************************************
*			Color Conversion Methods
****************************************************/
std::string oSDL::Color::ToString()
{
	std::stringstream stream;
	stream << "(" << this->r << "," << this->g << "," << this->b << "," << this->a << ")";
	return stream.str();
}
/*std::string oSDL::Color::ToHexString()
{
	// TODO
}*/
unsigned int oSDL::Color::ToHexNumber()
{
	return (r << 6) | (g << 4) | (b << 2) | a;
}







/****************************************************
*			Color Operator Overloads
*****************************************************/
oSDL::Color& oSDL::Color::operator=(unsigned int hex)
{
	this->r =GetRedFromHex(hex);
	this->g =GetGreenFromHex(hex);
	this->b =GetBlueFromHex(hex);
	this->a =GetAlphaFromHex(hex);

	return *this;
}
oSDL::Color& oSDL::Color::operator=(oSDL::Colors color)
{
	this->r =GetRedFromHex((Uint32)color);
	this->g =GetGreenFromHex((Uint32)color);
	this->b =GetBlueFromHex((Uint32)color);
	this->a =GetAlphaFromHex((Uint32)color);
	return *this;
}

oSDL::Color oSDL::Color::operator+(oSDL::Color& other)
{
	return this->Add(other.r,other.g,other.b,other.a);
}
oSDL::Color& oSDL::Color::operator+=(oSDL::Color& other)
{
	return this->AddTo(other.r, other.g, other.b, other.a);
}
oSDL::Color oSDL::Color::operator+(unsigned int hex)
{
	return this->Add(GetRedFromHex(hex), GetGreenFromHex(hex), GetBlueFromHex(hex), GetAlphaFromHex(hex));
}
oSDL::Color& oSDL::Color::operator+=(unsigned int hex)
{
	return this->AddTo(GetRedFromHex(hex), GetGreenFromHex(hex), GetBlueFromHex(hex), GetAlphaFromHex(hex));
}

oSDL::Color oSDL::Color::operator-(oSDL::Color& other)
{
	return this->Subtract(other.r, other.g, other.b, other.a);
}
oSDL::Color& oSDL::Color::operator-=(oSDL::Color& other)
{
	return this->SubtractFrom(other.r, other.g, other.b, other.a);
}
oSDL::Color oSDL::Color::operator-(unsigned int hex)
{
	return this->Subtract(GetRedFromHex(hex), GetGreenFromHex(hex), GetBlueFromHex(hex), GetAlphaFromHex(hex));
}
oSDL::Color& oSDL::Color::operator-=(unsigned int hex)
{
	return this->SubtractFrom(GetRedFromHex(hex), GetGreenFromHex(hex), GetBlueFromHex(hex), GetAlphaFromHex(hex));
}

oSDL::Color oSDL::Color::operator*(oSDL::Color& other)
{
	return this->Multiply(other.r, other.g, other.b, other.a);
}
oSDL::Color& oSDL::Color::operator*=(oSDL::Color& other)
{
	return this->MultiplyBy(other.r, other.g, other.b, other.a);
}
oSDL::Color oSDL::Color::operator*(float scale)
{
	return this->Multiply(scale,scale,scale,scale);
}
oSDL::Color& oSDL::Color::operator*=(float scale)
{
	return this->MultiplyBy(scale, scale, scale, scale);
}

oSDL::Color oSDL::Color::operator/(oSDL::Color& other)
{
	return this->Divide(other.r, other.g, other.b, other.a);
}
oSDL::Color& oSDL::Color::operator/=(oSDL::Color& other)
{
	return this->DivideBy(other.r, other.g, other.b, other.a);
}
oSDL::Color oSDL::Color::operator/(float scale)
{
	return this->Divide(scale, scale, scale, scale);
}
oSDL::Color& oSDL::Color::operator/=(float scale)
{
	return this->DivideBy(scale, scale, scale, scale);
}

Uint8& oSDL::Color::operator[](Uint8 index)
{
	index = index % 4;
	switch (index)
	{
	case 0:
		return this->r;
	case 1:
		return this->g;
	case 2:
		return this->b;
	}
	return this->a;
}





/*std::istream& oSDL::Color::operator>>(std::istream& str)
{
	// TODO
	return str;
}*/

std::ostream& oSDL::Color::operator<<(std::ostream& str)
{
	str << this->ToString();
	return str;
}


Uint8 oSDL::Color::GetRedFromHex(Uint32 color)
{
	return (color & 0xFF000000)>>24;
}
Uint8 oSDL::Color::GetGreenFromHex(Uint32 color)
{
	return (color & 0x00FF0000)>>16;
}
Uint8 oSDL::Color::GetBlueFromHex(Uint32 color)
{
	return (color & 0x0000FF00)>>8;
}
Uint8 oSDL::Color::GetAlphaFromHex(Uint32 color)
{
	return color & 0x000000FF;
}









/************************************************
 *	Begin Internal hex conversion functions
*************************************************/
Uint8 GetHexCharValue(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (c - 'A' + 10);
}

Uint32 GetHexStringValueAt(std::string val, int pos, int stride=2)
{
	Uint32 num = 0;
	Uint32 coef = 1;

	// Start at the furthest-right number
	for (int i = pos + stride - 1; i >= pos; --i)
	{
		num += GetHexCharValue(val[i])*coef;
		coef *= 16;
	}
	
	return num;
}

Uint8 GetHexRGBAValue(std::string hex,int pos)
{
	// For strings formatted as #RRGGBBAA or #RGBA
	if (hex[0] == '#')
		hex = hex.substr(1);
	// For strings formatted as 0xRRGGBBAA or 0xRGBA
	else if (hex[1] == 'x' && hex[0] == '0')
		hex = hex.substr(2);

	if (hex.length() > 4)
	{
		// The provided string is RRGGBB and we want alpha. Default to 255
		if (pos == 3 && hex.length() == 6)
			return 255;
		// The provided string is RRGGBBAA or we don't want alpha.
		return GetHexCharValue(hex[pos*2]) * 16 + GetHexCharValue(hex[pos*2+1]);
	}
	// The provided string is RGB and we want alpha. Default to 255
	if (pos == 3 && hex.length() == 3)
		return 255;
	// The provided string is RGBA or we don't want alpha
	return GetHexCharValue(hex[pos]) * 16 + GetHexCharValue(hex[pos]);
}













Uint8 oSDL::Color::GetRedFromHex(std::string hex)
{
	return GetHexRGBAValue(hex,0);
}
Uint8 oSDL::Color::GetGreenFromHex(std::string hex)
{
	return GetHexRGBAValue(hex, 1);
}
Uint8 oSDL::Color::GetBlueFromHex(std::string hex)
{
	return GetHexRGBAValue(hex, 2);
}
Uint8 oSDL::Color::GetAlphaFromHex(std::string hex)
{
	return GetHexRGBAValue(hex, 3);
}



void oSDL::Color::Destroy()
{
	r = g = b = a = 0;
}