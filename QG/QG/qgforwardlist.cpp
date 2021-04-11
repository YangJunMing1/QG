#include"qgforwardlist.h"
template<class ElemType>
QGForwardList<ElemType>::QGForwardList()
{
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
QGForwardList<ElemType>::~QGForwardList()
{
	Node* p1, * p2;							//p1ָ�븺�������p2ָ�����ڹ黹�ռ�
	if (head != NULL)
	{
		for (p1 = p2 = head; p1; p2=p1)
		{
			p1 = p2->next;
			delete p2;
		}
		head = tail = NULL;
	}
	cout << "����ɾ���ɹ�" << endl;
}

template<class ElemType>
ElemType& QGForwardList<ElemType>:: front()
{
	return head->data;
}

template<class ElemType>
ElemType& QGForwardList<ElemType>::back()
{
	return tail->data;
}

template<class ElemType>
bool QGForwardList<ElemType>::push_front(ElemType e)
{

	Node* p = new Node;
	p->data = e;
	if (head == NULL)
	{
		head =tail= p;
		head->next = tail->next = NULL;
		return true;
	}
	p->next = head;
	head = p;
	return true;
}

template<class ElemType>
bool QGForwardList<ElemType>::pop_front()
{
	if (head != NULL)
	{
		Node* p=head;
		head = head->next;
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
bool QGForwardList<ElemType>::push_back(ElemType e)
{
	Node* p = new Node;
	p->data = e;
	if (head == NULL)
	{
		head = tail = p;
		head->next = tail->next = NULL;
		return true;
	}
	else 
	{
		tail->next = p;
		tail = p;
		tail->next = NULL;
		return true;
	}
}

template<class ElemType>
bool QGForwardList<ElemType>:: pop_back()
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
bool  QGForwardList<ElemType>::insert(unsigned int index, ElemType e)		//��Ϊ��index���ڵ�
{
	
	if (head == NULL)
	{
		Node* p = new Node;
		p->data = e;
		head = tail = p;
		head->next = tail->next = NULL;
		return true;
	}
	int num = size();											//��ڵ���
	if (index > num+1)
	{
		cout << "����Ŀǰ��" << num << "���ڵ㣬������0~" << num <<endl;
		return false;
	}															//����Ϊ�Ż�����
	if (index == 1)												//�������Ԫ��
		push_front(e);
	else
	{
		Node* p,*p2=new Node;									//pΪ��index���ڵ㣬p2Ϊ����ڵ�
		p2->data = e;
		int i;
		for (p = head, i = 1; i < index-1; p = p->next, i++);	//�ҵ���index���ڵ�
		p2->next = p->next;
		p->next = p2;
	}
	return true;

}

template<class ElemType>
bool  QGForwardList<ElemType>::erase(unsigned int index)
{
	if (head == NULL)
	{
		cout << "��δ�������������Ϊ��" << endl;
		return false;
	}	
	int num = size();													//��ڵ���
	if (index > num||index<=0)	
	{
		cout << "����Ŀǰ��" << num << "���ڵ㣬������1~" << num << endl;
		return false;
	}																	//����Ϊ�Ż�����
	else
	{
		Node* p;														//pΪ��index���ڵ�
		int i;
		if (index != 1)													//��ɾ��������Ҫ�ҵ�ɾ���ڵ��ǰһ���ڵ㣬����Ҫ��ɾ��ͷ�ڵ���Ϊ����
		{
			for (p = head, i = 1; i < index - 1; p = p->next, i++);		//�ҵ���index-1���ڵ�
			p->next = p->next->next;
		}
		else if (head != tail)											//��ֹһ���ڵ㣬ɾ��ͷ�ڵ�
		{
			p = head;
			head = head->next;
			delete p;
		}
		else															//ֻ��һ���ڵ㣬ɾ��ͷ�ڵ�
		{
			delete head;
			head = tail = NULL;
		}
	}
	return true;

}


template<class ElemType>
bool QGForwardList<ElemType>::clear()
{
	Node* p1, * p2;
	for (p1 = p2 = head; p1; p2 = p1)
	{
		p1 = p2->next;
		delete p2;
	}
	head = tail = NULL;
	head = new Node;
	head = NULL;
	return true;
}

template<class ElemType>
bool QGForwardList<ElemType>::contain(ElemType e)
{
	Node* p;
	int num=1;
	for (p = head; p; p = p->next,num++)
		if (p->data == e)
		{
			cout << "��Ԫ��λ�ڵ�" << num << "�ڵ�";
			return true;
		}
	return false;
}

template<class ElemType>
bool QGForwardList<ElemType>::traverse(void (*visit)(ElemType& e))
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
bool QGForwardList<ElemType>::reverse_1()
{
	if (head == NULL)
	{
		cout << "��δ�������������Ϊ��" << endl;
		return false;
	}
	Node* p1, * temp_1,*temp_2;														//p1Ϊ��ǰ�����ڵ㣬temp_1���Ϊp1��ǰһ���ڵ㣬temp_2Ϊ��һ��
	for (temp_1 = head, p1 = head->next; p1; p1 = temp_2)
	{
		temp_2 = p1->next;
		p1->next = temp_1;
		temp_1 = p1;
	}
	tail = head;																	//ͷβ����
	tail->next = NULL;																//ע������ָ��
	head = temp_1;
	return true;
}

template<class ElemType>
typename QGForwardList<ElemType>::Node* QGForwardList<ElemType>::reverse_2(Node *temp)
{
	Node* p = temp;
	if (p->next == NULL)
	{
		return p;
	}
	else
	{
		head = reverse_2(p->next);
		p->next->next = p;
		p->next = NULL;
	
		return head;
	}
}

template<class ElemType>
bool QGForwardList<ElemType>::isLoop()
{
	Node* p1, * p2;
	if (head == NULL)
		return false;
	for (p1 = head, p2 = head->next; p2; p1 = p1->next, p2 = p2->next->next)
	{
		if (p1 = p2)return true;
		if (p2 == NULL)return false;
	}
	return true;
}

template<class ElemType>
unsigned int QGForwardList<ElemType>::size()
{
	Node* p;
	int num = 0;
	for (p = head; p; p = p->next, num++);
	return num;
}

template<class ElemType>
bool QGForwardList<ElemType>::reverseEven()
{
	if (head == NULL)
		return false;
	if (size() == 1)
		return true;
	bool first=true;
	Node* p1,*temp;								//p1Ϊ�����ڵ㣬temp������һ�ν����ڵ�
	for (p1 = temp = head; p1; p1 = p1->next)
	{
		if (first)								//1��2�ڵ㽻�������ǵ�headҪ��������Ϊ��������
		{
			head = p1->next;
			p1->next = head->next;
			head->next = p1;
			first = false;
		}
		else
		{
			if (p1->next == NULL)				//�������p1->nextΪ�գ�˵���ڵ���Ϊ���������һ���ڵ��޿ɽ����Ķ������Բ�����
			{
				tail = p1;						//��ʱtemp����β�ڵ㣬��Ҫ��tailָ��p1
				return true;
			}				
			temp->next = p1->next;
			p1->next = temp->next->next;
			temp->next->next = p1;
		}
		temp = p1;

	}
	tail = temp;								//��ʱtemp��β�ڵ�
	return true;
}
    
template<class ElemType>
typename QGForwardList<ElemType>::Node& QGForwardList<ElemType>:: middleElem()
{
	Node* p1, * p2;
	for (p1 = head,p2=head->next; p2&&p2->next; p1 = p1->next, p2 = p2->next->next);
	//cout << "�м�ڵ�Ϊ" <<p1->data<< endl;
	return *p1;

}

template<class ElemType>
void QGForwardList<ElemType>:: print()
{
	
	if (head == NULL)
		cout << "����Ϊ��" << endl;
	Node* p1;
	for (p1=head; p1;p1 = p1->next)
	{
		cout << p1->data << " " ;

	}
	cout << endl;
}

template<class ElemType>
ElemType QGForwardList<ElemType>::CreatFill()
{
	ElemType a;
	cin >> a;
	return a;
}