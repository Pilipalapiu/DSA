#ifndef _PERMUTATION_CHECK_H_
#define _PERMUTATION_CHECK_H_

#include<stdbool.h>

int permutation_check(int A[10], int Stack[10], int top){

    int Check[10];
    int ck_top = -1;

    for (int i = 0; i < 10; i++)
    {
        while(ck_top==-1 || Check[ck_top]!=A[i])
            if(top!=-1) 
                Check[++ck_top] = Stack[top--];
            else 
                return 0;
        ck_top--;
    }
    return 1;
}

#endif //_STACK_H_