#include<stdio.h>
#include<string.h>

char *returnPointer(char *ptr, int index){
    int length = strlen(ptr);

    if (index > length){
        return NULL;
    }
    else {
        return ptr+index;
    }
}

int main(){

    char arr[] = "software";

    char *ptr = returnPointer(arr, 2);

    if (ptr == NULL){
        printf("Pointer is NULL");
    }
    else{
        printf("%s",ptr);
    }


    return 0;
}