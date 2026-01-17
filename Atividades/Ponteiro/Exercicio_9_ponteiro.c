#include <stdio.h>
#include <stdlib.h>

int main(){
    float numeros[3][3] = {1,2,3,4,5,6,7,8,9};
    float *p = numeros;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%p\n", (p + (i * 3) + j));
        }
    }

    return 0;
}
