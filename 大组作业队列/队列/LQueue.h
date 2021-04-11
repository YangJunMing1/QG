#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#include<stdio.h>
#include"base.h"

//链式队列结构
typedef struct node
{
    void *data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    int length;            //队列长度
} LQueue;
					

/* 初始化队列*/
void InitLQueue(LQueue *Q);

/* 销毁队列 */
Status DestoryLQueue(LQueue *Q);

/* 检查队列是否为空*/
Status IsEmptyLQueue(const LQueue *Q);

/* 队列指针Q,返回数据指针e */
Status GetHeadLQueue(LQueue *Q, void *e);

/* 确定队列长度 */
int LengthLQueue(LQueue *Q);

/*入队操作 */
Status EnLQueue(LQueue *Q, void *data);

/* 出队操作 */
Status DeLQueue(LQueue *Q);

/* 清空队列 */
void ClearLQueue(LQueue *Q);

/* 遍历函数操作 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q));

/* 操作函数 */
void LPrint(void *q);

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED


