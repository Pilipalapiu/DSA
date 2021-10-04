#ifndef _BST_H_
#define _BST_H_

#include"BinTree.h"
#include<stdio.h>
#include<stdlib.h>

//查找值为key的节点
BinNode* BST_search(BinTree T,int key){
    while (T!=NULL&&key!=T->data)
    {
        if(key < T->data) T = T->lc;
        else T = T->rc;
    }
    return T;
}

//Insert a node into BST
int BST_insert(BinTree *T, int key){
    if (*T==NULL)
    {
        *T = (BinTree)malloc(sizeof(BinNode));
        (*T)->data = key;
        (*T)->lc = NULL;
        (*T)->rc = NULL;
        printf("插入:%d\n\n",(*T)->data);
        return 1;
    }
    else if (key == (*T)->data)
    {
        return 0;
    }
    else if (key < (*T)->data)
    {
        return BST_insert(&((*T)->lc),key);
    }
    else if (key > (*T)->data)
    {
        return BST_insert(&((*T)->rc),key);
    }
}
//Create a BST with the data entered from the keyboard
BinNode* create_BST(){

    int buf;//Buffer 

    BinTree T=NULL;
    
    scanf("%d",&buf);
    while (buf!=991220)
    {
        BST_insert(&T,buf);
        scanf("%d",&buf);
    }
    return T;
}

#endif //_BST_H_