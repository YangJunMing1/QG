#include<iostream>
#include "FillReview.h"

template<class ElemType>
class St
{
public:
	typedef struct StackNode
	{
		ElemType data;
		struct StackNode* next;
	}StackNode, * LinkStackPtr;

	LinkStackPtr top;			//头指针
	int	count;
	bool init;			//是否已初始化

	//链栈
	St();				//创建空链栈
	~St();
	bool initLStack();//初始化栈
	bool isEmptyLStack();//判断栈是否为空
	bool getTopLStack();//得到栈顶元素
	bool clearLStack();//清空栈
	bool destroyLStack();//销毁栈
	bool LStackLength();//检测栈长度
	bool pushLStack();//入栈
	bool popLStack();//出栈
	void print();//打印
};

/*定义成员函数*/
template<class ElemType>
St<ElemType>::St()
{
	int count = 0;							//记数
	top = nullptr;
	init = false;
}

template<class ElemType>
St<ElemType>::~St()
{
	if (top != NULL)
	{
		LinkStackPtr p;
		for (p = top; p; p = p->next)
		{
			delete p;
			count--;
		}
	}
}


template<class ElemType>
bool St<ElemType>::initLStack()//初始化栈
{
	LinkStackPtr p;							//从尾往头部创建
	ElemType temp;
	std::cin >> temp;
	while (FillReview(temp))					//分析输入是否为0
	{
		p = new StackNode;
		p->data = temp;
		if (top == NULL)					//如果top为空，说明此时节点为尾节点，令该节点的next悬空
			p->next = nullptr;
		else								//否则，另此时节点的指向下一节点（top此时所在节点）
			p->next = top;
		top = p;				
		count++;							//记数
		std::cin >> temp;
	}
	p = nullptr;							//悬空开辟指针
	init = true;
	return true;
}

template<class ElemType>
bool St<ElemType>::isEmptyLStack()//判断栈是否为空
{
	if (top == NULL)
		return true;
	else
		return false;
}

template<class ElemType>
bool  St<ElemType>::getTopLStack()//得到栈顶元素
{
	if (top != NULL)
	{
		std::cout << top->data << std::endl;
		return true;
	}
	else
		return false;
}

template<class ElemType>
bool St<ElemType>::clearLStack()//清空栈
{
	if (top != NULL)
	{
		LinkStackPtr p;
		for (p = top; top; p = top)
		{
			top = top->next;
			delete p;
			count--;
		}
		return true;
	}
	else
		return false;
}

template<class ElemType>
bool  St<ElemType> :: destroyLStack()//销毁栈
{
	if (top != NULL)
	{
		LinkStackPtr p;
		for (p = top; top; p= top)
		{
			top = top->next;
			delete p;
			count--;
		}
		return true;
	}
	else
		return false;

}

template<class ElemType>
bool  St<ElemType>::LStackLength()
{
	std::cout << "当前栈长"<<count << std::endl;
	return true;
}

template<class ElemType>
bool St<ElemType>::pushLStack()
{
	ElemType temp;
	std::cin >> temp;
	LinkStackPtr p=new StackNode;
	p->data = temp;
	if (top != NULL)			
		p->next = top;				//有节点
	else
		p->next = nullptr;			//没有节点，则next设空
	top = p;
	return true;
}

template<class ElemType>
bool St<ElemType>::popLStack()//出栈
{
	if (top == NULL)
		return false;
	LinkStackPtr p;
	p = top;
	top = top->next;
	delete p;
	count--;
	p = nullptr;
	return true;
}

template<class ElemType>
void St<ElemType>::print()
{
	if (top == NULL)
		std::cout << "当前栈为空栈" << std::endl;
	LinkStackPtr p;
	for (p = top; p; p = p->next)
		std::cout << p->data<<"   ";
	std::cout << std::endl;

}

