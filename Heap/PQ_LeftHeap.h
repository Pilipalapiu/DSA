#ifndef _PQ_LEFTHEAP_H_
#define _PQ_LEFTHEAP_H_

#include"../tools/tools.h"

/*Structure*/
typedef struct HeapNode{

    struct HeapNode *lc;
    struct HeapNode *rc;
    //struct HeapNode *parent;
    int data;
    int npl;//Null Path Length

}HeapNode,*LeftHeap;

/*Algorithm*/

void SwapPtr(LeftHeap* a, LeftHeap* b){

    LeftHeap tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    
}

void PreRecHeapTraversal(LeftHeap LH){
    if (LH!=NULL)
    {
        printf(" %d ",LH->data);
        PreRecHeapTraversal(LH->lc);
        PreRecHeapTraversal(LH->rc);
    }  
}

void InRecHeapTraversal(LeftHeap LH){
    if (LH!=NULL)
    {
        InRecHeapTraversal(LH->lc);
        printf(" %d ",LH->data);
        InRecHeapTraversal(LH->rc);
    }
}

LeftHeap HeapMerge(HeapNode* a, HeapNode* b){

    if(!a) return b;
    if(!b) return a;
    if (a->data < b->data)
        SwapPtr(&a,&b);
    a->rc = HeapMerge(a->rc,b); 
    if (!a->lc || a->lc->npl < a->rc->npl)
        SwapPtr(&(a->lc),&(a->rc));
    a->npl = a->rc ? (a->rc->npl + 1) : 1;
    return a; 
}

LeftHeap NewHeapNode(int key){

    LeftHeap LH;
    LH = (LeftHeap)malloc(sizeof(HeapNode));
    LH->data = key;
    LH->npl = 1;

    return LH;
}

void LeftHeapInsert(LeftHeap* LH, int key ){

    LeftHeap a = NULL;
    LeftHeap b = NULL;
    b = NewHeapNode(key);
    a = *LH;
    b->data = key;
    *LH =  HeapMerge(a,b);

}

LeftHeap LeftHeapCreate(){

    LeftHeap LH=NULL;
    int buf;

    printf("\nEnter the key:\n");
    scanf("%d",&buf);
    while (buf!=991220)
    {
        LeftHeapInsert(&LH,buf);
        printf("\nEnter the key:\n");
        scanf("%d",&buf);
    }
    return LH;


}

#endif // _PQ_LEFTHEAP_H_
