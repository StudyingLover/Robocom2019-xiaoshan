#ifndef _ADAFRUIT_GFX_H
#define _ADAFRUIT_GFX_H


#include <stdarg.h>
#include "double.h"

#define swap(a, b) { int16_t t = a; a = b; b = t; }


typedef enum FONT
{
	FONT12 = 12,
	FONT16 = 16,
	FONT24 = 24,
};
typedef enum COLOR
{
	BLACK = 0,
	WHITE = 1,
	INVERSE = 2,
	TRANSPARENT = 3,
};

class Adafruit_GFX
{

public:

	Adafruit_GFX(int16_t w, int16_t h); // Constructor

	//这个必须由子类定义：
	virtual void drawPixel(int16_t x, int16_t y, COLOR color = WHITE) = 0;

	//这些可以被子类覆盖以提供特定于设备的优化代码。 否则使用'通用'版本。
	virtual void
		drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, COLOR color = WHITE),
		drawFastVLine(int16_t x, int16_t y, int16_t h, COLOR color = WHITE),
		drawFastHLine(int16_t x, int16_t y, int16_t w, COLOR color = WHITE),
		drawRect(int16_t x, int16_t y, int16_t w, int16_t h, COLOR color = WHITE),
		fillRect(int16_t x, int16_t y, int16_t w, int16_t h, COLOR color = WHITE),
		fillScreen(COLOR color = WHITE),
		invertDisplay(bool i);



	// These exist only with Adafruit_GFX (no subclass overrides)
	void
		drawCircle(int16_t x0, int16_t y0, int16_t r, COLOR color = WHITE),
		drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, COLOR color = WHITE),
		fillCircle(int16_t x0, int16_t y0, int16_t r, COLOR color = WHITE),
		fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, COLOR color = WHITE),
		drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, COLOR color = WHITE),
		fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, COLOR color = WHITE),
		drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, COLOR color = WHITE),
		fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, COLOR color = WHITE),
		drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, COLOR color = WHITE),
		drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, COLOR color, COLOR bg),
		drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, COLOR color = WHITE),
		setCursor(int16_t x, int16_t y),
		setTextColor(uint16_t c),
		setTextColor(uint16_t c, COLOR bg = WHITE),
		setTextSize(uint8_t s),
		setRotation(uint8_t r);

	void printStr(FONT FontName, const char * s, S16 x, S16 y, COLOR color = WHITE, COLOR bg = TRANSPARENT);
	void printNum(FONT FontName, Double n, U8 d, S16 x, S16 y, COLOR color = WHITE, COLOR bg = TRANSPARENT);
	void printf(FONT FontName, S16 x, S16 y, const char * fmt, ...);
	void printf(FONT FontName, S16 x, S16 y, COLOR color, const char * fmt, ...);
	void printf(FONT FontName, S16 x, S16 y, COLOR color, COLOR bg, const char * fmt, ...);
	//const unsigned char * GetFont_12(char c);

	int16_t height(void) const;
	int16_t width(void) const;

	uint8_t getRotation(void) const;

	// get current cursor position (get rotation safe maximum values, using: width() for x, height() for y)
	int16_t getCursorX(void) const;
	int16_t getCursorY(void) const;

protected:
	const int16_t
		WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
	int16_t
		_width, _height, // Display w/h as modified by current rotation
		cursor_x, cursor_y;
	uint16_t
		textcolor, textbgcolor;
	uint8_t
		textsize,
		rotation;

private:
	void _printf(FONT FontName, S16 x, S16 y, COLOR color, COLOR bg, const char * fmt, va_list ap);

	//typedef struct
	//{
	//	const unsigned char *font;
	//	uint8_t w;
	//	uint8_t h;
	//} Font_Info;
	//void GetFont(Font_Info *font_info, int FontName, int c);
};



#endif // _ADAFRUIT_GFX_H
