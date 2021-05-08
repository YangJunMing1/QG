#include "qgsort.h"

void insertSort(int* a, int n)
{
	if (n == 1)
		return;
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (temp <= a[j])
				a [j+1] = a[j];
			else
			{
				a[j+1] = temp;
				break;
			}
		}
	}
}

void MergeArray(int* a, int begin, int end)
{
	if (begin <end)
	{
		int mid = (begin + end) / 2;
		MergeArray(a, begin, mid);		//左半部排序
		MergeArray(a, mid + 1, end);		//右半部排序
		MergeSort(a, begin, mid, end);
	}
}

void MergeSort(int* a, int begin,int mid, int end)
{
	/* 合并 */
	int* temp = new int[end-begin+1];	//临时数组
	int m = mid++;
	int k = 0;
	while (begin <= m && mid <= end)
	{
		if (a[begin] < a[mid])
			temp[k++] = a[begin++];
		else
			temp[k++] = a[mid++];
	}
	while (begin <= m)
		temp[k++] = a[begin++];
	while (mid <= end)
		temp[k++] = a[mid++];
	for (int i = k - 1; i >= 0; --i, --end)
		a[end] = temp[i];
	delete[]temp;				//归还空间
}

void QuickSort_Recursion(int* a, int begin, int end)
{
	if (begin < end)
	{
		int mid = Partition(a, begin, end);
		QuickSort_Recursion(a, begin, mid - 1);		//前半段
		QuickSort_Recursion(a, mid + 1,end);		//后半段
	}
}

void QuickSort(int* a, int size)
{
	;
}

int Partition(int* a, int begin, int end)
{
	int key=a[begin];		//基准
	int i=begin, j=end;		//指针
	while (i < j)
	{
		while (i < j && a[j] >= key)j--;	//从右边找出比基准小的数所在位置
		if (i < j)
			a[i] = a[j];
		while (i < j && a[i] <= key)i++;	//从左找比基准小的
		if (i < j)
			a[j] = a[i];
	}
	a[i] = key;		//将基准放在中轴
	return i;		//返回中轴所在位置
}

void CountSort(int* a, int size, int max)
{
	int i,p;							//i主要用于遍历数组，p作为a数组下标
	int* num = new int[max+1];			//记数数组
	for (i = 0; i < max + 1; i++)		//初始化记数数组
		num[i] = 0;

	for (i = 0; i < size; i++)			//记数
		num[a[i]]++;

	for (i = p = 0; i < max + 1; i++)		
	{
		int k;
		for (k = 0; k < num[i]; k++,p++)		//k用于计当前数据有无输入完
			a[p] = i;
	}
	delete[]num;
}

void RadixCountSort(int* a, int size)
{
	int(* temp)[200000] = new int[10][200000];	//创建桶
	int i,j,y;			//主要用于遍历数组
	int max = a[0];
	for (i = 0; i < size; i++)		//找出最大值
	{
		if (max < a[i])
			max = a[i];
	}
	int k,t;				//根据最大值的位数，确定计数排列次数k。t用于取得位数
	for (k = 0; max; max /= 10, k++);

	for (k,t=1; k > 0; k--,t*=10)
	{
		int temp_num[10] = { 0 };			//桶内元素数目,初始化为0。如temp_num[1]=2，指temp[1]中有2个元素(为temp[1][0],temp[1][1])

		for (i = 0; i < size; i++)			//存放
		{
			temp[a[i] / t % 10][temp_num[a[i] / t % 10]] = a[i];	//将a[i]存放到temp[当前位数][第几个元素]里面
			temp_num[a[i] / t % 10]++;
		}

		for (i = 0,y=0; i < 10; i++)	//取出
			for (j = 0; j < temp_num[i]; j++)
			{
				a[y] = temp[i][j];
				temp[i][j] = 0;
				y++;
			}
	}

	delete []temp;	//归还内存
}

void ColorSort(int* a, int size)
{
	int i,temp;		//i遍历数组,temp交换时的中间变量
	int r=0, b = size - 1;	//头尾指针
	for (i = 0; i < b; i++)
	{
		if (a[i] == 2)
		{
			temp = a[i];
			a[i] = a[b];
			a[b] = temp;
			b--;
		}
		if (a[i] == 0)
		{
			temp = a[i];
			a[i] = a[r];
			a[r] = temp;
			r++;
		}
	}
}

int Find_KMax(int* a, int begin,int end,int K)
{
		int p = Partition(a, begin, end);
		if (p + 1 == K)return p;
		else if (p  < K-1)return Find_KMax(a, p+1 , end, K );
		else return Find_KMax(a, begin, p - 1, K);

}

int Find_KMin(int* a, int begin, int end, int K)
{
	int p = Partition(a, begin, end);
	if (p - begin + 1 == K)return p;
	else if (p - begin + 1 > K)return Find_KMin(a, p + 1, end, K - (p - begin + 1));
	else return Find_KMax(a, begin, p - 1, K);

}