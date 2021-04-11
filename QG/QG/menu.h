#ifndef __MENU_H__
#define __MENU_H__
#include"qgforwardlist.cpp"
#include"qglist.cpp"
#include"FillReview.h"
using namespace std;

class menu
{

public:
	void Menu_1();					//单双链表选择
	void Menu_2();					//类型选择
	template<class T>
	void Menu_3(T &temp);			//函数选择
	template<class T>
	void Menu_4(T &temp);


	void select_1();
	void select_2();
	template<class T>
	void select_3(char i,T &temp,bool &Loop);
	template<class T>
	void select_4(char i,T &temp,bool &Loop);
	void CreatList();

private:
	bool isForward = true;
	int select=0;


};

#endif
