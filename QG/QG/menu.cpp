#include "menu.h"

void menu::Menu_1()
{
	cout << "选择链表" << endl;
	cout << "1.单向链表" << endl;
	cout << "2.双向链表" << endl;
	select_1();
	system("cls");
}

void menu::Menu_2()
{
	cout << "选择数据类型" << endl;
	cout << "1.int" << endl;
	cout << "2.double" << endl;
	cout << "3.string" << endl;
	cout << "4.char" << endl;
	select_2();
}

template<class T>
void menu::Menu_3(T &temp)
{	
	char i;
	bool Loop = true;
	do 
	{
		system("cls");
		cout << "1.第一个元素" << endl;
		cout << "2.最后一个元素" << endl;
		cout << "3.前面加一个元素" << endl;
		cout << "4.删除第一个元素" << endl;
		cout << "5.删除最后一个元素" << endl;
		cout << "6.插入元素" << endl;
		cout << "7.删除元素" << endl;
		cout << "8.清空链表" << endl;
		cout << "9.查找元素" << endl;
		cout << "a.元素个数" << endl;
		cout << "b.打印链表" << endl;
		cout << "c.关于算法（单向）" << endl;
		cout << "0.exit" << endl;
		cin >> i;
		select_3(i,temp,Loop);
	} while (Loop);
	return;
}


template<class T>
void menu::Menu_4(T& temp)
{
	char i;
	bool Loop = true;
	do
	{
		system("cls");
		cout << "1.迭代反转" << endl;
		cout << "2.递归反转" << endl;
		cout << "3.链表判环" << endl;
		cout << "4.偶节点反转" << endl;
		cout << "5.中间节点" << endl;
		cout << "6.打印链表" << endl;
		cout << "0.返回" << endl;
		cin >> i;
		select_4(i, temp, Loop);
	} while (Loop);
	return;
}


void menu::select_1()
{
	char i;
	bool Loop=false;
	do
	{
		if(Loop==false)
			cout << "请选择: ";
		cin >> i;
		switch (i) 
		{
		case '1':isForward = true; Loop = false; break;
		case '2':isForward = false; Loop = false; break;
		default:Loop = true;
		}
	
		if (Loop)
			cout << "请按选项选择: ";
	} while (Loop);
	
}

void menu::select_2()
{
	char i;
	bool Loop = false;
	do
	{
		if (Loop == false)
			cout << "请选择: ";
		cin >> i;
		switch (i)
		{
		case '1': select = 1; Loop = false; break;
		case '2': select = 2; Loop = false; break;
		case '3': select = 3; Loop = false; break;
		case '4': select = 4; Loop = false; break;
		default : Loop = true;
		}

		if (Loop)
			cout << "请按选项选择: ";
	} while (Loop);
}

template<class T>
void menu::select_3(char i, T& temp, bool& Loop)
{
	bool error = false;
	switch (i)
	{
	case'1':
	{
		if (temp.head == NULL)
			cout << "链表为空" << endl;
		else
			cout << "第一个元素为" << temp.front() << endl; 
		break;
	}
	case'2':
	{
		if (temp.head == NULL)
			cout << "链表为空" << endl;
		else
			cout << "最后一个元素为" << temp.back() << endl; 
		break;
	}
	case'3': {
		cout << "请输入元素" << endl;
		if (temp.push_front(temp.CreatFill()))
			cout << "添加完成" << endl;
		else
			cout << "添加失败" << endl;
		break;
	}
	case'4': {
		if (temp.pop_front())
			cout << "删除成功" << endl;
		else
			cout << "删除失败" << endl;
		break;
	}
	case'5': {
		if (temp.head == NULL)cout << "链表已为空" << endl;
		if (temp.pop_back())cout << "删除成功" << endl;
		else cout << "删除失败" << endl;
		break;
	}
	case'6': {
		int a, num = temp.size();
		cout << "节点共" << num << "个，你希望插入的元素是第几个节点：";
		bool Loop_1 = true;
		do {
			cin >> a;
			if (a >= 1 && a <= num + 1)
				Loop_1 = false;
			if (Loop_1 == true)
				cout << "请合理输入" << endl;
		} while (Loop_1);
		cout << "请输入元素" << endl;
		if (temp.insert(a, temp.CreatFill()))
			cout << "插入完成" << endl;
		else
			cout << "插入失败" << endl;
		break;
	}
	case'7': {
		int a, num = temp.size();
		cout << "节点共" << num << "个，你希望删除的元素是第几个节点：";
		bool Loop_1 = true;
		do {
			cin >> a;
			if (a >= 1 && a <= num)
				Loop_1 = false;
			if (Loop_1 == true)
				cout << "请合理输入" << endl;
		} while (Loop_1);
		if (temp.erase(a))
			cout << "删除完成" << endl;
		else cout << "删除失败" << endl;
		break;
	}
	case'8': {
		if (temp.head == NULL)
			cout << "链表已为空" << endl;
		else {
			temp.clear();
			cout << "清空完成" << endl;
		}
		break;
	}
	case'9': {
		cout << "请输入你想查找的元素：";
		if (!temp.contain(temp.CreatFill()))
			cout << "未找到该元素" << endl;
		break;
	}
	case'a':cout << "当前链表共" << temp.size() << "节点" << endl;
	case'b':temp.print(); break;
	case'c': {
		if (isForward)
			Menu_4(temp);
		else
			cout << "该链表不是单向链表" << endl;
		break;
	}
	case'0':Loop=false; break;
	default:cout << "请按选项输入" << endl;
	}
	system("pause");
}

template<class T>
void menu::select_4(char i, T& temp, bool& Loop)
{
	switch (i)
	{
	case'1': {
		if (temp.reverse_1())
			cout << "反转完成" << endl;
		else
			cout << "反转失败" << endl;
		break;
	}
	case'2': {
		if(temp.size()!=1)
			temp.reverse_2(temp.head);
		cout << "反转完成" << endl;
		break;
	}
	case'3': {
		if (temp.isLoop())
			cout << "该链表成环" << endl;
		else
			cout << "该链表不成环" << endl;
		break;
	}
	case'4': {
		if (temp.reverseEven())
			cout << "反转完成" << endl;
		else
			cout << "反转失败" << endl;
		break;
	}
	case'5':cout << "中间节点为" << temp.middleElem().data << endl; break;
	case'6':temp.print(); break;
	case'0':Loop = false;break;
	default:cout << "请按选项输入" << endl;
	}
	if(Loop!=false)
		system("pause");
}



void menu::CreatList()
{
	if (isForward)
	{
		if (select == 1) { QGForwardList<int> list_1; Menu_3(list_1); }
		if (select == 2) { QGForwardList<double> list_2; Menu_3(list_2); }
		if (select == 3) { QGForwardList<string> list_3; Menu_3(list_3); }
		if (select == 4) { QGForwardList<char> list_4; Menu_3(list_4); }
		
	}
	else
	{
		if (select == 1) { QGList<int> list_1; Menu_3(list_1); }
		if (select == 2) { QGList<double> list_2; Menu_3(list_2); }
		if (select == 3) { QGList<string> list_3; Menu_3(list_3); }
		if (select == 4) { QGList<char> list_4; Menu_3(list_4); }
	}
}