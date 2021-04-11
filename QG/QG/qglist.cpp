#include"qglist.h"

template<class ElemType>
QGList<ElemType>::QGList()
{
	//Node* p1, * p2;
	//head = tail = p2 = NULL;;
	//p1 = new Node;
	//cout << "���¿�ʼ��������������'0'ʱ������������" << endl;
	//cin >> p1->data;
	//while (p1->data != 0)
	//{
	//	if (head == NULL)head = p1;
	//	else p2->next = p1;
	//	p1->prior = p2;
	//	p2 = p1;
	//	p1 = new Node;
	//	cin >> p1->data;
	//}
	//if (head == NULL) tail = NULL;
	//else
	//{
	//	tail = p2;
	//	tail->next = NULL;
	//	head->prior = NULL;
	//}
	//delete p1;								//�黹����ָ�������������ÿռ�
	//cout << "�����������" << endl;
	head = tail = NULL;
	cout << "���ڴ������������������ݵ����ͣ��������롰0������" << endl;
	ElemType a;
	ElemType& temp = a;
	cin >> temp;
	while (FillReview(temp))
	{
		push_back(temp);
		cin >> temp;
	}
}

template<class ElemType>
QGList<ElemType>::~QGList()
{
	Node* p1, * p2;							//p1ָ�븺�������p2ָ�����ڹ黹�ռ�
	if (head != NULL)
	{
		for (p1 = p2 = head; p1; p2 = p1)
		{
			p1 = p2->next;
			delete p2;
		}
		head = tail = NULL;
	}
	cout << "����ɾ���ɹ�" << endl;
}

template<class ElemType>
ElemType& QGList<ElemType>::front()
{
	return head->data;
}

template<class ElemType>
ElemType& QGList<ElemType>::back()
{
	return tail->data;
}

template<class ElemType>
bool QGList<ElemType>::push_front(ElemType e)
{

	Node* p = new Node;
	p->data = e;
	if (head == NULL)
	{
		head = tail = p;
		head->next = tail->next = NULL;
		head->prior = tail->prior = NULL;
		return true;
	}
	p->next = head;
	head->prior = p;
	head = p;
	return true;
}

template<class ElemType>
bool QGList<ElemType>::pop_front()
{
	if (head != NULL)
	{
		Node* p=head;
		head = head->next;
		head->prior = NULL;
		delete p;
		return true;
	}
	else
	{
		cout << "��δ�������������Ϊ��" << endl;
		return false;
	}

}

template<class ElemType>
bool QGList<ElemType>::push_back(ElemType e)
{

	Node* p = new Node;
	p->data = e;
	if (head == NULL)
	{
		head = tail = p;
		head->next = tail->next = NULL;
		head->prior = tail->prior = NULL;
		return true;
	}
	else 
	{
		tail->next = p;
		p->prior = tail;
		tail = p;
		tail->next = NULL;
		return true;
	}

}

template<class ElemType>
bool  QGList<ElemType>::insert(unsigned int index, ElemType e)			//��Ϊ��index���ڵ�
{
	
	if (head == NULL)
	{
		Node* p = new Node;
		p->data = e;
		head = tail = p;
		head->next = tail->next = NULL;
		head->prior = tail->prior = NULL;
		return true;
	}
	int num = size();											//��ڵ���
	if (index > num+1)
	{
		cout << "����Ŀǰ��" << num << "���ڵ㣬������0~" << num << endl;
		return false;
	}															//����Ϊ�Ż�����
	if (index == 1)												//�������Ԫ��
		push_front(e);
	else
	{
		Node* p, * p2 = new Node;								//pΪ��index���ڵ㣬p2Ϊ����ڵ�
		p2->data = e;
		int i;
		for (p = head, i = 1; i < index - 1; p = p->next, i++);	//�ҵ���index���ڵ�
		p2->next = p->next;
		p->next = p2;
	}
	return true;

}

template<class ElemType>
bool QGList<ElemType>::pop_back()
{
	if (tail != NULL)
	{
		if (head != tail)								//��ֹһ���ڵ�
		{
			Node* p;
			for (p = head; p->next != tail; p = p->next);
			delete tail;
			tail = p;
			tail->next = NULL;
			return true;
		}
		else											//ֻ��һ���ڵ�
		{
			delete tail;
			head = tail = NULL;
			return true;
		}
	}
	else
	{
		cout << "��δ�������������Ϊ��" << endl;
		return false;
	}

}


template<class ElemType>
bool QGList<ElemType>::clear()
{
	Node* p1, * p2;							
		for (p1 = p2 = head; p1; p2 = p1)
		{
			p1 = p2->next;
			delete p2;
		}
	head = tail = NULL;
	head = new Node;
	return true;
}

template<class ElemType>
bool QGList<ElemType>::erase(unsigned int index)
{
	if (head == NULL)
	{
		cout << "��δ�������������Ϊ��" << endl;
		return false;
	}
	int num = size();													
	if (index > num || index <= 0)
	{
		cout << "����Ŀǰ��" << num << "���ڵ㣬������1~" << num << endl;
		return false;
	}			
	if (index == num)
	{
		pop_back();
	}
	else
	{
		Node* p;														//pΪ��index���ڵ�
		int i;
		for (p = head, i = 1; i < index; p = p->next, i++);
		p->next->prior = p->prior;
		p->prior->next = p->next;
		delete p;
	}
	return true;
}

template<class ElemType>
bool QGList<ElemType>::contain(ElemType e)
{
	Node* p;
	int num = 1;
	for (p = head; p; p = p->next,num++)
		if (p->data == e)
		{
			cout << "��Ԫ��λ�ڵ�" << num << "�ڵ�";
			return true;
		}
	return false;
}

template<class ElemType>
unsigned int QGList<ElemType>::size()
{
	Node* p;
	int num = 0;
	for (p = head; p; p = p->next, num++);
	return num;
}

template<class ElemType>
bool QGList<ElemType>::traverse(void (*visit)(ElemType& e))
{
	if (head == NULL)
	{
		cout << "��δ�������������Ϊ��" << endl;
		return false;
	}
	Node* p;
	for (p = head; p; p = p->next)
		visit(p->data);
	return true;
}

template<class ElemType>
void QGList<ElemType>::print()
{
	if (head == NULL)
		cout << "����Ϊ��" << endl;
	Node* p1;
	for (p1 = head; p1 != NULL; p1 = p1->next)
	{
		cout << p1->data << " ";
	}
	cout << endl;
}


template<class ElemType>
ElemType QGList<ElemType>::CreatFill()
{
	ElemType a;
	cin >> a;
	return a;
}


template<class ElemType>
bool QGList<ElemType>::reverse_1() { return true; }


template<class ElemType>
typename QGList<ElemType>::Node* QGList<ElemType>::reverse_2(Node* temp) { return head; }


template<class ElemType>
bool QGList<ElemType>::isLoop() { return true; }


template<class ElemType>
bool QGList<ElemType>::reverseEven() { return true; }


template<class ElemType>
typename QGList<ElemType>::Node& QGList<ElemType>::middleElem() { return *head; }
