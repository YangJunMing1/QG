#include "DataFill.h"


void DataFill::Creatdata(int* a, int size)
{
	int i;
	std::cout << "�����봴���ļ����ļ�����ֻ����Ϊ.txt�ļ���" << std::endl;
	std::string Fill_name;
	std::getline(std::cin, Fill_name);
	std::ofstream outfile(".//data//"+Fill_name+".txt", std::ios::trunc);
	for (i = 0; i < size; i++)
	{
		a[i] = rand();
		outfile << a[i] << " ";
	}
}



void DataFill::Creatdata_Color(int* a, int size,std::string Fill_name)
{
	int i;

	std::ofstream outfile(".//data//" + Fill_name + ".txt", std::ios::trunc);
	for (i = 0; i < size; i++)
	{
		a[i] = (rand() % (2 + 1)) + 0;
		
		outfile << a[i] << " ";
	}
}

bool DataFill::Getdata(int* a, int &size,std::string FillName)
{
	std::ifstream infile;
	infile.open(".//data//" + FillName + ".txt", std::ios::in);
	if (!infile.is_open())
	{
		std::cout << "�ļ���ʧ�ܣ������ļ�������" << std::endl;
		return false;
	}
	size = 0;
	int i = 0;
	while (!infile.eof())
	{
		infile >> a[i];
		i++;
		size++;
	}
}

void DataFill::Savedata(int* a, int size,int diff, std::string FillName,std::string method)
{
	std::ofstream outfile(".//sort_data//" + FillName + "_Sdata.txt", std::ios::app);
	int i;
	outfile << method << "  ��ʱ��" << diff << "ms\n";
	for (i = 0; i < size; i++)
	{
		outfile << a[i] << " ";
	}
	outfile << "\n\n";
	outfile.close();
}