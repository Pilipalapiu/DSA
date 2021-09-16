#include"DSA.h"

int main(){
    int Stack[10]={10,9,8,7,6,5,4,3,2,1};
    int A[10]={1,2,3,4,6,7,8,9,10,5};

    if(permutation_check(A,Stack,9))
        printf("A is a permutation");
    else
        printf("WRONG");

}