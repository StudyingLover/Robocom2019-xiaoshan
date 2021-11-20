
#ifndef _GamePad_H
#define _GamePad_H

#include <DEVICE.h>




class GAMEPAD : public DEVICE
{
public:
	
		//SELECT¡¢L3¡¢R3¡¢START¡¢UP¡¢RIGHT¡¢DOWN¡¢LEFT
	
#define	GAMEPAD_KEY_SELECT  0x0001
#define	GAMEPAD_KEY_L3  0x0002
#define	GAMEPAD_KEY_R3  0x0004
#define	GAMEPAD_KEY_START  0x0008
#define	GAMEPAD_KEY_UP  0x0010
#define	GAMEPAD_KEY_RIGHT  0x0020
#define	GAMEPAD_KEY_DOWN  0x0040
#define	GAMEPAD_KEY_LEFT  0x0080

		//L2¡¢R2¡¢L1¡¢R1¡¢¡÷¡¢¡ð¡¢¨w¡¢¡õ
#define	GAMEPAD_KEY_L2  0x0100
#define	GAMEPAD_KEY_R2  0x0200
#define	GAMEPAD_KEY_L1  0x0400
#define	GAMEPAD_KEY_R1  0x0800
#define	GAMEPAD_KEY_A  0x1000//¡÷
#define	GAMEPAD_KEY_O  0x2000//¡ð
#define	GAMEPAD_KEY_X  0x4000//¨w
#define	GAMEPAD_KEY_B  0x8000//¡õ
	

	bool isKey(uint8_t addess, U16 k);
	s16 GetAnalog_LX(uint8_t addess);
	s16 GetAnalog_LY(uint8_t addess);
	s16 GetAnalog_RX(uint8_t addess);
	s16 GetAnalog_RY(uint8_t addess);

	float GetAnalog_LX_f(uint8_t addess);
	float GetAnalog_LY_f(uint8_t addess);
	float GetAnalog_RX_f(uint8_t addess);
	float GetAnalog_RY_f(uint8_t addess);

protected:
	
	float ChuLiData_f(U8 data);
	s16 ChuLiData(U8 data);
public:
	uint8_t * Get_data(uint8_t addess);
	uint8_t Data[6];
};

extern GAMEPAD GamePad;


#endif
