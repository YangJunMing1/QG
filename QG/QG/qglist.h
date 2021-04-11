#ifndef __QGLIST_H__
#define __QGLIST_H__
#include<iostream>
#include"FillReview.h"

using namespace std;
/*
 * ˫������
 */
template<class ElemType>
class QGList {
	
public:

protected:
	struct Node {
		ElemType data;
	  	struct Node *prior;
		struct Node *next;
	};


public:

	Node* head;
	Node* tail;
	/*
	 * ��ʼ������
	 */
	QGList();

	/*
	 * ��������
	 */
	~QGList();
	
	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	ElemType& front();

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	ElemType& back();

	/*
	 * �������һ��Ԫ��ǰ���Ԫ��e
	 */
	bool push_front(ElemType e);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	bool pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	bool push_back(ElemType e);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	bool pop_back();
	
	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	bool insert(unsigned int index, ElemType e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	bool erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * ����Ԫ���Ƿ����
	 */
	bool contain(ElemType e);
        
	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	bool traverse(void (*visit)(ElemType& e));

	/*
	 * ��ӡ����
	 */
	void print();

	ElemType CreatFill();				//��ϲ��룬���ң�ɾ���ȷ���

	bool reverse_1();

	Node* reverse_2(Node* temp);	

	bool isLoop();

	bool reverseEven();

	Node& middleElem();
};

#endif

