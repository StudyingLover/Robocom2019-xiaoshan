#ifndef _KEY_H_
#define _KEY_H_
#include "DEVICE.H"




typedef union
{
	struct
	{
	u8 UP : 1;
	u8 DOWN : 1;
	u8 LEFT : 1;
	u8 RIGHT : 1;
	u8 OK : 1;
	u8 bit5: 1;
	u8 bit6 : 1;
	u8 bit7 : 1;
	};
	u8 keyValue;
}BUTTON_DEF;

class BUTTON : public DEVICE
{
public:
	bool ReadValue(char key, bool issync = true);
	uint8_t ReadPanelKey(bool isWait = true);
	void WaitKeyUp(char key);
	void WaitKeyDown(char key);
	//bool ReadValue(uint8_t addess, char key, bool issync = true);
	//bool ReadValue(char key);
	U8 Read(bool issync = true);
private:
	U16 KEY_VALUE = 0;
	U16 KEY_VALUE2 = 0;
	U16 GetKeyValue(U8 k);
	
};

extern BUTTON button;
#endif