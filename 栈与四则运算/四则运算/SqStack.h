#include<iostream>

template<class ElemType>
class Sh {
public:
	bool init;			//是否已初始化

//private:
	ElemType* elem;
	int top;
	int size;
	bool isdestroy;		//栈被摧毁(空间已归还)，用于析构函数和销毁栈函数

public:
	//基于数组的顺序栈
	Sh(int sizes);		//创建空栈（无数据）
	~Sh();//销毁栈(防止关闭程序前没有选择销毁对象归还空间)		
	bool initStack();//初始化栈，填入数据
	bool isEmptyStack();//判断栈是否为空
	ElemType getTopStack(); //得到栈顶元素
	bool clearStack();//清空栈
	bool destroyStack();//销毁栈
	bool stackLength();//检测栈长度
	bool pushStack(ElemType data);//入栈
	bool popStack();//出栈
	void print();//打印
	void print_size();
};


/*类成员函数的定义*/
template<class ElemType>
Sh<ElemType>::Sh(int sizes) :size(sizes)
{
	elem = new ElemType[size];
	top = -1;
	isdestroy = false;
	init = false;
}

template<class ElemType>
Sh<ElemType>::~Sh()
{
	if (!isdestroy)
		 delete[] elem;
}

template<class ElemType>
bool Sh<ElemType>::initStack()
{
	while (top < size-1)
		std::cin >> elem[++top];
	init = true;
	return true;
}

template<class ElemType>
bool Sh<ElemType>::isEmptyStack()
{
	if (top != -1)
		return false;
	else
		return true;
}

template<class ElemType>
ElemType Sh<ElemType>::getTopStack()
{
		return elem[top];
}

template<class ElemType>
bool Sh<ElemType>::clearStack()
{
	top = -1;
	return true;
}

template<class ElemType>
bool Sh<ElemType>::destroyStack()
{
	if (!isdestroy)
	{
		delete[]elem;
		top = -1;
		isdestroy = true;
		return true;
	}
	else
		return false;
}

template<class ElemType>
bool Sh<ElemType>::stackLength()
{
	std::cout << "当前栈长：" << top + 1 << std::endl;
	return true;
}

template<class ElemType>
bool Sh<ElemType>::pushStack(ElemType data)
{
	if (top < size-1)
	{
		elem[++top] = data;
		return true;
	}
	else
		return false;

}

template<class ElemType>
bool Sh<ElemType>::popStack()
{
	if (top != -1)
	{
		top--;
		return true;
	}
	else
		return false;
}

template<class ElemType>
void Sh<ElemType>::print()
{
	if (top == -1)
		std::cout << "当前栈为空" << std::endl;
	int p = top;
	while (p != -1)
		std::cout << elem[p--]<<" ";
	std::cout << std::endl;
}

template<class ElemType>
void Sh<ElemType>::print_size()
{
	std::cout << size << std::endl;
}

