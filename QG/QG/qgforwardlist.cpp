#include"qgforwardlist.h"
template<class ElemType>
QGForwardList<ElemType>::QGForwardList()
{
	head = tail = NULL;
	cout << "现在创建链表，无论链表数据的类型，单独输入“0”结束" << endl;
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
	Node* p1, * p2;							//p1指针负责遍历，p2指针用于归还空间
	if (head != NULL)
	{
		for (p1 = p2 = head; p1; p2=p1)
		{
			p1 = p2->next;
			delete p2;
		}
		head = tail = NULL;
	}
	cout << "链表删除成功" << endl;
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
		cout << "尚未创建链表或链表为空" << endl;
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
		if (head != tail)								//不止一个节点
		{
			Node* p;
			for (p = head; p->next != tail; p = p->next);
			delete tail;
			tail = p;
			tail->next = NULL;
			return true;
		}
		else											//只有一个节点
		{
			delete tail;
			head = tail = NULL;
			return true;
		}
	}
	else
	{
		cout << "尚未创建链表或链表为空" << endl;
		return false;
	}
}

template<class ElemType>
bool  QGForwardList<ElemType>::insert(unsigned int index, ElemType e)		//成为第index个节点
{
	
	if (head == NULL)
	{
		Node* p = new Node;
		p->data = e;
		head = tail = p;
		head->next = tail->next = NULL;
		return true;
	}
	int num = size();											//求节点数
	if (index > num+1)
	{
		cout << "链表目前有" << num << "个节点，请输入0~" << num <<endl;
		return false;
	}															//以上为优化处理
	if (index == 1)												//插入成首元素
		push_front(e);
	else
	{
		Node* p,*p2=new Node;									//p为第index个节点，p2为接入节点
		p2->data = e;
		int i;
		for (p = head, i = 1; i < index-1; p = p->next, i++);	//找到第index个节点
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
		cout << "尚未创建链表或链表为空" << endl;
		return false;
	}	
	int num = size();													//求节点数
	if (index > num||index<=0)	
	{
		cout << "链表目前有" << num << "个节点，请输入1~" << num << endl;
		return false;
	}																	//以上为优化处理
	else
	{
		Node* p;														//p为第index个节点
		int i;
		if (index != 1)													//该删除操作需要找到删除节点的前一个节点，所以要将删除头节点作为特例
		{
			for (p = head, i = 1; i < index - 1; p = p->next, i++);		//找到第index-1个节点
			p->next = p->next->next;
		}
		else if (head != tail)											//不止一个节点，删除头节点
		{
			p = head;
			head = head->next;
			delete p;
		}
		else															//只有一个节点，删除头节点
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
			cout << "该元素位于第" << num << "节点";
			return true;
		}
	return false;
}

template<class ElemType>
bool QGForwardList<ElemType>::traverse(void (*visit)(ElemType& e))
{
	if (head == NULL)
	{
		cout << "尚未创建链表或链表为空" << endl;
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
		cout << "尚未创建链表或链表为空" << endl;
		return false;
	}
	Node* p1, * temp_1,*temp_2;														//p1为当前操作节点，temp_1标记为p1的前一个节点，temp_2为后一个
	for (temp_1 = head, p1 = head->next; p1; p1 = temp_2)
	{
		temp_2 = p1->next;
		p1->next = temp_1;
		temp_1 = p1;
	}
	tail = head;																	//头尾交换
	tail->next = NULL;																//注意悬空指针
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
	Node* p1,*temp;								//p1为交换节点，temp保存上一次交换节点
	for (p1 = temp = head; p1; p1 = p1->next)
	{
		if (first)								//1，2节点交换，考虑到head要调整，作为特例操作
		{
			head = p1->next;
			p1->next = head->next;
			head->next = p1;
			first = false;
		}
		else
		{
			if (p1->next == NULL)				//如果出现p1->next为空，说明节点数为奇数，最后一个节点无可交换的对象，所以不操作
			{
				tail = p1;						//此时temp不是尾节点，需要让tail指向p1
				return true;
			}				
			temp->next = p1->next;
			p1->next = temp->next->next;
			temp->next->next = p1;
		}
		temp = p1;

	}
	tail = temp;								//此时temp是尾节点
	return true;
}
    
template<class ElemType>
typename QGForwardList<ElemType>::Node& QGForwardList<ElemType>:: middleElem()
{
	Node* p1, * p2;
	for (p1 = head,p2=head->next; p2&&p2->next; p1 = p1->next, p2 = p2->next->next);
	//cout << "中间节点为" <<p1->data<< endl;
	return *p1;

}

template<class ElemType>
void QGForwardList<ElemType>:: print()
{
	
	if (head == NULL)
		cout << "链表为空" << endl;
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