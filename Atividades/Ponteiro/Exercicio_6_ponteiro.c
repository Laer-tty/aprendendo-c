#include <stdio.h>
#include <stdlib.h>

void somaDobroVariaveis(int *p1, int *p2){
    *p1 = *p1 * 2;
    *p2 = *p2 * 2;
    printf("A soma do dobro dos numeros e: %d. (%d + %d)", (*p1 + *p2), *p1, *p2);
}

int main(){
    int A, B;
    printf("Digite o primeiro numero: ");
    scanf("%d",&A);
    printf("Digite o segundo numero: ");
    scanf("%d",&B);

    int *p1 = &A;
    int *p2 = &B;

    somaDobroVariaveis(p1,p2);
    return 0;
}
