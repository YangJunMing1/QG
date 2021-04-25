#include"Menu.h"


void Menu::Menu_1()
{
	std::cout << "��ѡ������" << std::endl;
	std::cout << "1-int" << std::endl;
	std::cout << "2-double" << std::endl;
	std::cout << "3-char" << std::endl;
	select_1();
}

void Menu::select_1()
{
	char i = correct("3");
	if (i == '1') { elem = 1; BST<int>temp; system("cls"); Menu_2(temp); }
	if (i == '2') { elem = 2; BST<double>temp; system("cls"); Menu_2(temp); }
	if (i == '3') { elem = 3; BST<char>temp; system("cls"); Menu_2(temp); }

}

template<class T>
void Menu:: Menu_2(T& temp)
{
	bool unexit=true;
	do
	{
		std::cout << "1-��������" << std::endl;
		std::cout << "2-��ѯ����" << std::endl;
		std::cout << "3-ɾ������" << std::endl;
		std::cout << "4-�������(�ݹ�)" << std::endl;
		std::cout << "5-�������(�ǵݹ�)" << std::endl;
		std::cout << "6-�������(�ݹ�)" << std::endl;
		std::cout << "7-�������(�ǵݹ�)" << std::endl;
		std::cout << "8-�������(�ݹ�)" << std::endl;
		std::cout << "9-�������(�ǵݹ�)" << std::endl;
		std::cout << "10-�������" << std::endl;
		std::cout << "0-exit" << std::endl;
		select_2(unexit,temp);
		system("pause");
		system("cls");
	} while (unexit);

}

template<class T>
void Menu::select_2(bool &unexit,T& temp)
{
	char i=(char)correct("10");

	switch (i) {
	case'1': {
		temp.BST_insert(temp.CreatData());
		break;
	}
	case'2': {
		if (temp.root == NULL)
			std::cout << "����ǰΪ��" << std::endl;
		else
			temp.BST_search_result(temp.root, temp.CreatData());

		break;
	}
	case'3': {
		if (temp.root == NULL)
			std::cout << "����ǰΪ��" << std::endl;
		else
			temp.BST_delete(temp.root, temp.CreatData());
		break;
	}
	case'4': {
		if (temp.root == NULL)
			std::cout << "����ǰΪ��" << std::endl;
		else
			temp.BST_preorderR(temp.root);
		break;
	}
	case'5': {
		if (temp.root == NULL)
			std::cout << "����ǰΪ��" << std::endl;
		else
			temp.BST_preorderI(temp.root);
		break;
	}
	case'6': {
		if (temp.root == NULL)
			std::cout << "����ǰΪ��" << std::endl;
		else
			temp.BST_inorderR(temp.root);
		break;
	}
	case'7': {
		if (temp.root == NULL)
			std::cout << "����ǰΪ��" << std::endl;
		else
			temp.BST_inorderI(temp.root);
		break;
	}
	case'8': {
		if (temp.root == NULL)
			std::cout << "����ǰΪ��" << std::endl;
		else
			temp.BST_postorderR(temp.root);
		break;
	}
	case'9': {
		if (temp.root == NULL)
			std::cout << "����ǰΪ��" << std::endl;
		else
			temp.BST_postorderI(temp.root);
		break;
	}
	case'a': {
		if (temp.root == NULL)
			std::cout << "����ǰΪ��" << std::endl;
		else
			temp.BST_levelOrder(temp.root);
		break;
	}
	case'0':unexit = false; break;
	}
}


char Menu::correct(std::string b)
{
	std::string ch;
	bool loop = false;
	do
	{
		if (loop)
			std::cout << "���������" << std::endl;
		else
			std::cout << "������:";
		std::cin >> ch;
		if (ch.size() == 1&&b.size()==1)
		{
			if (ch[0] < '0' || ch[0]>b[0])
				loop = true;
			else
				loop = false;
		}
		if (ch.size() == 1 && b.size() == 2)
		{
			if (ch[0] < '0' || ch[0]>'9')
				loop = true;
			else
				loop = false;
		}
		if (ch.size() == 2)
		{
			if (ch[0] < '0' || ch[1]>b[1])
				loop = true;
			else
				loop = false;
		}

	} while (loop);
	if (ch.size() == 1)
		return ch[0];
	else
		return ch[1] + 49;

}