#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<iostream>

template<class ElemType>
class Sh {
public:
	bool init;			//�Ƿ��ѳ�ʼ��

private:
	ElemType* elem;
	int top;
	int size;
	bool isdestroy;		//ջ���ݻ�(�ռ��ѹ黹)��������������������ջ����

public:
	//���������˳��ջ
	Sh(int sizes);		//������ջ�������ݣ�
	~Sh();//����ջ(��ֹ�رճ���ǰû��ѡ�����ٶ���黹�ռ�)		
	bool initStack();//��ʼ��ջ����������
	bool isEmptyStack();//�ж�ջ�Ƿ�Ϊ��
	bool getTopStack(); //�õ�ջ��Ԫ��
	bool clearStack();//���ջ
	bool destroyStack();//����ջ
	bool stackLength();//���ջ����
	bool pushStack();//��ջ
	bool popStack();//��ջ
	void print();//��ӡ
	void print_size();
};


/*���Ա�����Ķ���*/
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
bool Sh<ElemType>::getTopStack()
{
	if (top != -1)
	{
		std::cout << elem[top]<<std::endl;
		return true;
	}
	else
		return false;
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
	std::cout << "��ǰջ����" << top + 1 << std::endl;
	return true;
}

template<class ElemType>
bool Sh<ElemType>::pushStack()
{
	if (top < size-1)
	{
		std::cout << "������" << std::endl;
		ElemType data;
		std::cin >> data;
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
		std::cout << "��ǰջΪ��" << std::endl;
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
#endif 
