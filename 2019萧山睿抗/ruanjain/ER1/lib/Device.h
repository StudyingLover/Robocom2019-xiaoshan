#ifndef _DEVICE_H
#define _DEVICE_H

#include "stdint.h"
#include "BaseDef.h"
#pragma pack(1)
typedef struct
{
	U16 DevType;
	U8 DevVer;
}DeviceInfoDef;
#pragma pack()

extern U32 ErrCount;
extern const char *DevName[];
extern U32 DataRecovery[12][15];
extern DeviceInfoDef DeviceList[12];

#define CMD_SetIicDev 0
#define CMD_GET_TYPE 1
#define CMD_GET_SN 2
#define CMD_GET_VER 3
#define DEBUG_SHOW(s,...) //Serial.printfln(s, ##__VA_ARGS__);
//#define DEBUG_SHOW(s) Debug(s)
class DEVICE
{
public:

	//正常通信返回true 否则返回false
	static bool PortTest(unsigned char addess);
	U16 GetDevType(unsigned char addess);
	U8 GetDevVer(unsigned char addess);
	U8 SetDevAddess(unsigned char DevAddess, unsigned char TargetAddess);
	void GetDevStr(U8 DevType, char * DevStr);

	static void WritePin(u32 pin, bool val);
	static bool ReadPin(u32 pin);
	static u32 ReadPin_AD(u32 pin);


	U8 Debug(const char * v);







	static U8 UserPort_TO_SystemPort_Digital(U8 p);
	static U8 UserPort_TO_SystemPort_Analogy(U8 p);
	bool checkPortDev();
	void DeviceInit();
	static const char* getDevName(u8 DevIndex);

	static void UpdateDeviceList();
	static void ResetAllDev();
//protected:
	U8 IIC_Write(U8 DevAddess, U8 cmd, U8 * data = 0, U16 data_len = 0, bool = true);
	U8 IIC_Read(U8 DevAddess, U8 cmd, U8 * data, U8 data_len, bool = true);



	virtual void errProcessing(U8 DevAddess);
private:
	bool IIC_ErrHandling(U8 DevAddess, bool isread,U8 ErrCode);
};
#include "SYSTEM.H"
#endif