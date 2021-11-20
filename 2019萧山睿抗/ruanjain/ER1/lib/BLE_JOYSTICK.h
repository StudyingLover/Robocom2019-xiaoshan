#ifndef _BLE_JOYSTICK_H
#define _BLE_JOYSTICK_H

#include <DEVICE.h>
#include <CC2541.h>
#include <Double.h>

typedef struct
{
	u8 UP : 1;
	u8 DOWN : 1;
	u8 LEFT : 1;
	u8 RIGHT : 1;
	u8 A : 1;//Èý½Ç
	u8 B : 1;//²æ
	u8 C : 1;//·½¿é
	u8 D : 1;//Ô²È¦

	u8 L1 : 1;
	u8 L2 : 1;
	u8 L3 : 1;
	u8 R1 : 1;
	u8 R2 : 1;
	u8 R3 : 1;
	u8 SELECT : 1;
	u8 START : 1;

	Double LX;
	Double LY;
	Double RX;
	Double RY;
}BLE_JoyData;


class BLE_JOYSTICK : public DEVICE
{
public:
	BLE_JOYSTICK();
	BLE_JoyData GetData();
	BLE_JoyData GetData_f();
protected:
	BLE_JoyData j;
	int32_t LastTime;

	s16 ChuLiData(s8 data);
	float ChuLiData_f(s8 data);

};

extern BLE_JOYSTICK ble_joystick;

#endif



