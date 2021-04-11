#include "menu.h"

void menu::Menu_1()
{
	cout << "ѡ������" << endl;
	cout << "1.��������" << endl;
	cout << "2.˫������" << endl;
	select_1();
	system("cls");
}

void menu::Menu_2()
{
	cout << "ѡ����������" << endl;
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
		cout << "1.��һ��Ԫ��" << endl;
		cout << "2.���һ��Ԫ��" << endl;
		cout << "3.ǰ���һ��Ԫ��" << endl;
		cout << "4.ɾ����һ��Ԫ��" << endl;
		cout << "5.ɾ�����һ��Ԫ��" << endl;
		cout << "6.����Ԫ��" << endl;
		cout << "7.ɾ��Ԫ��" << endl;
		cout << "8.�������" << endl;
		cout << "9.����Ԫ��" << endl;
		cout << "a.Ԫ�ظ���" << endl;
		cout << "b.��ӡ����" << endl;
		cout << "c.�����㷨������" << endl;
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
		cout << "1.������ת" << endl;
		cout << "2.�ݹ鷴ת" << endl;
		cout << "3.�����л�" << endl;
		cout << "4.ż�ڵ㷴ת" << endl;
		cout << "5.�м�ڵ�" << endl;
		cout << "6.��ӡ����" << endl;
		cout << "0.����" << endl;
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
			cout << "��ѡ��: ";
		cin >> i;
		switch (i) 
		{
		case '1':isForward = true; Loop = false; break;
		case '2':isForward = false; Loop = false; break;
		default:Loop = true;
		}
	
		if (Loop)
			cout << "�밴ѡ��ѡ��: ";
	} while (Loop);
	
}

void menu::select_2()
{
	char i;
	bool Loop = false;
	do
	{
		if (Loop == false)
			cout << "��ѡ��: ";
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
			cout << "�밴ѡ��ѡ��: ";
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
			cout << "����Ϊ��" << endl;
		else
			cout << "��һ��Ԫ��Ϊ" << temp.front() << endl; 
		break;
	}
	case'2':
	{
		if (temp.head == NULL)
			cout << "����Ϊ��" << endl;
		else
			cout << "���һ��Ԫ��Ϊ" << temp.back() << endl; 
		break;
	}
	case'3': {
		cout << "������Ԫ��" << endl;
		if (temp.push_front(temp.CreatFill()))
			cout << "������" << endl;
		else
			cout << "���ʧ��" << endl;
		break;
	}
	case'4': {
		if (temp.pop_front())
			cout << "ɾ���ɹ�" << endl;
		else
			cout << "ɾ��ʧ��" << endl;
		break;
	}
	case'5': {
		if (temp.head == NULL)cout << "������Ϊ��" << endl;
		if (temp.pop_back())cout << "ɾ���ɹ�" << endl;
		else cout << "ɾ��ʧ��" << endl;
		break;
	}
	case'6': {
		int a, num = temp.size();
		cout << "�ڵ㹲" << num << "������ϣ�������Ԫ���ǵڼ����ڵ㣺";
		bool Loop_1 = true;
		do {
			cin >> a;
			if (a >= 1 && a <= num + 1)
				Loop_1 = false;
			if (Loop_1 == true)
				cout << "���������" << endl;
		} while (Loop_1);
		cout << "������Ԫ��" << endl;
		if (temp.insert(a, temp.CreatFill()))
			cout << "�������" << endl;
		else
			cout << "����ʧ��" << endl;
		break;
	}
	case'7': {
		int a, num = temp.size();
		cout << "�ڵ㹲" << num << "������ϣ��ɾ����Ԫ���ǵڼ����ڵ㣺";
		bool Loop_1 = true;
		do {
			cin >> a;
			if (a >= 1 && a <= num)
				Loop_1 = false;
			if (Loop_1 == true)
				cout << "���������" << endl;
		} while (Loop_1);
		if (temp.erase(a))
			cout << "ɾ�����" << endl;
		else cout << "ɾ��ʧ��" << endl;
		break;
	}
	case'8': {
		if (temp.head == NULL)
			cout << "������Ϊ��" << endl;
		else {
			temp.clear();
			cout << "������" << endl;
		}
		break;
	}
	case'9': {
		cout << "������������ҵ�Ԫ�أ�";
		if (!temp.contain(temp.CreatFill()))
			cout << "δ�ҵ���Ԫ��" << endl;
		break;
	}
	case'a':cout << "��ǰ����" << temp.size() << "�ڵ�" << endl;
	case'b':temp.print(); break;
	case'c': {
		if (isForward)
			Menu_4(temp);
		else
			cout << "�������ǵ�������" << endl;
		break;
	}
	case'0':Loop=false; break;
	default:cout << "�밴ѡ������" << endl;
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
			cout << "��ת���" << endl;
		else
			cout << "��תʧ��" << endl;
		break;
	}
	case'2': {
		if(temp.size()!=1)
			temp.reverse_2(temp.head);
		cout << "��ת���" << endl;
		break;
	}
	case'3': {
		if (temp.isLoop())
			cout << "������ɻ�" << endl;
		else
			cout << "�������ɻ�" << endl;
		break;
	}
	case'4': {
		if (temp.reverseEven())
			cout << "��ת���" << endl;
		else
			cout << "��תʧ��" << endl;
		break;
	}
	case'5':cout << "�м�ڵ�Ϊ" << temp.middleElem().data << endl; break;
	case'6':temp.print(); break;
	case'0':Loop = false;break;
	default:cout << "�밴ѡ������" << endl;
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