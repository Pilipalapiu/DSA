#ifndef _TOOLS_H_
#define _TOOLS_H_

#include<stdio.h>
#include<stdlib.h>

//print everything in a vector
void show(int *A, int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d ",A[i]);
    }
    
}

//swap the value of two variables
void swap(int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//find the minimun value between two variables
int min(int x, int y){
    return x>y ? y : x;
}

#endif // _TOOLS_H_
