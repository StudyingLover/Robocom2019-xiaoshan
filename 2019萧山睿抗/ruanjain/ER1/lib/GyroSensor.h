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

	//��ȡŷ����
	EulerDef getEuler(u8 addess);
	//��ȡ��Ԫ��
	QuatDef getQuat(u8 addess);

	//��ȡ������ԭʼ����
	GyroRawDef getGyro(u8 addess);
	//��ȡ���ٶȼ�ԭʼ����
	GyroRawDef getAccel(u8 addess);
	//��ȡ��ǿ��ԭʼ����
	GyroRawDef getCompass(u8 addess);
	//��ȡоƬ�¶�ԭʼ����
	s16 getTemp(u8 addess);

	//У׼�����ǣ��ɹ�����true��ʧ�ܷ���false��
	bool SelfTest(u8 addess, bool showStatus = true);
	void test();


private:
	u32 LastTime;
	void _delay();
};

extern GyroSensor gyroSensor;


#endif

