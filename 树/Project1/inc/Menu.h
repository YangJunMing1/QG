#include<iostream>
#include<string>
#include"binary_sort_tree.h"

class Menu
{
public:
	void Menu_1();	//ѡ������
	template<class T>
	void Menu_2(T &temp);//���˵�

	void select_1();
	template<class T>
	void select_2(bool& unexit,T& temp);

	char correct(std::string b);	//ѡ�������
private:
	int elem;
	
};