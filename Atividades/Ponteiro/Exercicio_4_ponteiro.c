#include <stdio.h>
#include <stdlib.h>

void trocaVariaveis(int *p1, int *p2){
    int aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

int main(){
    int num1, num2;
    printf("Digite o primeiro numero: ");
    scanf("%d",&num1);
    printf("Digite o segundo numero: ");
    scanf("%d",&num2);

    int *p1 = &num1;
    int *p2 = &num2;
    trocaVariaveis(p1, p2);

    printf("numero 1: %d numero 2: %d",num1, num2);
    return 0;
}
