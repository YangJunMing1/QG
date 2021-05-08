#include "Menu.h"
#define DATA_1 10000
#define DATA_2 50000
#define DATA_3 200000

void Menu::menu()
{
	bool loop=true;
	do
	{
		std::cout << "1生成指定数据与文件" << std::endl;
		std::cout << "2-大数据测试" << std::endl;
		std::cout << "3-小数据测试" << std::endl;
		std::cout << "4-颜色排序" << std::endl;
		std::cout << "5-查找第K大" << std::endl;
		std::cout << "6-查找第K小" << std::endl;
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
		
		std::cout << "请选择数据个数" << std::endl;
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
		std::cout << "数据已生成于data文件夹中" << std::endl;
		break;
	}
	case'2': {
		int i;
		std::string FillName;
		std::cout << "输入数据所在文件名(不用输入后缀名)：";
		getline(std::cin, FillName);
		if (!fill.Getdata(a, size, FillName))
			break;

		int start,diff;		//计时
		std::cout << "当前数据规模：" << size-1 << std::endl;
		std::cout << "排序中" << std::endl;

		fill.Getdata(a, size, FillName);
		start = (int)GetTickCount64();
		insertSort(a, size);
		diff = (int)GetTickCount64() - start;
		std::cout << "插入排序用时" << diff << "ms" << std::endl;
		fill.Savedata(a, size, diff,FillName, "插入排序");


		fill.Getdata(a, size, FillName);
		start = (int)GetTickCount64();
		MergeArray(a, 0, size - 1);
		diff = (int)GetTickCount64() - start;
		std::cout << "归并排序用时" << diff << "ms" << std::endl;
		fill.Savedata(a, size, diff,FillName, "归并排序");

		fill.Getdata(a, size, FillName);
		start = (int)GetTickCount64();
		RadixCountSort(a, size );
		diff = (int)GetTickCount64() - start;
		std::cout << "基数排序用时" << diff << "ms" << std::endl;
		fill.Savedata(a, size, diff, FillName, "基数排序");

		fill.Getdata(a, size, FillName);
		 max = a[0];
		for (i = 0; i < size; i++)
			if (a[i] > max)
				max = a[i];
		start = (int)GetTickCount64();
		CountSort(a, size, max);
		diff = (int)GetTickCount64() - start;
		std::cout << "计数排序用时" << diff << "ms" << std::endl;
		fill.Savedata(a, size,diff, FillName, "计数排序");

		fill.Getdata(a, size, FillName);
		start = (int)GetTickCount64();
		QuickSort_Recursion(a, 0, size - 1);
		diff = (int)GetTickCount64() - start;
		std::cout << "快速排序（递归）用时" << diff << "ms" << std::endl;
		fill.Savedata(a, size,diff, FillName, "快速排序");

		std::cout << "快速排序（非递归）用时  " << "代码尚为完成" << std::endl;

		std::cout << "排列后的数据已保存在" << FillName + "_Sdata.txt，请在sort_data文件夹中勋章" << std::endl;
		break;

	}
	case'3': {
		int i,j;
		int start, diff;
		std::string FillName;
		std::cout << "输入数据所在文件名(不用输入后缀名)：";
		getline(std::cin, FillName);
		if (!fill.Getdata(a, size, FillName))
			break;
		system("cls");
		std::cout << "当前数据规模:" << size / 100 << "*100" << std::endl;
		int Time ;		//Time为总时长
		int t[2000] = {0};
		
		std::ifstream infile;
		std::ofstream outfile;
		outfile.open(FillName + "_Time.txt", std::ios::app);
		infile.open(FillName + ".txt", std::ios::in);
		for (Time=0,i = 0; i < 100; i++)		//100个小数组
		{
			for (j = 0; j < size / 100; j++)
				infile >> t[j];
			start = (int)GetTickCount64();
			insertSort(t, size/100);
			diff = (int)GetTickCount64() - start;
			Time += diff;
		}
		std::cout << "插入排序 总用时：" << Time << "ms" << std::endl;
		outfile << "插入排序 总用时：" << Time <<"ms"<< "\n";
		infile.close();

		infile.open(FillName + ".txt", std::ios::in);
		for (Time=0,i = 0; i < 100; i++)		//100个小数组
		{
			for (j = 0; j < size / 100; j++)
				infile >> t[j];
			start = (int)GetTickCount64();
			RadixCountSort(t, size/100);
			diff = (int)GetTickCount64() - start;
			Time += diff;
		}
		std::cout<< "基数计数排序 总用时：" << Time << "ms" << std::endl;
		outfile << "基数计数排序 总用时：" << Time << "ms" << "\n";
		infile.close();


		infile.open(FillName + ".txt", std::ios::in);
		for (Time=0,i = 0; i < 100; i++)		//100个小数组
		{
			for (j = 0; j < size / 100; j++)
				infile >> t[j];
			start = (int)GetTickCount64();
			MergeArray(t, 0, size/100 - 1);
			diff = (int)GetTickCount64() - start;
			Time += diff;
		}
		std::cout << "归并排序 总用时：" << Time << "ms" << std::endl;
		outfile << "归并排序 总用时：" << Time << "ms" << "\n";
		infile.close();

		infile.open(FillName + ".txt", std::ios::in);
		for (Time = 0, i = 0; i < 100; i++)		//100个小数组
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
		std::cout << "计数排序 总用时：" << Time << "ms" << std::endl;
		outfile << "计数排序 总用时：" << Time << "ms" << "\n";
		infile.close();
		outfile.close();
		std::cout << "记录已保存在" << FillName << ".txt" << "与" << FillName << "Time.txt中" << std::endl;
		break;
	}
	case'4': {
		int start, diff;		//计时
		std::string r;		//消化回车
		int length = 0;			//长度
		std::cout << "请输入数组长度(注意:若数据过多，排列会有误差)：" << std::endl;
		std::cin >> length;
		getline(std::cin, r);
		std::cout << "请输入文件名（只保存为.txt文件）" << std::endl;
		std::string Fill_name;
		std::getline(std::cin, Fill_name);
		fill.Creatdata_Color(a, length,Fill_name);
		start = (int)GetTickCount64();
		ColorSort(a, length);
		diff = (int)GetTickCount64() - start;
		std::cout << "颜色排序用时" << diff << "ms" << std::endl;
		fill.Savedata(a, length,diff, Fill_name,"颜色排序");
		std::cout << "排列后的数据已保存在" << Fill_name + "_Sdata.txt" << std::endl;
		break;
	}
	case'5': {
		int K,i;
		std::string r;		//消化回车
		int length = 0;			//长度
		std::cout << "请输入数组长度：" << std::endl;
		std::cin >> length;
		getline(std::cin, r);
		fill.Creatdata(a, length);
		for (i = 0; i < length; i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
		std::cout << "希望所找数据是第几大：" << std::endl;
		do {
			std::cin >> K;
			if (K<0 || K>length)
				std::cout << "请输入合理范围" << std::endl;
		} while (K > length || K < 0);

		std::cout << "第" << K << "大的数是：" << a[Find_KMax(a, 0, length - 1, K)] << std::endl;
		break;
	}
	case'6': {
		int K,i;
		std::string r;		//消化回车
		int length = 0;			//长度
		std::cout << "请输入数组长度：" << std::endl;
		std::cin >> length;
		getline(std::cin, r);
		fill.Creatdata(a, length);
		for (i = 0; i < length; i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
		std::cout << "希望所找数据是第几小：" << std::endl;
		do {
			std::cin >> K;
			if (K<0 || K>length)
				std::cout << "请输入合理范围" << std::endl;
		} while (K > length|| K < 0);
		std::cout<<"第"<<K<<"小的数是："<<a[Find_KMin(a, 0, length - 1, K)]<<std::endl; 
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
	std::cout << "请输入选项：";
	bool loop = false;
	std::cin >> temp;
	getline(std::cin, r);	//消化回车
	do
	{
		if (temp<a || temp>b)
			loop = true;
		if (loop)
		{
			std::cout << "请合理输入" << std::endl;
			std::cin >> temp;
			std::cin >> r;	//消化回车
		}

	} while (loop);
	return temp;
}