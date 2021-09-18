#include <stdio.h>

char *dayName(char *ptr[],int length,int day){

    if (day >= 1 && day <=7){
        return ptr[day - 1];
    }
    else{
        return NULL;
    }
}

int main() {

    char *days[7] = {"Pazartesi","Salı","Çarşamba","Perşembe","Cuma","Cumartesi","Pazar"};

    char *ptr = dayName(days,7,1);

    if (ptr == NULL){
        printf("Pointer is NULL");
    }
    else{
        printf("%s",ptr);
    }

    return 0;
}