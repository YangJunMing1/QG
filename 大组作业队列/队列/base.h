#ifndef BASE_H
#define BASE_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum
{
    FALSE = 0, TRUE = 1
} Status;

char datatype[20];
int type_size;
Status isA;
Status isinit;


void SIZE();

#endif