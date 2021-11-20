#ifndef _BATTERY_H
#define _BATTERY_H
#include "SYSTEM.h"

class BATTERY
{
public:
	static U16 ReadBatteryVersion();
	static float ReadBatteryVoltage();
	static float ReadLowVoltageLevel();
	static U16 ReadBatteryTYPE();
	static void ReadBatterySN(U8 * sn);
};

extern BATTERY Battery;
#endif