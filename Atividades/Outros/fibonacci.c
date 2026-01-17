#include <stdio.h>
#include <stdlib.h>


int fibonacci(int numero) {

    if (numero == 0 || numero == 1) {
        return 1;
    } else {
        return fibonacci(numero - 1) + fibonacci(numero - 2);
    }

}

int main() {

    printf("%d",fibonacci(-1));

    return 0;
}
