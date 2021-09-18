#include<stdio.h>

int max(int *a, int length){
    int maks = a[0];

    int i;

    for (i=1; i < length; i++){
        if (a[i] > maks){
            maks = a[i];
        }
    }
    return maks;
}


int main(){

    int numbers[5] = {3,4,532,320,5};

    int maks = max(numbers,5);

    printf("Largest element of the array of numbers: %d", maks);

    /* Offset

    int *ptr = numbers;

    printf("%d\n", ptr[0]);
    printf("%d\n", ptr[1]);
    printf("%d\n", ptr[2]);
    printf("%d\n", ptr[3]);
    printf("%d\n", ptr[4]);*/

    return 0;
}