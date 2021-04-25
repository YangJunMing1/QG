#include<iostream>
#include<string>
#include"binary_sort_tree.h"

class Menu
{
public:
	void Menu_1();	//选择类型
	template<class T>
	void Menu_2(T &temp);//主菜单

	void select_1();
	template<class T>
	void select_2(bool& unexit,T& temp);

	char correct(std::string b);	//选择纠错函数
private:
	int elem;
	
};