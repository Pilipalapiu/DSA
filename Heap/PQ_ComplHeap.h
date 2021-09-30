#ifndef _PQ_COMPLHEAP_H_
#define _PQ_COMPLHEAP_H_
#define MAXSIZE 128

#include "../tools/tools.h"

typedef struct PQ {
    int LastIndex;
    int data[MAXSIZE];
}PQ;

int get_PQmax(PQ* PQ){
    return PQ->data[0];
}

int getParentIndex(int index){
    return (index-1)>>1;
}

int getLcIndex(int index){
    return index<<1 + 1;
}

int getRcIndex(int index){
    return index<<1 + 2;
}

//上滤
int up(PQ* PQ, int index){
    while (index!=0)
    {
        if(PQ->data[index] > PQ->data[getParentIndex(index)])
        {
            swap(&(PQ->data[index]), &(PQ->data[getParentIndex(index)]));
            index = getParentIndex(index);
        }
        else
            break;
    }
    return index; 
}
//下滤
int down(PQ* PQ, int index){
    while (index < PQ->LastIndex )
    {
        if(PQ->data[index] < PQ->data[getLcIndex(index)])
        {
            swap(&(PQ->data[index]), &(PQ->data[getLcIndex(index)]));
            index = getLcIndex(index);
            break;
        }
        if (PQ->data[index] < PQ->data[getRcIndex(index)])
        {
            swap(&(PQ->data[index]), &(PQ->data[getRcIndex(index)]));
            index = getRcIndex(index);
            break;
        }
        else
            break;
    }
    return index;
}

int del_PQmax(PQ* PQ){
    int tmp = PQ->data[(PQ->LastIndex)--];
    swap(&(PQ->data[0]),&(PQ->data[PQ->LastIndex]));
    down(PQ, 0);
    return tmp;
}

void insert_PQ(PQ* PQ,int x){
    PQ->data[++(PQ->LastIndex)] = x;
    up(PQ,PQ->LastIndex);
}

//BF建堆
void BF_Heapify(PQ** H){

    int buf;

    printf("\nEnter the value:\n");
    scanf("%d",&buf);
    while (buf!=991220)
    {
        insert_PQ(*H,buf);
        printf("\nEnter the value:\n");
        scanf("%d",&buf);
    }
}
//Floyd建堆
void Floyd_Heapify(PQ** H){

    int buf;

    printf("\nEnter the value:\n");
    scanf("%d",&buf);
    while (buf!=991220)
    {
        (*H)->data[++(*H)->LastIndex] = buf;
        printf("\nEnter the value:\n");
        scanf("%d",&buf);
    }
    for (int i = (*H)->LastIndex; i < 0; i--)
    {
        down(*H,i);
    }
    
}

#endif  // _PQ_COMPLHEAP_