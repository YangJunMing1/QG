#include "DataFill.h"
class Menu
{
public:
	void menu();
	
	void select(bool& loop);

	char correct(char a, char b);

	int a[200000];
	int size;
	int max;	//���ڼ�������
	DataFill fill;
};

