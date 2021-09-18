#include<stdio.h>

void changeValue(int *a, int *b){
    int temporaryValue = *a;

    *a = *b;

    *b = temporaryValue;
}

int main() {
    int x = 5;
    int y = 10;

    changeValue(&x, &y);

    printf("x:%d y:%d",x,y);

    return 0;
}