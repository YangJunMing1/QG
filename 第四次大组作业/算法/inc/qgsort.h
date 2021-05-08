#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include<iostream>
#include<string>


/* 插入排序算法(从小到大) */
void insertSort(int *a,int n);


/*  归并排序（合并数组） */
void MergeArray(int *a,int begin,int end);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int mid,int end);


/* 快速排序（递归版） */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size);


/* 快速排序（枢轴存放） */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);


/* 在一个无序序列中找到第K大/小的数 */
int Find_KMax(int* a, int begin,int end,int K);

int Find_KMin(int* a, int begin, int end, int K);

#endif // QUEUE_H_INCLUDED
