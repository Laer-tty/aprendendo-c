#include <stdio.h>
#include <stdlib.h>

int main(){
    int numeros[5];
    int *p = numeros;

    for (int i = 0; i < 5; i++){
        printf("Digite o %d numero: ",i + 1);
        scanf("%d",p + i);
    }

    for (int i = 0; i < 5; i++){
        printf("%d\n",(*(p + i) * 2));
    }

    return 0;
}
