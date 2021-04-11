#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#include<stdio.h>
#include"base.h"

//��ʽ���нṹ
typedef struct node
{
    void *data;                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    int length;            //���г���
} LQueue;
					

/* ��ʼ������*/
void InitLQueue(LQueue *Q);

/* ���ٶ��� */
Status DestoryLQueue(LQueue *Q);

/* �������Ƿ�Ϊ��*/
Status IsEmptyLQueue(const LQueue *Q);

/* ����ָ��Q,��������ָ��e */
Status GetHeadLQueue(LQueue *Q, void *e);

/* ȷ�����г��� */
int LengthLQueue(LQueue *Q);

/*��Ӳ��� */
Status EnLQueue(LQueue *Q, void *data);

/* ���Ӳ��� */
Status DeLQueue(LQueue *Q);

/* ��ն��� */
void ClearLQueue(LQueue *Q);

/* ������������ */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q));

/* �������� */
void LPrint(void *q);

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED


