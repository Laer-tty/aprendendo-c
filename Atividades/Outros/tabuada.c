#include <stdio.h>
#include <stdlib.h>


int main() {
    int numero,soma,multiplicacao;
    printf("     -------------------------\n");
    printf("\tDigite um numero: ");
    scanf("%d",&numero);
    printf("     -------------------------\n");

    printf("\tTABUADA DE ADICAO\tTABUADA DE SUBTRACAO\tTABUADA DE MULTIPLICACAO\tTABUADA DE DIVISAO\n");
    for (int i = 1; i <= 10; i++) {
        soma = i + numero;
        multiplicacao = numero * i;
        printf("\t  %d + %d = %d\t\t     %d - %d = %d\t\t%d * %d = %d\t\t    %d / %d = %d\n",
               numero,i,soma,
               soma,numero,i,
               numero,i,multiplicacao,
               multiplicacao,numero,i
               );
    }

    return 0;
}
