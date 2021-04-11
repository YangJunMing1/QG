#include "Menu.h"

void Menu::Menu_1()
{
	std::cout << "1.顺序栈" << std::endl;
	std::cout << "2.链栈" << std::endl;
	select_1();
}

void Menu::select_1()
{
	char temp = correct('1', '2');
	switch (temp)
	{
	case '1':isLink=false; break;
	case '2':isLink=true; break;
	}
	return;
}

void Menu::Menu_2()
{
	std::cout << "1.int" << std::endl;
	std::cout << "2.char" << std::endl;
	std::cout << "3.double" << std::endl;
	std::cout << "4.string" << std::endl;
	select_2();
}

void Menu::select_2()
{
	char temp=correct('1', '4');
	if(isLink)
		switch (temp)
		{
		case'1': {St<int> stack; Menu_4(stack); break; }
		case'2': {St<char> stack; Menu_4(stack); break; }
		case'3': {St<double> stack; Menu_4(stack); break; }
		case'4': {St<string> stack; Menu_4(stack); break; }
		}
	else
	{
		int count;
		std::cout << "请输入栈最大长度" << std::endl;
		std::cin >> count;
		switch (temp)
		{
		case'1': {Sh<int> stack(count); Menu_3(stack); break; }
		case'2': {Sh<char> stack(count); Menu_3(stack); break; }
		case'3': {Sh<double> stack(count); Menu_3(stack); break; }
		case'4': {Sh<string> stack(count); Menu_3(stack); break; }
		}
	}
}

template<class T>
void Menu::Menu_3(T& temp)
{
	do
	{
		system("cls");
		std::cout << "当前栈最大空间：";
		temp.print_size();
		std::cout<<std::endl;
		std::cout << "1.初始化" << std::endl;
		std::cout << "2.栈是否为空" << std::endl;
		std::cout << "3.栈顶元素" << std::endl;
		std::cout << "4.清空栈" << std::endl;
		std::cout << "5.销毁栈" << std::endl;
		std::cout << "6.栈长度" << std::endl;
		std::cout << "7.入栈" << std::endl;
		std::cout << "8.出栈" << std::endl;
		std::cout << "9.打印" << std::endl;
		std::cout << "0.exit" << std::endl;
	} while (select_3(temp));
}

template<class T>
bool Menu::select_3(T& temp)
{
	char c;
	c = correct('0', '9');
	switch (c)
	{
	case '1': 
	{
		std::cout << "请输入数据" << std::endl;
		temp.initStack(); 
		break;
	}
	case '2': 
	{
		if (temp.isEmptyStack())
			std::cout << "空" << std::endl;
		else
			std::cout << "非空" << std::endl;
		break;
	}
	case '3': 
	{
		if(!temp.getTopStack())
		cout<<"当前栈已空"<<std::endl;
		break; 
	}
	case '4': {temp.clearStack(); break; }
	case '5': 
	{
		if (temp.destroyStack())
			std::cout << "销毁完成" << std::endl;
		else
			std::cout<<"销毁失败，栈不存在"<<std::endl;
		break; 
	}
	case '6': {temp.stackLength(); break; }
	case '7':
		{
		
		if (temp.init)
		{
			if (!temp.pushStack())
				std::cout << "当前栈已满" << std::endl;
		}
		else
		{
			std::cout << "请先初始化" << std::endl;
		}
		break; }
	case '8': 
	{
		if (temp.popStack())
			std::cout << "顶部数据出栈完成" << std::endl;
		else
			std::cout << "当前暂无数据" << std::endl;
		break;
	}
	case '9': {temp.print(); break; }
	case '0':return false;
	}
	system("pause");
	return true;
}


template<class T>
void Menu::Menu_4(T& temp)
{
	do
	{
		system("cls");
		std::cout << "1.初始化" << std::endl;
		std::cout << "2.栈是否为空" << std::endl;
		std::cout << "3.栈顶元素" << std::endl;
		std::cout << "4.清空栈" << std::endl;
		std::cout << "5.销毁栈" << std::endl;
		std::cout << "6.栈长度" << std::endl;
		std::cout << "7.入栈" << std::endl;
		std::cout << "8.出栈" << std::endl;
		std::cout << "9.打印" << std::endl;
		std::cout << "0.exit" << std::endl;
	} while (select_4(temp));
}

template<class T>
bool Menu::select_4(T& temp)
{
	char c;
	c = correct('0', '9');
	switch (c)
	{
	case '1': 
	{
		std::cout << "请输入数据且输入0时结束" << std::endl;
		temp.initLStack();
		break;
	}
	case '2':
	{
		if (temp.isEmptyLStack())
			std::cout << "空" << std::endl;
		else
			std::cout << "非空" << std::endl;
		break;
	}
	case '3': 
	{
		if (!temp.getTopLStack())
			std::cout << "当前栈已空" << std::endl;
		break;
	}
	case '4': 
	{	
		temp.clearLStack();
		break;
	}
	case '5': 
	{
		if (temp.destroyLStack())
			std::cout << "销毁完成" << endl;
		else
			std::cout << "销毁失败，栈不存在";
		break;
	}
	case '6': {temp.LStackLength(); break; }
	case '7': 
	{	
		if (temp.init)
		{
			std::cout << "请输入数据" << std::endl;
			temp.pushLStack();
		}
		else
			std::cout << "请先初始化" << std::endl;

		break;
	}
	case '8': 
	{
		if (temp.popLStack())
			std::cout << "顶部数据出栈完成"<<std::endl;
		else
			std::cout << "当前暂无数据" << std::endl;
		break; 
	}
	case '9': {temp.print(); break; }
	case '0':return false;
	}
	system("pause");
	return true;
}

char Menu::correct(char sel_1,char sel_2)
{
	char temp;
	bool loop=false;
	do
	{
		if (!loop)
		{
			loop = true;
			std::cout << "请输入" << std::endl;
		}
		else
			std::cout << "请合理输入" << std::endl;
		std::cin >> temp;
	} while (sel_1 > temp || temp > sel_2);
	return temp;
}