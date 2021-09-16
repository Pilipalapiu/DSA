#ifndef _SORT_H_
#define _SORT_H_

#include"../tools/tools.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


//插入排序算法
void insertionSort (int *A, int len) {
    int i,j;//循环变量
    int tmp;//缓存区

    for (int i = 1; i < len; i++)//外层循环，遍历无序序列的每一个元素
    {
        tmp=A[i];
        j=i-1;
        while (A[j]>tmp&&j>-1)//内层循环，逆向遍历有序序列，为当前数值寻找合适的插入位置
        {
            A[j+1]=A[j];
            j--;
        }   
        A[j+1]=tmp;
    } 
}

//希尔排序
void shellSort(int *A, int len){
    int i,j,gap,tmp;
    for (gap = len>>1; gap>0; gap>>=1)
    {
        for ( i = gap; i < len; i++)
        {
            tmp=A[i];
            for ( j = i-gap; j >= 0&&A[j]>tmp; j-=gap)
            {
                A[j+gap]=A[j];
            }
            A[j+gap] = tmp;
            
        }  
        
    }
    
}

//起泡排序算法_第三版
void bubbleSort(int *A, int len){
    int lastIndex;//标志位，记录上次发生交换的位置
    int tmp;
    int i,j;
    i=len;
    while (i>0)//i大于0代表，上一趟排序仍存在交换
    {
        lastIndex=0;//先将标志位置0
        for (j=0; j<i; j++)//遍历整个序列
        {
            if(A[j]>A[j+1]){
                tmp=A[j];
                A[j]=A[j+1];
                A[j+1]=tmp;
                lastIndex=j;//设置标志位，lastIndex之后的序列均为有序
            }
        }
        i=lastIndex;//将标志位值赋给循环变量，去除多余的比较操作
    } 
}

//选择排序
void selectionSort(int *A, int len){
    int i,j;
    int min,tmp;
    for (i = 0; i < len; i++)//遍历所有元素
    {
        min=A[i];
        for (int j = i+1; j < len; j++)//在i之后寻找更小的元素
        {
            if (min>A[j])//若发现，则替换二者位置
            {
                tmp=A[j];
                A[j]=min;
                min=tmp;
            }    
        }   
    }
}

//merge iteration version
void mergeSort(int *A, int len){
    int* a = A;//动态数组a用于存放待排序序列
    int* b = (int *)malloc(sizeof(int)*len);//动态数组b用于临时存放处于排序过程中的序列
    int seg_size;//当前一个序列段的大小
    int start;

    for ( seg_size = 1; seg_size<len; seg_size+=seg_size)//序列大小从1至len依次增大
    {
        for (start=0; start < len; start+=seg_size*2)//从起始位置，对每一个大小为seg_size的序列进行操作
        {
            //每一个序列的取值范围为一个左闭右开的区间[start,end)
            int k = start;
            int start1 = start;
            /*
            使用min()函数是为了处理界桩越界的情况
            例如，对于奇数序列，start1抵达最后一个
            元素(Index = len-1)的位置时，其余三个
            界桩会被设置为len,对应了循环2
            */
            int end1 = min(start+seg_size, len);
            int start2 = min(start+seg_size, len);
            int end2 = min(start+seg_size*2, len);
            while(start1<end1&&start2<end2)//1
                b[k++] = a[start1]<a[start2] ? a[start1++] : a[start2++];
            while(start1<end1)             //2
                b[k++] = a[start1++];
            while(start2<end2)             //3
                b[k++] = a[start2++];
        }
        
        int *tmp;
        tmp = a;
        a = b;
        b = tmp;

    }
    free(b);

}

//quick
void quickSort(int *A, int len){

}
#endif // _SORT_H_
