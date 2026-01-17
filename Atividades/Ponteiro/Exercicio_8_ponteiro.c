#include <stdio.h>
#include <stdlib.h>

int main(){
    float numeros[10];
    float *p = numeros;

    for (int i = 0; i < 10; i++){
        printf("%p\n", (p+i));
    }

    return 0;
}
