#include <stdio.h>
#include <stdlib.h>

void mudaVariavel(int *p1, int *p2){
    *p1 = *p1 + *p2;
}

int main(){
    int A, B;
    printf("Digite o primeiro numero: ");
    scanf("%d",&A);
    printf("Digite o segundo numero: ");
    scanf("%d",&B);

    int *p1 = &A;
    int *p2 = &B;

    mudaVariavel(p1,p2);
    printf("Primeiro numero: %d\nSegundo numero: %d", A, B);
    return 0;
}
