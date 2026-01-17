#include <stdio.h>
#include <stdlib.h>

int main(){
    int num1, num2;
    printf("Digite o primeiro numero: ");
    scanf("%d",&num1);
    printf("Digite o segundo numero: ");
    scanf("%d",&num2);

    int *p1 = &num1;
    int *p2 = &num2;

    if (p1 > p2){
        printf("%x e maior que %x", p1, p2);
    } else {
        printf("%x e maior que %x", p2, p1);
    }

    return 0;
}
