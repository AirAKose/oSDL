#ifndef _OSDL_COLOR_HEADER_
#define _OSDL_COLOR_HEADER_

#include <SDL.h>
#include <string>
#include <stdio.h>

namespace oSDL
{
	// Color enumerations stored by hex values
	enum Colors
	{
		COLOR_BLACK		= 0x000000FF,	COLOR_WHITE			= 0xFFFFFFFF,
		COLOR_GREY		= 0x7F7F7FFF,	COLOR_LIGHTGREY		= 0xBFBFBFFF,	COLOR_DARKGREY		= 0X404040FF,
		COLOR_RED		= 0x990000FF,	COLOR_DARKRED		= 0x3F0000FF,	COLOR_BRIGHTRED		= 0xFF0000FF,
		COLOR_GREEN		= 0x009900FF,	COLOR_DARKGREEN		= 0x003F00FF,	COLOR_BRIGHTGREEN	= 0x00FF00FF,
		COLOR_BLUE		= 0x000099FF,	COLOR_DARKBLUE		= 0x00003FFF,	COLOR_BRIGHTBLUE	= 0x0000FFFF,
		COLOR_YELLOW	= 0xFFFF00FF,	COLOR_ORANGE,						COLOR_BROWN,
		COLOR_GOLD,						COLOR_LIMEGREEN,					COLOR_EARTHBROWN,
		COLOR_PINK,						COLOR_VIOLET,						COLOR_AQUA,
		COLOR_HOTPINK,					COLOR_TURQUOISE,					COLOR_SALMON,
		COLOR_STEELBLUE,				COLOR_SKYBLUE,						COLOR_NAVYBLUE,
		COLOR_TRANSPARENT=0x00000000
	};

	class Color: public SDL_Color
	{
	//private:
	//	SDL_Color* _color;
	public:
		Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
		Color(SDL_Color col);
		Color(oSDL::Color& copy); // Copy _color here
		~Color();

		void Set(Uint8 r, Uint8 g, Uint8 b, Uint8 a=255);
		void Set(Uint32 hexColor);
		void Set(oSDL::Colors color);
		void Set(const SDL_Color& color);
		void Set(const oSDL::Color& color);
		oSDL::Color Add(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 0);			// Returns a new color with the added values of this and the supplied RGBA
		oSDL::Color& AddTo(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 0);			// Adds the supplied RGBA to this color object
		oSDL::Color Subtract(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 0);		// Returns a new color with the subtracted values of this and the supplied RGBA
		oSDL::Color& SubtractFrom(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 0);	// Subtractss the supplied RGBA from this color object

		oSDL::Color Multiply(float r,float g,float b,float a = 1);		// Returns a new color with the multiplied values of this and the supplied RGBA
		oSDL::Color& MultiplyBy(float r, float g, float b, float a = 1);	// Multiplies this color object by the supplied RGBA
		oSDL::Color Divide(float r, float g, float b, float a = 1);			// Returns a new color with the divided values of this and the supplied RGBA
		oSDL::Color& DivideBy(float r, float g, float b, float a = 1);		// Divides this color object by the supplied RGBA

		std::string ToString();									// Outputs "(R,G,B,A)"
		//std::string ToHexString();								// Outputs "RRGGBBAA"
		unsigned int ToHexNumber();								// Outputs equivalent to 0xRRGGBBAA



		oSDL::Color& operator=(unsigned int hex);				// Set equal to a hex value. Same as calling ->Set(hex)
		oSDL::Color& operator=(oSDL::Colors color);				// Set equal to a color enumerator. Same as calling ->Set(COLOR_...)

		oSDL::Color operator+(oSDL::Color& other);				// Additive blend
		oSDL::Color& operator+=(oSDL::Color& other);			// Additive blend + assignment
		oSDL::Color operator+(unsigned int hex);				// Additive blend against hex integer
		oSDL::Color& operator+=(unsigned int hex);				// Additive blend against hex integer + assignment

		oSDL::Color operator-(oSDL::Color& other);				// Subtractive blend
		oSDL::Color& operator-=(oSDL::Color& other);			// Subtractive blend + assignment
		oSDL::Color operator-(unsigned int hex);				// Subtractive blend against hex integer
		oSDL::Color& operator-=(unsigned int hex);				// Subtractive blend against hex integer + assignment

		oSDL::Color operator*(oSDL::Color& other);				// Multiply blend
		oSDL::Color& operator*=(oSDL::Color& other);			// Multiply blend + assignment
		oSDL::Color operator*(float scale);						// Scalar
		oSDL::Color& operator*=(float scale);					// Scalar + assignment

		oSDL::Color operator/(oSDL::Color& other);				// Divides on 1-to-1. r/r, g/g, b/b, a/a
		oSDL::Color& operator/=(oSDL::Color& other);			// Divides on 1-to-1. r/r, g/g, b/b, a/a + assignment
		oSDL::Color operator/(float scale);						// Scalar
		oSDL::Color& operator/=(float scale);					// Scalar + assignment

		Uint8& operator[](Uint8 index);		// Array-style reference to values. 0=Red, 1=Green, 2=Blue, 3=Alpha




		//std::istream& operator>>(std::istream& str);			// Stream output
		std::ostream& operator<<(std::ostream& str);			// Stream input


		static Uint8 GetRedFromHex(Uint32 color);		// Parses out the red from colors stored in a 32-bit integer
		static Uint8 GetGreenFromHex(Uint32 color);		// Parses out the green from colors stored in a 32-bit integer
		static Uint8 GetBlueFromHex(Uint32 color);		// Parses out the blue from colors stored in a 32-bit integer
		static Uint8 GetAlphaFromHex(Uint32 color);		// Parses out the alpha from colors stored in a 32-bit integer

		static Uint8 GetRedFromHex(std::string hex);			// Parses out the red from strings formatted in hex RRGGBBAA, RRGGBB, RGBA, or RGB
		static Uint8 GetGreenFromHex(std::string hex);			// Parses out the green from strings formatted in hex RRGGBBAA, RRGGBB, RGBA, or RGB 
		static Uint8 GetBlueFromHex(std::string hex);			// Parses out the blue from strings formatted in hex RRGGBBAA, RRGGBB, RGBA, or RGB
		static Uint8 GetAlphaFromHex(std::string hex);			// Parses out the alpha from strings formatted in hex RRGGBBAA, RRGGBB, RGBA, or RGB. Default is 255

		void Destroy();									// Called internally. Does clean up
	};
}

#endif