#include <stdio.h>
#include "sort.h"

int main(){
    int A[10]={12,32,43,54,65,75,87,4,2,5};
    show(A,10);
    insertionSort(A,10);
    show(A,10);
}