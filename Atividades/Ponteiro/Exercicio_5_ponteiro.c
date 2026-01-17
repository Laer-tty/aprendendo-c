#include <stdio.h>
#include <stdlib.h>

void maiorMenorVariaveis(int *p1, int *p2){
    if (*p1 > *p2){
        printf("Maior: %d Menor: %d", *p1, *p2);
    } else {
        printf("Maior: %d Menor: %d", *p2, *p1);
    }
}


int main(){
    int num1, num2;
    printf("Digite o primeiro numero: ");
    scanf("%d",&num1);
    printf("Digite o segundo numero: ");
    scanf("%d",&num2);

    int *p1 = &num1;
    int *p2 = &num2;

    maiorMenorVariaveis(p1,p2);
    return 0;
}
