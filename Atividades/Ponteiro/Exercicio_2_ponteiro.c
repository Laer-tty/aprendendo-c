#include <stdio.h>
#include <stdlib.h>

int main(){
    float num1 = 5.7;
    float num2 = 10.5;

    float *p1 = &num1;
    float *p2 = &num2;

    if (p1 > p2){
        printf("%x e maior que %x", p1,p2);
    } else {
        printf("%x e maior que %x", p2,p1);
    }

    return 0;
}
