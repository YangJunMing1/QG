#include<iostream>
#include"LinkStack.h"
#include"SqStack.h"
class Menu
{
public:
	void Menu_1();			//˳��ջ or ��ջ
	void Menu_2();			//����ѡ��
	template<class T>
	void Menu_3(T &temp);			//˳��ջ
	template<class T>
	void Menu_4(T& temp);			//��ջ

	void select_1();		
	void select_2();
	template<class T>
	bool select_3(T& temp);
	template<class T>
	bool select_4(T& temp);

	char correct(char sel_1, char sel_2);			//����,����Ϊѡ�Χ
private:
	bool isLink;

};

