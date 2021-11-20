#pragma once
#include "DEVICE.H"


class RgbLed : public DEVICE
{
public:
	bool Set_LedColor_f(uint8_t addess, double r, double g, double b);
	bool Set_LedColor(uint8_t addess, uint8_t r, uint8_t g, uint8_t b);
};

extern RgbLed RGBLED;



