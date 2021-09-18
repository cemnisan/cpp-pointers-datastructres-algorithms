#include<stdio.h>
#include <string.h>

int titleLength(char *p){
    int length = 0;
    int i = 0;

    for(; p[i] != '\0'; i++){
        length++;
    }

    return length;
}

int main(){

    char title[] = "tura";

    printf("%d",titleLength(title));

    return 0;
}