#include"DSA.h"

int main(){
    PQ *H;
    H->LastIndex = -1;
    Floyd_Heapify(&H);
    show(H->data,(H->LastIndex)+1);
}
