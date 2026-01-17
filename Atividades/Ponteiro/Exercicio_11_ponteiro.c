#include <stdio.h>
#include <stdlib.h>

int main(){
    int numeros[5] = {0,6,5,4,1};
    int *p = numeros;

    for (int i = 0; i < 5; i++){

        if (*(p + i) % 2 == 0){
            printf("%d\n",*(p + i));
            printf("%p\n",(p + i));
        }
    }

    return 0;
}
