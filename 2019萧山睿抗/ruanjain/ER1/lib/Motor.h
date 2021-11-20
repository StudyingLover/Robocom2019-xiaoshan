#ifndef _MOTOR_H
#define _MOTOR_H
#include "DEVICE.H"

typedef enum
{
	Motor_ActionType_Time,
	Motor_ActionType_Angle,
	Motor_ActionType_Coil,
	Motor_ActionType_Cont,
	Motor_ActionType_Stop,
}Motor_ActionType;
class Motor : public DEVICE
{
public:

	unsigned char SetAction_f(unsigned char addess, double actiontype, double data, double speed, double stoptype, bool isShowErr = true);
	unsigned char SetAction(u8 addess, u8 actiontype, double data, s32 speed, u8 outputMode, bool isShowErr = true);
	bool GetBusy(unsigned char addess, bool isShowErr = true);
	void WaitBusy(unsigned char addess, bool isShowErr = true);
	double GetCount(unsigned char addess, bool isShowErr = true);
	void SetCount(unsigned char addess, double count, bool isShowErr = true);
	void test();
};

extern Motor motor;

#endif