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

	LinkStackPtr top;			//ͷָ��
	int	count;
	bool init;			//�Ƿ��ѳ�ʼ��

	//��ջ
	St();				//��������ջ
	~St();
	bool initLStack();//��ʼ��ջ
	bool isEmptyLStack();//�ж�ջ�Ƿ�Ϊ��
	bool getTopLStack();//�õ�ջ��Ԫ��
	bool clearLStack();//���ջ
	bool destroyLStack();//����ջ
	bool LStackLength();//���ջ����
	bool pushLStack();//��ջ
	bool popLStack();//��ջ
	void print();//��ӡ
};

/*�����Ա����*/
template<class ElemType>
St<ElemType>::St()
{
	int count = 0;							//����
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
bool St<ElemType>::initLStack()//��ʼ��ջ
{
	LinkStackPtr p;							//��β��ͷ������
	ElemType temp;
	std::cin >> temp;
	while (FillReview(temp))					//���������Ƿ�Ϊ0
	{
		p = new StackNode;
		p->data = temp;
		if (top == NULL)					//���topΪ�գ�˵����ʱ�ڵ�Ϊβ�ڵ㣬��ýڵ��next����
			p->next = nullptr;
		else								//�������ʱ�ڵ��ָ����һ�ڵ㣨top��ʱ���ڽڵ㣩
			p->next = top;
		top = p;				
		count++;							//����
		std::cin >> temp;
	}
	p = nullptr;							//���տ���ָ��
	init = true;
	return true;
}

template<class ElemType>
bool St<ElemType>::isEmptyLStack()//�ж�ջ�Ƿ�Ϊ��
{
	if (top == NULL)
		return true;
	else
		return false;
}

template<class ElemType>
bool  St<ElemType>::getTopLStack()//�õ�ջ��Ԫ��
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
bool St<ElemType>::clearLStack()//���ջ
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
bool  St<ElemType> :: destroyLStack()//����ջ
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
	std::cout << "��ǰջ��"<<count << std::endl;
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
		p->next = top;				//�нڵ�
	else
		p->next = nullptr;			//û�нڵ㣬��next���
	top = p;
	return true;
}

template<class ElemType>
bool St<ElemType>::popLStack()//��ջ
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
		std::cout << "��ǰջΪ��ջ" << std::endl;
	LinkStackPtr p;
	for (p = top; p; p = p->next)
		std::cout << p->data<<"   ";
	std::cout << std::endl;

}

