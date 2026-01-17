#include <stdio.h>
#include <stdlib.h>

int main(){
    int inteiro = 5;
    float real = 10.5;
    char caractere = 'a';

    int *p1 = &inteiro;
    float *p2 = &real;
    char *p3 = &caractere;

    printf("%d %.1f %c",*p1,*p2,*p3);
    printf("\n%x %x %x",p1,p2,p3);

    *p1 = 8;
    *p2 = 15;
    *p3 = 'c';

    printf("\n%d %.1f %c",*p1,*p2,*p3);
    printf("\n%x %x %x",p1,p2,p3);

    return 0;
}
