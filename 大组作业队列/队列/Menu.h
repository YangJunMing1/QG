#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"AQueue.h"
#include"LQueue.h"

/* 选择队列菜单 */
void Menu_1();

void select_1();

/* 选择类型菜单 */
void Menu_2();

/* 选择类型 */
void select_2();

/* 功能菜单 */
void Menu_3();
void Menu_4();

/* 功能选择菜单 */
void select_3(Status* loop,AQueue *temp);
void select_4(Status* loop, LQueue* temp);

/* 纠错函数 */
char correct(char i, char j, char I, char J);