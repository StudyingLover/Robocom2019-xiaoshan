#ifndef _CMDSYS_H
#define _CMDSYS_H

class CmdSys
{
private:
#pragma pack(1)
	typedef struct
	{
		u8 cmd;
		u8 port;
		u8 data[];
	}DataDef;

	typedef struct
	{
		u8 port;
		U16 DevType;
		U8 DevVer;
		u8 data[];
	}Device_SwapData_Def;
#pragma pack()
public:
	void ReceiveData(u8 data);
	void writeDataPack(u8 * data, u8 len);
	void writeDataPack(u8 cmd, u8 * data, u8 len);
	void writeDataPack(u8 * data1, u8 len1, u8 * data2, u8 len2);
	void Device_SwapData(DataDef * dataDef);
	bool Exec();
	void printf(const char *fmt, ...);
};

extern CmdSys cmdSys;

#endif



