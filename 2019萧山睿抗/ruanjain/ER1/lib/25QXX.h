#ifndef _25QXX_H
#define _25QXX_H


class W25QXX
{
public:
	W25QXX();
	U8 read(U32 add);
	void read(U32 add, U8*data, U32 Length);
private:
#define W25QXX_CS  24
};

extern W25QXX w25qxx;

#endif
