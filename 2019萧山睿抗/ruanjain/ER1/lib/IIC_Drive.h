#ifndef _IIC_DEVICE_H
#define _IIC_DEVICE_H



class IIC
{
	
public:
	IIC(void *t);
	U8 write(U8 DevAddess, U8 * data, U16 data_len);
	U8 write(U8 DevAddess, U8 data);
	U8 read(U8 DevAddess, U8 * data, U8 data_len);
private:
	void *Iic = NULL;
};
extern IIC iic;
extern IIC iic1;
#endif
