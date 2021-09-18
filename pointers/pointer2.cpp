#include<stdio.h>

int main() {

    int i,j = 1;
    int *jp1,*jp2 = &j;

    jp1 = jp2;

    i = ++(*jp2);

    *jp2 = *jp1 +i;

    printf("i = %d , j = %d, *jp1 = %d *jp2 = %d\n",i,j,*jp1,*jp2);

    return 0;
}