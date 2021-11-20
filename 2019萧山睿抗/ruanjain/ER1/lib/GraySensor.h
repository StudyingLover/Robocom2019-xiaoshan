#ifndef _Gray_Scale_Sensor_H
#define _Gray_Scale_Sensor_H

#include "DEVICE.H"

typedef enum
{
	White,		//°×
	Red,
	Green,
	Blue,
	Yellow,		//»Æ
	Cyan,		//Çà
	Magenta,	//Æ·ºì
}Gray_Color_Def;

class Gray_Scale_Sensor : public DEVICE
{
public:

	int16_t Get_GrayValue(uint8_t addess);
	bool Set_DebounceTime(uint8_t addess,uint16_t time);
	bool Set_Threshold(uint8_t addess, uint16_t v);
	int16_t Get_GrayValue(uint8_t addess, uint8_t r, uint8_t g, uint8_t b);
	int16_t Get_GrayValue(uint8_t addess, Gray_Color_Def color);
	bool Set_LedValue(uint8_t addess, uint8_t r, uint8_t g, uint8_t b);
	bool Set_LedValue(uint8_t addess, Gray_Color_Def color);
	void test();
protected:
	void errProcessing(U8 DevAddess);
	
private:

};

extern Gray_Scale_Sensor Gray;


#endif
