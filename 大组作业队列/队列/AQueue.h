#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED
#include"base.h"
#define MAXQUEUE 10

//循环队列结构
typedef struct Aqueue
{
    void *data[MAXQUEUE];      //数据域
    int front;
    int rear;
    int length;        //队列长度
} AQueue;



 /* 初始化队列 */
void InitAQueue(AQueue* Q);

/* 检查队列是否为空 */
int IsEmptyAQueue(AQueue* Q);

 /* 销毁队列 */
Status DestoryAQueue(AQueue* Q);

/* 检查队列是否已满 */
Status IsFullAQueue(AQueue* Q);

/* 查看队头元素 ，存放元素e */
Status GetHeadAQueue(AQueue* Q, void* e);

/*确定队列长度 */
int LengthAQueue(AQueue* Q);

/* 入队操作 入队数据指针data */
Status EnAQueue(AQueue* Q, void* data);

/* 出队操作 */
Status DeAQueue(AQueue* Q);

/*  清空队列 */
void ClearAQueue(AQueue* Q);

/* 遍历函数操作 */
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q));

/* 操作函数 */
void APrint(void* q);


#endif