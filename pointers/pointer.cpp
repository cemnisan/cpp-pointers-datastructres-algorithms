#include<stdio.h>

int main(){

    int a = 5, *ap;
    float b = 3.2, *bp;
    double c = 3.412, *cp;
    char d = 'a', *dp;

    int numbers[5] = {1,2,3,4,5};
    int *arrayp;

    ap = &a;
    bp = &b;
    cp = &c;
    dp = &d;

    arrayp = &numbers[1];

    printf("%p adresindeki int değeri %d dir.\n", ap, *ap);
    printf("%p adresindeki float değeri %f dir.\n", bp, *bp);
    printf("%p adresindeki double değeri %lf dir.\n", cp, *cp);
    printf("%p adresindeki char değeri %c dir.\n", dp, *dp);
    printf("%p adresindeki arrayin 1. index değeri %d dir.\n", arrayp, *arrayp);

    return 0;
}