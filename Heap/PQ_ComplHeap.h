#ifndef _PQ_COMPLHEAP_H_
#define _PQ_COMPLHEAP_H_
#define MAXSIZE 128

#include "../tools/tools.h"
//完全二叉堆
typedef struct PQ {
    int LastIndex;
    int data[MAXSIZE];
}PQ;

int get_PQmax(PQ* PQ){
    return PQ->data[0];
}

int getParentIndex(PQ* H,int index){
    if( (index-1)>>1 > 0||(index-1)>>1 == 0 )
        return (index-1)>>1;
    else 
        return -1;
}

int getLcIndex(PQ* H,int index){
    if( (index*2 + 1) < H->LastIndex||(index*2 + 1) == H->LastIndex )
        return index*2 + 1;
    else 
        return -1;
}

int getRcIndex(PQ* H,int index){
    if((index*2 + 2) < H->LastIndex||(index*2 + 2) == H->LastIndex)
        return index*2 + 2;
    else
        return -1;
}
//判断一个索引的合法性
bool InHeap(PQ* H, int index){
   if((index > -1)&&(index < H->LastIndex + 1)) 
        return true;
    else 
        return false;
}
//右孩子值
int RChild(PQ* H, int index){
    if(InHeap(H,getRcIndex(H,index)))
        return H->data[getRcIndex(H,index)];
    else
        return -999;
}
//左孩子值
int LChild(PQ* H, int index){
    if(InHeap(H,getLcIndex(H,index)))
        return H->data[getLcIndex(H,index)]; 
    else
        return -999;
}

//是否有左孩子
bool HasLc(PQ* H, int index){
    if(InHeap(H,getLcIndex(H,index))) 
        return true; 
    else 
        return false;
}
//是否有右孩子
bool HasRc(PQ* H, int index){
    if(InHeap(H,getRcIndex(H,index))) 
        return true; 
    else
        return false;
}
//两者取最大者索引，相等前者优先
int Bigger(PQ* H, int index1,int index2){
    if((H->data[index1] > H->data[index2])||(H->data[index1] == H->data[index2]))
        return index1;
    else
        return index2;
}
//选取当前节点的最大孩子
int getMaxChild(PQ* H, int index){
    if(HasLc(H,index))
    {
        if(HasRc(H,index))
            return Bigger(H,getLcIndex(H,index),getRcIndex(H,index));
        else
            return getLcIndex(H,index);
    }
    else
    {
        if(HasRc(H,index))
            return getRcIndex(H,index);
        else
            return -1;
    }
}

//上滤
int up(PQ* PQ, int index){
    while (index!=0)
    {
        if(PQ->data[index] > PQ->data[getParentIndex(PQ,index)])
        {
            swap(&(PQ->data[index]), &(PQ->data[getParentIndex(PQ,index)]));
            index=getParentIndex(PQ,index);
        }
        else
            break;
    }
    return index; 
}
//下滤
int down(PQ* PQ, int index){
    while(1){
        if(getMaxChild(PQ,index)!=-1)
        {
            if(PQ->data[index] < PQ->data[getMaxChild(PQ,index)])
            {
                int tmp = getMaxChild(PQ,index);
                swap(&(PQ->data[index]), &(PQ->data[tmp]));
                index = tmp;
            }
            else
                break;
        }
        else
            break;
    }
}

int del_PQmax(PQ* PQ){
    int tmp = PQ->data[0];
    swap(&(PQ->data[0]),&(PQ->data[PQ->LastIndex--]));
    down(PQ, 0);
    return tmp;
}

void insert_PQ(PQ* PQ,int x){
    PQ->data[++(PQ->LastIndex)] = x;
    up(PQ,PQ->LastIndex);
}

//BF建堆：自上而下的上滤
void BF_Heapify(PQ* H){

    int buf;

    printf("\nEnter the value:\n");
    scanf("%d",&buf);
    while (buf!=991220)
    {
        insert_PQ(H,buf);
        printf("\nEnter the value:\n");
        scanf("%d",&buf);
    }
}
//Floyd建堆：自下而上的下滤
void Floyd_Heapify(PQ* H){

    int buf=4;
    int i;

    printf("\nEnter the value:\n");
    scanf("%d",&buf);
    while (buf!=991220)
    {
        H->data[++H->LastIndex] = buf--;
        printf("\nEnter the value:\n");
        scanf("%d",&buf);
    }

    for (i = H->LastIndex; i > -1; i--)
    {
        down(H,i);
    }
    
}
void showHeap(PQ* H){
    printf("\n\n");
    show(H->data,H->LastIndex+1);
    printf("\n\n");
}
#endif  // _PQ_COMPLHEAP_