#include "Menu.h"
#define DATA_1 10000
#define DATA_2 50000
#define DATA_3 200000

void Menu::menu()
{
	bool loop=true;
	do
	{
		std::cout << "1����ָ���������ļ�" << std::endl;
		std::cout << "2-�����ݲ���" << std::endl;
		std::cout << "3-С���ݲ���" << std::endl;
		std::cout << "4-��ɫ����" << std::endl;
		std::cout << "5-���ҵ�K��" << std::endl;
		std::cout << "6-���ҵ�KС" << std::endl;
		std::cout << "0-exit" << std::endl;
		select(loop);
	} while (loop);

}

void Menu::select(bool &loop)
{
	char ch = correct('0', '6');
	switch (ch)
	{
	case'1': {
		
		std::cout << "��ѡ�����ݸ���" << std::endl;
		std::cout << "1-10000" << std::endl;
		std::cout << "2-50000" << std::endl;
		std::cout << "3-200000" << std::endl;
		char Ch = correct('1', '3');
		if (Ch == '1')
			size = DATA_1;
		else if (Ch == '2')
			size = DATA_2;
		else
			size = DATA_3;
		int* a = new int[size];
		fill.Creatdata(a, size);
		std::cout << "������������data�ļ�����" << std::endl;
		break;
	}
	case'2': {
		int i;
		std::string FillName;
		std::cout << "�������������ļ���(���������׺��)��";
		getline(std::cin, FillName);
		if (!fill.Getdata(a, size, FillName))
			break;

		int start,diff;		//��ʱ
		std::cout << "��ǰ���ݹ�ģ��" << size-1 << std::endl;
		std::cout << "������" << std::endl;

		fill.Getdata(a, size, FillName);
		start = (int)GetTickCount64();
		insertSort(a, size);
		diff = (int)GetTickCount64() - start;
		std::cout << "����������ʱ" << diff << "ms" << std::endl;
		fill.Savedata(a, size, diff,FillName, "��������");


		fill.Getdata(a, size, FillName);
		start = (int)GetTickCount64();
		MergeArray(a, 0, size - 1);
		diff = (int)GetTickCount64() - start;
		std::cout << "�鲢������ʱ" << diff << "ms" << std::endl;
		fill.Savedata(a, size, diff,FillName, "�鲢����");

		fill.Getdata(a, size, FillName);
		start = (int)GetTickCount64();
		RadixCountSort(a, size );
		diff = (int)GetTickCount64() - start;
		std::cout << "����������ʱ" << diff << "ms" << std::endl;
		fill.Savedata(a, size, diff, FillName, "��������");

		fill.Getdata(a, size, FillName);
		 max = a[0];
		for (i = 0; i < size; i++)
			if (a[i] > max)
				max = a[i];
		start = (int)GetTickCount64();
		CountSort(a, size, max);
		diff = (int)GetTickCount64() - start;
		std::cout << "����������ʱ" << diff << "ms" << std::endl;
		fill.Savedata(a, size,diff, FillName, "��������");

		fill.Getdata(a, size, FillName);
		start = (int)GetTickCount64();
		QuickSort_Recursion(a, 0, size - 1);
		diff = (int)GetTickCount64() - start;
		std::cout << "�������򣨵ݹ飩��ʱ" << diff << "ms" << std::endl;
		fill.Savedata(a, size,diff, FillName, "��������");

		std::cout << "�������򣨷ǵݹ飩��ʱ  " << "������Ϊ���" << std::endl;

		std::cout << "���к�������ѱ�����" << FillName + "_Sdata.txt������sort_data�ļ�����ѫ��" << std::endl;
		break;

	}
	case'3': {
		int i,j;
		int start, diff;
		std::string FillName;
		std::cout << "�������������ļ���(���������׺��)��";
		getline(std::cin, FillName);
		if (!fill.Getdata(a, size, FillName))
			break;
		system("cls");
		std::cout << "��ǰ���ݹ�ģ:" << size / 100 << "*100" << std::endl;
		int Time ;		//TimeΪ��ʱ��
		int t[2000] = {0};
		
		std::ifstream infile;
		std::ofstream outfile;
		outfile.open(FillName + "_Time.txt", std::ios::app);
		infile.open(FillName + ".txt", std::ios::in);
		for (Time=0,i = 0; i < 100; i++)		//100��С����
		{
			for (j = 0; j < size / 100; j++)
				infile >> t[j];
			start = (int)GetTickCount64();
			insertSort(t, size/100);
			diff = (int)GetTickCount64() - start;
			Time += diff;
		}
		std::cout << "�������� ����ʱ��" << Time << "ms" << std::endl;
		outfile << "�������� ����ʱ��" << Time <<"ms"<< "\n";
		infile.close();

		infile.open(FillName + ".txt", std::ios::in);
		for (Time=0,i = 0; i < 100; i++)		//100��С����
		{
			for (j = 0; j < size / 100; j++)
				infile >> t[j];
			start = (int)GetTickCount64();
			RadixCountSort(t, size/100);
			diff = (int)GetTickCount64() - start;
			Time += diff;
		}
		std::cout<< "������������ ����ʱ��" << Time << "ms" << std::endl;
		outfile << "������������ ����ʱ��" << Time << "ms" << "\n";
		infile.close();


		infile.open(FillName + ".txt", std::ios::in);
		for (Time=0,i = 0; i < 100; i++)		//100��С����
		{
			for (j = 0; j < size / 100; j++)
				infile >> t[j];
			start = (int)GetTickCount64();
			MergeArray(t, 0, size/100 - 1);
			diff = (int)GetTickCount64() - start;
			Time += diff;
		}
		std::cout << "�鲢���� ����ʱ��" << Time << "ms" << std::endl;
		outfile << "�鲢���� ����ʱ��" << Time << "ms" << "\n";
		infile.close();

		infile.open(FillName + ".txt", std::ios::in);
		for (Time = 0, i = 0; i < 100; i++)		//100��С����
		{
			for (j = 0; j < size / 100; j++)
			{
				infile >> t[j];
				if(j==0)
					max = t[0];
				if (t[j] > max)
					max = t[j];
			}
			start = (int)GetTickCount64();
			CountSort(t, size/100, max);
			diff = (int)GetTickCount64() - start;
			Time += diff;
		}
		std::cout << "�������� ����ʱ��" << Time << "ms" << std::endl;
		outfile << "�������� ����ʱ��" << Time << "ms" << "\n";
		infile.close();
		outfile.close();
		std::cout << "��¼�ѱ�����" << FillName << ".txt" << "��" << FillName << "Time.txt��" << std::endl;
		break;
	}
	case'4': {
		int start, diff;		//��ʱ
		std::string r;		//�����س�
		int length = 0;			//����
		std::cout << "���������鳤��(ע��:�����ݹ��࣬���л������)��" << std::endl;
		std::cin >> length;
		getline(std::cin, r);
		std::cout << "�������ļ�����ֻ����Ϊ.txt�ļ���" << std::endl;
		std::string Fill_name;
		std::getline(std::cin, Fill_name);
		fill.Creatdata_Color(a, length,Fill_name);
		start = (int)GetTickCount64();
		ColorSort(a, length);
		diff = (int)GetTickCount64() - start;
		std::cout << "��ɫ������ʱ" << diff << "ms" << std::endl;
		fill.Savedata(a, length,diff, Fill_name,"��ɫ����");
		std::cout << "���к�������ѱ�����" << Fill_name + "_Sdata.txt" << std::endl;
		break;
	}
	case'5': {
		int K,i;
		std::string r;		//�����س�
		int length = 0;			//����
		std::cout << "���������鳤�ȣ�" << std::endl;
		std::cin >> length;
		getline(std::cin, r);
		fill.Creatdata(a, length);
		for (i = 0; i < length; i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
		std::cout << "ϣ�����������ǵڼ���" << std::endl;
		do {
			std::cin >> K;
			if (K<0 || K>length)
				std::cout << "���������Χ" << std::endl;
		} while (K > length || K < 0);

		std::cout << "��" << K << "������ǣ�" << a[Find_KMax(a, 0, length - 1, K)] << std::endl;
		break;
	}
	case'6': {
		int K,i;
		std::string r;		//�����س�
		int length = 0;			//����
		std::cout << "���������鳤�ȣ�" << std::endl;
		std::cin >> length;
		getline(std::cin, r);
		fill.Creatdata(a, length);
		for (i = 0; i < length; i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
		std::cout << "ϣ�����������ǵڼ�С��" << std::endl;
		do {
			std::cin >> K;
			if (K<0 || K>length)
				std::cout << "���������Χ" << std::endl;
		} while (K > length|| K < 0);
		std::cout<<"��"<<K<<"С�����ǣ�"<<a[Find_KMin(a, 0, length - 1, K)]<<std::endl; 
		break;
	}
	case'0':loop = false;break;
	}
	system("pause");
	system("cls");
}

char Menu::correct(char a,char b)
{
	char temp;	
	std::string r;
	std::cout << "������ѡ�";
	bool loop = false;
	std::cin >> temp;
	getline(std::cin, r);	//�����س�
	do
	{
		if (temp<a || temp>b)
			loop = true;
		if (loop)
		{
			std::cout << "���������" << std::endl;
			std::cin >> temp;
			std::cin >> r;	//�����س�
		}

	} while (loop);
	return temp;
}