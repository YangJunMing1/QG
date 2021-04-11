#include"Menu.h"

void Menu_1()
{
	printf("AQueue or LQueue\n");
	printf("1-AQueue\n");
	printf("2-LQueue\n");
	select_1();
}

void select_1()
{
	char choice=correct('1', '2', 'b', 'a');
	switch (choice)
	{
	case'1':isA = TRUE; break;
	case'2':isA = FALSE; break;
	}
}

void Menu_2()		
{
	printf("choose your type\n");
	printf("1-int\n");
	printf("2-char\n");
	printf("3-double\n");
	select_2();
}

void select_2()
{

	char choice=correct('1','3','a','a');
	switch (choice)
	{
	case '1':strcpy_s(datatype, 4, "int");  break;
	case '2':strcpy_s(datatype, 5, "char"); break;
	case '3':strcpy_s(datatype, 7, "double"); break;
	}
	SIZE();
}

void Menu_3()
{
	Status loop=TRUE;
	AQueue* temp = (AQueue*)malloc(sizeof(AQueue));
	do
	{
		system("cls");
		printf("1-Init\n");
		printf("2-Judge_IsEmpty\n");
		printf("3-Destory\n");
		printf("4-Judge_IsFull\n");
		printf("5-GetHead\n");
		printf("6-Length\n");
		printf("7-push\n");
		printf("8-pop\n");
		printf("9-clear\n");
		printf("a-Traverse_print\n");
		printf("0-exit\n");

		select_3(&loop,temp);
		system("pause");
	} while (loop);
	DestoryAQueue(temp);		//销毁队列，归还空间
}

void Menu_4()
{
	Status loop = TRUE;
	LQueue* temp = (LQueue*)malloc(sizeof(LQueue));
	do
	{

		system("cls");
		printf("1-Init\n");
		printf("2-Judge_IsEmpty\n");
		printf("3-Destory\n");
		printf("4-GetHead\n");
		printf("5-Length\n");
		printf("6-push\n");
		printf("7-pop\n");
		printf("8-clear\n");
		printf("9-Traverse_print\n");
		printf("0-exit\n");
		select_4(&loop, temp);
		system("pause");
	} while (loop);
	DestoryLQueue(temp);		//销毁队列，归还空间
}

void select_3(Status* loop, AQueue* temp)
{
	char choice = correct('0', '9', 'a', 'a');
	switch (choice)
	{
	case'1': {
		InitAQueue(temp);
		printf("inti success\n");
		break;
	}
	case'2': {

		if (isinit == FALSE)
			printf("haven`t init!\n");
		else {
			if (temp->length==0)
				printf("isempty\n");
			else
				printf("notempty\n");
		}
		break;
	}
	case'3': {
		if (isinit == FALSE)
			printf("haven`t init!\n");
		else {
			if (DestoryAQueue(temp))
				printf("destroy success\n");
			else
				printf("The queue is not exit\n");
		}
		break;
	}
	case'4': {
		if (isinit == FALSE)
			printf("haven`t init!\n");
		else {
			if (IsFullAQueue(temp))
				printf("The queue is full\n");
			else
				printf("The queue is not full\n");
		}
		break;
	}
	case'5': {
		if (isinit == FALSE)
			printf("haven`t init!\n");
		else {
			void* e =(void*)malloc(type_size);
			if (GetHeadAQueue(temp, e))
			{
				printf("The First elem is  ");
				APrint(e);
			}
			else
				printf("The queue is empty\n");
		}
		break;
	}
	case'6': {
		if (isinit == FALSE)
			printf("haven`t init!\n");
		else {
			printf("The queue`length is %d\n", LengthAQueue(temp));
		}
		break;
	}
	case'7': {
		if (isinit == FALSE)
			printf("haven`t init!\n");
		else if (IsFullAQueue(temp))
			printf("is Full\n");
		else {
			printf("please input the data:  ");
			if (strcmp(datatype, "int") == 0)
			{
				int data;
				scanf_s("%d", &data);
				EnAQueue(temp, &data);
			}
			else if (strcmp(datatype, "char") == 0)
			{
				char data;
				scanf_s("%c", &data, 1);
				EnAQueue(temp, &data);
			}
			else {
				double data;
				scanf_s("%lf", &data);
				EnAQueue(temp, &data);
			}
			getchar();
		}
		break;
	}
	case'8': {
		if (isinit == FALSE)
			printf("haven`t init!\n");
		else {
			if (DeAQueue(temp))
				printf("pop success\n");
			else
				printf("error!The queue is empty\n");
		}
		break;
	}
	case'9': {
		ClearAQueue(temp);
		printf("clear success\n");
		break;
	}
	case'a': {
		if (isinit == FALSE)
			printf("haven`t init!\n");
		else {
			if (!TraverseAQueue(temp, APrint))
				printf("The pueue is empty\n");
		}
		break;
	}
	case'0':*loop = FALSE; break;
	}

}


void select_4(Status * loop,LQueue *temp)
{
	char choice = correct('0', '9', 'b', 'a');
	switch (choice)
		{
		case'1': {
			InitLQueue(temp);
			printf("inti success\n");
			break;
		}
		case'2': {
			if (isinit == FALSE)
				printf("haven`t init!\n");
			else {
				if (IsEmptyLQueue(temp))
					printf("isempty\n");
				else
					printf("notempty\n");
			}
			break;
		}
		case'3': {
			if (isinit == FALSE)
				printf("haven`t init!\n");
			else {
				if (DestoryLQueue(temp))
					printf("destroy success\n");
				else
					printf("The queue is not exit\n");
			}
			break;
		}
		case'4': {
			if (isinit == FALSE)
				printf("haven`t init!\n");
			else {
				void* e=NULL;
				if (!GetHeadLQueue(temp, e))
				{
					printf("The First elem is  ");
					LPrint(e);
				}
				else
					printf("The queue is empty\n");
			}
			break;		
		}
		case'5': {
			if (isinit == FALSE)
				printf("haven`t init!\n");
			else {
				printf("The queue`length is %d\n", LengthLQueue(temp));
			}
			break;
		}
		case'6': {
			if (isinit == FALSE)
				printf("haven`t init!\n");
			else {
				printf("please input the data:  ");
				if (strcmp(datatype, "int")==0)
				{
					int data;
					scanf_s("%d", &data);
					EnLQueue(temp, &data);
				}
				else if (strcmp(datatype, "char") == 0)
				{
					char data;
					scanf_s("%c", &data,1);
					EnLQueue(temp, &data);
				}
				else {
					double data;
					scanf_s("%lf", &data);
					EnLQueue(temp, &data);
				}
				getchar();
			}
			break;
		}
		case'7': {
			if (isinit == FALSE)
				printf("haven`t init!\n");
			else {
				if (DeLQueue(temp))
					printf("pop success\n");
				else
					printf("error!The queue is empty\n");
			}
			break;
		}
		case'8':{
			ClearLQueue(temp);
			printf("clear success\n");
			break;
		}
		case'9': {
			if (isinit == FALSE)
				printf("haven`t init!\n");
			else {
				if (!TraverseLQueue(temp,LPrint))
					printf("The pueue is empty\n");
			}
			break;
		}
		case'0':*loop = FALSE; break;
		}

}

char correct(char i,char j,char I,char J)
{
	char op,t;
	op=getchar();
	t=getchar();			//消化回车
	while ((op<i || op>j)&&(op<I||op>J))
	{
		printf("unreasonable input\n");
		op=getchar();
		t=getchar();
	}
	return op;
}