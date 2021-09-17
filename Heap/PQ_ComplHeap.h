#ifndef _PQ_COMPLHEAP_H_
#define _PQ_COMPLHEAP_H_
#define MAXSIZE 128

#include "../tools/tools.h"

typedef struct PQ {
    int data[MAXSIZE];
}PQ;

int get_PQmax(PQ* PQ){
    return PQ->data[0];
}

int del_PQmax(PQ* PQ){
    swap(&(PQ->data[0]),&(PQ->data[MAXSIZE-1]));
}

int insert_PQ(PQ* PQ){

}
#endif  // _PQ_COMPLHEAP_