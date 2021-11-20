#pragma once


class BOOT_TIME
{
public:
	u32 getTime();
	void setTime(u32 count);
	u32 getAbsoluteTime();
private:
	u32 statrtTime = 0;
};

extern BOOT_TIME BootTime;