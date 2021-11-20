#ifndef _TracingCard_H
#define _TracingCard_H
#include "DEVICE.H"

class TracingCard : public DEVICE
{
public:
	//��ȡѰ����ÿ����ͷ��ֵ  ����grayValue Ӧ����һ��u16���� ����Ϊ8������
	bool Get_GrayValue(uint8_t addess, u16 * grayValue);
	//����Ѱ����ÿ����ͷ����ֵ  ����grayValue Ӧ����һ��u16���� ����Ϊ8������
	bool Set_Threshold(uint8_t addess, u16 threshold1, u16 threshold2, u16 threshold3, u16 threshold4, u16 threshold5, u16 threshold6, u16 threshold7, u16 threshold8);
	//��ȡ��ֵ����ֵ�ȽϺ��ֵ�����ص�һ���ֽڣ�ÿһ��λ����һ�����ıȽϽ�� 1��ʾ��ֵ����ֵ��0��ʾ��ֵ����ֵС
	u8 Get_ComparingResults(uint8_t addess);
};

extern TracingCard tracing;

#endif