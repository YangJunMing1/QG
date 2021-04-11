#include<iostream>
#include"LinkStack.h"
#include"SqStack.h"
class Menu
{
public:
	void Menu_1();			//顺序栈 or 链栈
	void Menu_2();			//类型选择
	template<class T>
	void Menu_3(T &temp);			//顺序栈
	template<class T>
	void Menu_4(T& temp);			//链栈

	void select_1();		
	void select_2();
	template<class T>
	bool select_3(T& temp);
	template<class T>
	bool select_4(T& temp);

	char correct(char sel_1, char sel_2);			//纠错,参数为选项范围
private:
	bool isLink;

};

