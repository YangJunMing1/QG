#include"LQueue.h"

void InitLQueue(LQueue* Q)
{
	Q->front = Q->rear;
	//Q->front->next = Q->rear->next = NULL;			//悬空指针
	Q->front = Q->rear=NULL;
	Q->length = 0;
	isinit = TRUE;
}

Status DestoryLQueue(LQueue* Q)
{
	Node* p;
	for (p = Q->front; p; p=Q->front )
	{
		Q->front = Q->front->next;
		free(p);
	}
	p = NULL;
	return TRUE;
	
}

Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q->length == 0)
		return TRUE;
	else
		return FALSE;
}

Status GetHeadLQueue(LQueue* Q, void* e)
{
	if (IsEmptyLQueue(Q))
		return FALSE;
	memcpy(e, Q->front->data, type_size);
	return TRUE;
}

int LengthLQueue(LQueue* Q)
{
	return Q->length;
}

Status EnLQueue(LQueue* Q, void* data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = (void*)malloc(type_size);
	memcpy(p->data, data, type_size);
	if (Q->front == NULL)
		Q->front = Q->rear = p;
	else
		Q->rear->next = p;
	Q->rear = p;
	Q->rear->next = NULL;
	Q->length++;
	return TRUE;
}

Status DeLQueue(LQueue* Q)
{
	Node* p;	//标记指针
	p = Q->front;
	Q->front = Q->front->next;
	Q->length--;
	free(p);
	p = NULL;
	return TRUE;
}

void ClearLQueue(LQueue* Q)
{
	Node* p;
	for (p = Q->front; p != Q->rear; p = p->next)
		p->data = NULL;
	Q->front = Q->rear = NULL;
	Q->length = 0;
}

Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q))
{
	if (Q->length == 0)
		return FALSE;
	Node* p;
	for (p = Q->front; p; p = p->next)
	{
		if (p == NULL)
			printf("p is NULL\n");
		(*foo)(p->data);
	}

	printf("\n");
	return TRUE;
}

void LPrint(void* q)
{
	if (strcmp(datatype, "int") == 0)
		printf("%d  ", *(int*)q);
	else if (strcmp(datatype, "char") == 0)
		printf("%c  ", *(char*)q);
	else if (strcmp(datatype, "double") == 0)
		printf("%lf  ", *(double*)q);
}