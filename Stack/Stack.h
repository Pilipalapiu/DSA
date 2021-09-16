#ifndef _STACK_H_
#define _STACK_H_

#define MAXSIZE 128

#include<stdio.h>

typedef struct Stack{

    int top;
    int data[MAXSIZE];

    //int (*push) ();
    //int (*pop) ();
    //int (*get_top) ();

}Stack;

int pop(Stack* S){

    if(S->top == -1) return -1;

    return S->data[(S->top)--];
}

int push(Stack* S, int a){

    if (S->top < (MAXSIZE - 1)){ 
        a = S->data[++(S->top)];
    } else return -1;

    return 1;
}

#endif  //_STACK_H_