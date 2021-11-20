#ifndef _CC2541_H
#define _CC2541_H

#include "base64.h"
#include "menu.h"
//#include "system.h"



typedef enum BLE_ErrStatus
{
	SUCCESS = 0,
	bleInvalidTaskID = 0x03,
	bleNotReady = 0x10,
	bleAlreadyInRequestedMode = 0x11,
	bleIncorrectMode = 0x12,
	bleMemAllocError = 0x13,
	bleNotConnected = 0x14,
	bleNoResources = 0x15,
	blePending = 0x16,
	bleTimeout = 0x17,
	bleInvalidRange = 0x18,
	bleLinkEncrypted = 0x19,
	bleProcedureComplete = 0x1A,
	bleInvalidMtuSize = 0x1B,
};

typedef enum
{
	//����ֵ��֪ͨ
	DataNotify,
	//����ֵ�ҵ�
	CharFound,
	//��������ֵ����
	CharFounded,
	//���ִӻ�
	FindSlaves,
	//���ִӻ����
	FindSlaveEnd,
	//���ӳɹ�
	ConnectSuccess,
	//����ʧ��
	ConnectFailed,
	//�ѶϿ��ӻ�
	Disconnect,

	//��Կ�ʼ
	PairingStart,
	//��Գɹ�
	PairingSuccess,
	//���ʧ��
	PairingFailed,
	//�󶨳ɹ�
	BondingSuccess,
	//��ʧ��
	BondingFailed,

	//���ɹ�
	ReadSuccess,
	//��ʧ��
	ReadFailed,
	//д�ɹ�
	WriteSuccess,
	//дʧ��
	WriteFailed,
}NotifyEvent;




#pragma pack (1)
typedef struct
{
	u8 mac[6];
	u32 pass;
}ConnectArg;

typedef struct
{
	u16 serv_uuid;
	u8 char_num;
	u16 char_uuid[0];
}FindArg;

typedef struct
{
	u16 handle;
	u8 len;
	u8 data[0];
}DataArg;

typedef struct
{
	NotifyEvent notifyEvent;
	u8 len;
	u8 data[0];
}NotifyArg;

typedef struct
{
	u16 handle;
	u16 uuid;
}CharFoundArg;

typedef struct
{
	u8 Mac[6];
	s8 Rssi;
	u8 NameLen;
	u8 Name[0];
}DeviceArg;

typedef struct
{
	u8 UP : 1;
	u8 DOWN : 1;
	u8 LEFT : 1;
	u8 RIGHT : 1;
	u8 A : 1;//����
	u8 B : 1;//��
	u8 C : 1;//����
	u8 D : 1;//ԲȦ

	u8 L1 : 1;
	u8 L2 : 1;
	u8 L3 : 1;
	u8 R1 : 1;
	u8 R2 : 1;
	u8 R3 : 1;
	u8 SELECT : 1;
	u8 START : 1;

	s8 LX;
	s8 LY;
	s8 RX;
	s8 RY;
}JoyData;

#pragma pack ()

typedef union
{
	u32 ststus = 0;
	struct
	{
		u32 isFindSlaveEnd : 1;
		u32 isConnect : 2;
		u32 isPairing : 3;
		u32 isBonding : 2;
		u32 isCharFound : 2;
		u32 isRead : 2;
		u32 isWrite : 2;
	};
}BLE_STATUS;


class CC2541
{
public:
	CC2541();
	//���Ҵӻ����г��ҵ��Ĵӻ��б�
	u8 findSlaves(u16 DevType);
	//���ӵ��ӻ�
	u8 Connect(u8 * mac, u32 pass);
	bool isReConnect(u8 * mac=0);
	void ReConnect();
	//�Ͽ�����
	u8 Disconnect();
	//���ַ�������
	u8 CharFound(FindArg * fa);
	//����ӻ���
	u8 ClsAllBonding();
	//��ָ������дֵ
	u8 write(u8 handle, u8 data);
	u8 write(u8 handle, u8 * data, u8 len);
	//��ָ��������ֵ
	u8 read(u8 handle, u8 * data, u8 len);
	u8 read(u8 handle);
	u8 GetConnectStatus();


	void test(u8);
	void test(u8 * cmd, u8 cmdlen);
	void menu();
	char * getConnectErrMsg(BLE_ErrStatus err);
	u8 openNotify(u8 ch);
	u8 closeNotify(u8 ch);

	~CC2541();

	//ConnectArg uuid = { {0,0,0,0,0,0},{ 0xfff1,0,0,0,0 } };


//private:

	
	typedef enum
	{
		CMD_RST,
		CMD_SCAN,
		CMD_CONNET,
		CMD_DISCONNECT,
		CMD_FINDCHAR,
		CMD_WRITE,
		CMD_READ,
		CMD_OPEN_NOTIFY,
		CMD_CLS_ALL_BONDING,

		CMD_GET_CONNET_STATUS,
	}Cmds;


	enum
	{
		//����
		BLE_STATE_IDLE,
		//������
		BLE_STATE_CONNECTING,
		//������
		BLE_STATE_CONNECTED,
		//�Ͽ���
		BLE_STATE_DISCONNECTING
	};


	void Rst();

	void writeDataPack(u8 * data, u8 len);
	u8 readDataPack(u8 * data, u8 len, u32 delay = 50);
	u8 writeCmd(u8 cmd);
	u8 writeCmd(u8 cmd, u8 * par, u8 parLen);
};

extern CC2541 cc2541;
extern bool IsHavaDevice;
extern volatile BLE_STATUS ble_status;
#endif // _CC2541_H


