#ifndef _MENU_H
#define _MENU_H


class Menu
{
public:
	Menu(const char* menuName, u8 itemLines, const char*(*cb)(u8));
	//const char * MenuCB(u8 index);
	Menu(const char * MenuName, const char * menu[], u8 len);
	
	u8 Show();
	void reg_getkey(U8(* fp)());
	void reg_menuEvent(u8(*fp)(u8 menuIndex));

	static U8 waitkey();
	static U8 scankey();

private:
	const char * _itemcb(u8);


	const char * menuName;
	U8(*getkey)() = 0;
	u8(*menuEvent)(U8 menuIndex) = 0;
	u8 itemLines;
	s8 MaxLineIndex = 0;
	
	const char*(*itemcb)(u8) = 0;
};


u8 menu();


#endif


