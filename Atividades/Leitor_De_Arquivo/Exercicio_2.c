#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//o programa não lê letras com acento e nem ç.
int main(){
    FILE *file = fopen("texto.txt","r");
    char leitura;
    int letra_contador[26] = {0};

    if (file == NULL){
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    while (fscanf(file," %c", &leitura) == 1){
        leitura = tolower(leitura); //converte todas as letras que serão lidas para minusculo.
        letra_contador[leitura - 'a']++; //converte o char em int.
    }
    char letra = 'A';
    for (int i = 0;i < 26;i++){
        printf("%c: %d\n",letra,letra_contador[i]);
        letra++;
    }

    fclose(file);
    return 0;
}
