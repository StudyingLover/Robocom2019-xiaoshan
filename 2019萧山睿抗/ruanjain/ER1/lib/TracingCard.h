#ifndef _TracingCard_H
#define _TracingCard_H
#include "DEVICE.H"

class TracingCard : public DEVICE
{
public:
	//获取寻迹卡每个光头的值  参数grayValue 应传入一个u16类型 长度为8的数组
	bool Get_GrayValue(uint8_t addess, u16 * grayValue);
	//设置寻迹卡每个光头的阈值  参数grayValue 应传入一个u16类型 长度为8的数组
	bool Set_Threshold(uint8_t addess, u16 threshold1, u16 threshold2, u16 threshold3, u16 threshold4, u16 threshold5, u16 threshold6, u16 threshold7, u16 threshold8);
	//获取光值和阈值比较后的值，返回的一个字节，每一个位代表一个光电的比较结果 1表示光值比阈值大，0表示光值比阈值小
	u8 Get_ComparingResults(uint8_t addess);
};

extern TracingCard tracing;

#endif