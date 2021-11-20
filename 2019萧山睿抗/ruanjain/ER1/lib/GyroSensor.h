#ifndef _GYROSENSOR_H
#define _GYROSENSOR_H

#include "DEVICE.H"

typedef struct
{
	float Pitch;
	float Roll;
	float Yaw;
}EulerDef;
typedef struct
{
	float W;
	float X;
	float Y;
	float Z;
}QuatDef;
typedef struct
{
	s16 X;
	s16 Y;
	s16 Z;
}GyroRawDef;






class GyroSensor : public DEVICE
{
public:
	GyroSensor();

	//读取欧拉角
	EulerDef getEuler(u8 addess);
	//读取四元素
	QuatDef getQuat(u8 addess);

	//读取陀螺仪原始数据
	GyroRawDef getGyro(u8 addess);
	//读取加速度计原始数据
	GyroRawDef getAccel(u8 addess);
	//读取磁强计原始数据
	GyroRawDef getCompass(u8 addess);
	//读取芯片温度原始数据
	s16 getTemp(u8 addess);

	//校准陀螺仪，成功返回true，失败返回false。
	bool SelfTest(u8 addess, bool showStatus = true);
	void test();


private:
	u32 LastTime;
	void _delay();
};

extern GyroSensor gyroSensor;


#endif

