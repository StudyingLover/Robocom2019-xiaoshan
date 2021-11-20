/*
 * AT24Cxx.h - library for AT24Cxx
 */

#ifndef AT24Cxx_h
#define AT24Cxx_h

class AT24Cxx
{
	// user-accessible "public" interface
public:
	AT24Cxx();
	AT24Cxx(uint8_t);

	static bool isPresent(void);      // check if the device is present
	static uint8_t Read(uint8_t iAddr);
	static bool Read(uint8_t iAddr, uint8_t * Buf, int iCnt);
	static bool Write(uint8_t iAddr, uint8_t iVal);
	static bool Write(uint8_t iAddr, const uint8_t *pBuf, int iCnt);

	static int ReadStr(uint8_t iAddr, char Buf[], int iBufLen);
	static uint8_t WriteStr(uint8_t iAddr, const char *pBuf);

	float ReadVer(uint8_t iAddr);

	void WriteVer(uint8_t iAddr, float value);

private:
	static bool WaitBusy();
};

extern AT24Cxx eeprom;


#endif
