#include"DSA.h"

int main(){

    LeftHeap A;
    A = LeftHeapCreate();
    PreRecHeapTraversal(A);
    printf("\n\n");
    InRecHeapTraversal(A);

}
