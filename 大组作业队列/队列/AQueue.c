#include"AQueue.h"

/* 初始化队列 */
void InitAQueue(AQueue* Q)
{
    int i;
    for (i = 0; i < MAXQUEUE; i++)
        Q->data[i] = (void*)malloc(type_size);
    Q->front = Q->length = Q->rear = 0;
    isinit = TRUE;
 
}

/* 检查队列是否为空*/
int IsEmptyAQueue(AQueue* Q)
{
    if (LengthAQueue(Q) == 0)
        return 1;
    else
        return 0;
}

/* 销毁队列 */
Status DestoryAQueue(AQueue* Q)
{
    if (Q->data[0] == NULL)
        return FALSE;
    int i;
    for (i = 0; i < MAXQUEUE; i++)
    {
        Q->data[i] = NULL;
        free(Q->data[i]);
    }
    isinit = FALSE;
    return TRUE;
}


/* 检查队列是否已满 */
Status IsFullAQueue( AQueue* Q)
{
    if (Q->length == MAXQUEUE-1)
        return TRUE;
    else
        return FALSE;
}



/* 查看队头元素 ，存放元素e */
Status GetHeadAQueue(AQueue* Q, void* e)
{
    if (Q->length == 0)
        return FALSE;
    memcpy(e, Q->data[Q->front],type_size);
    return TRUE;
}


/**
 * 确定队列长度 */
int LengthAQueue(AQueue* Q)
{
    return Q->length;
}



/* 入队操作 入队数据指针data */
Status EnAQueue(AQueue* Q, void* data)
{
    if (IsFullAQueue(Q))
        return FALSE;
    memcpy(Q->data[Q->rear], data, type_size);
    Q->length++;
    Q->rear=(Q->rear+1)%MAXQUEUE;
    
    return TRUE;
}



/* 出队操作 */
Status DeAQueue(AQueue* Q)
{
    if (Q->length == 0)
        return FALSE;
    Q->front = (Q->front + 1) % MAXQUEUE;
    Q->length--;
    return TRUE;
}


/*  清空队列 */
void ClearAQueue(AQueue* Q)
{
    int i;
    for (i = Q->front; i % MAXQUEUE != Q->rear; i++)
        Q->data[i] = NULL;
}


/* 遍历函数操作 */
Status TraverseAQueue(const AQueue* Q, void (*foo)(void* q))
{
    if (Q->length == 0)
        return FALSE;
    int i;
    for (i = Q->front; i % MAXQUEUE != Q->rear; i++)
        (*foo)(Q->data[i]);
    printf("\n");
    return TRUE;
}


/* 操作函数 */
void APrint(void* q)
{
    if (strcmp(datatype, "int")==0)
        printf("%d\t",*(int *)q);
    else if (strcmp(datatype, "char")==0)
        printf("%c\t", *(char*)q);
    else if (strcmp(datatype, "double")==0)
        printf("%lf\t", *(double*)q);

}