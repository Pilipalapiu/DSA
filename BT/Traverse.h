#ifndef _TRAVERSE_H_
#define _TRAVERSE_H_

#include"BinTree.h"
#include<stdio.h>


//先序遍历递归版
void pre_recursion(BinTree T){
    if (T!=NULL)
    {
        printf(" %d ",T->data);
        pre_recursion(T->lc);
        pre_recursion(T->rc);
    }
    
    
}

//先序遍历迭代版
void pre_iteration(BinTree T){
    BinNode* S[100];
    int top = -1;
    
    while (top!=-1)
    {
        while (T!=NULL)
        {
            printf(" %d ",T->data);
            if(T->rc!=NULL) S[++top] = T->rc;
            T = T->lc;    
        }
        T = S[top--];
    }
    
    
    
    
}

//中序遍历递归版
void in_recursion(BinTree T){
    if (T!=NULL)
    {
        in_recursion(T->lc);
        printf(" %d ",T->data);
        in_recursion(T->rc);
    }
    
}

//中序遍历迭代版
void in_iteration(BinTree T){
    BinNode* S[100];
    int top = -1;
    while (top!=-1)
    {
        while (T!=NULL)
        {
            S[++top] = T; 
            T = T->lc;
        }
        T = S[top--];
        printf(" %d ",T->data);
        T = T->rc;
    }
    

}

//后序遍历递归版
void pos_recursion(BinTree T){
    if (T!=NULL)
    {
        pos_recursion(T->lc);
        pos_recursion(T->rc);
        printf(" %d ",T->data);
    }
    
}

//后序遍历迭代版
void pos_iteration(BinTree T){
    BinNode* S[100];
    int top = -1;
    BinNode* LastVisit;
    LastVisit = NULL;
    S[++top] = T;

    while(top!=-1){
        while((T->lc!=LastVisit && T->rc!=LastVisit) || LastVisit==NULL){
            if (T->lc!=NULL){
                if (T->rc!=NULL) S[++top] = T->rc;
                S[++top] = T->lc;
                T = T->lc;   
            } 
            else if(T->rc!=NULL && T->lc == NULL ) {
                S[++top] = T->rc;
                T=T->rc;
            }
            else if(T->rc == NULL && T->lc == NULL){
                break;
            }

        }    
        LastVisit = S[top--];
        printf(" %d",LastVisit->data);
        T = S[top];    
    }
                    
}
#endif //_TRAVERSE_H_
