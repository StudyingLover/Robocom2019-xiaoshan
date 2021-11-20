#ifndef _COLORSENSOR_H
#define _COLORSENSOR_H

#include "DEVICE.H"

typedef struct
{
	u8 r;
	u8 g;
	u8 b;
}Color_Def;

class ColorSensor : public DEVICE
{
public:
	Color_Def getRGB_Original(u8 addess);
	Color_Def getRGB(u8 addess);
	u8 getColor(u8 addess);

	void  setRGB_ADJ(u8 addess,u8 threshold,u8 powR, u8 powG, u8 powB);
	void Init(U8 DevAddess);
	virtual void errProcessing(U8 DevAddess);
};

extern ColorSensor colorSensor;


#endif






