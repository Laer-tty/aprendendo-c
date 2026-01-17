#include <stdio.h>
#include <stdlib.h>

int fatorial(int numero) {

    if (numero <= 1) {
        return 1;
    } else {
        return numero * fatorial(numero - 1);
    }
}

int main() {

    printf("%d",fibonacci(3));

    return 0;
}
