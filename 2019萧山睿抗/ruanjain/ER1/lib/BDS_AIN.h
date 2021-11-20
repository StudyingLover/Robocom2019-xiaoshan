#ifndef __BDS_AIN_H__
#define __BDS_AIN_H__
#include "DEVICE.H"
#include "double.h"

class BDS_AIN : public DEVICE
{
public:
	BDS_AIN();
	Double read(u8 port);
};


extern BDS_AIN bds_ain;



#endif