#include <stdio.h>

void changeValue(int a, int b){
    int temporaryValue = a;

    a = b;

    b =  temporaryValue;

    printf("a:%d b:%d ",a,b);

}

int main (){
    
    int x = 5, y= 10;

    changeValue(x,y);

    printf("x:%d y:%d ",x,y);

    return 0;
}