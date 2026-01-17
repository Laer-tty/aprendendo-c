#include <stdio.h>
#include <stdlib.h>

void ordenaVariavel(int *a, int *b, int *c){
    if (*a == *b && *b == *c){
        return 1;
    }

    if (*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    if (*a > *c) {
        int temp = *a;
        *a = *c;
        *c = temp;
    }

    if (*b > *c) {
        int temp = *b;
        *b = *c;
        *c = temp;
    }
    printf("%d,%d,%d", *a,*b,*c);
}

int main(){
    int A, B,C;
    printf("Digite o primeiro numero: ");
    scanf("%d",&A);
    printf("Digite o segundo numero: ");
    scanf("%d",&B);
    printf("Digite o segundo numero: ");
    scanf("%d",&C);

    int *p1 = &A;
    int *p2 = &B;
    int *p3 = &C;

    ordenaVariavel(p1,p2,p3);
    return 0;
}
