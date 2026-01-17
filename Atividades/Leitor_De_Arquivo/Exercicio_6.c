#include <stdio.h>
#include <stdlib.h>
//O programa não lê letras com acento e nem ç.
struct Texto{
    char palavra[50];
    int quantidade;
};


int main(){
    struct Texto texto[100];
    FILE *file = fopen("MeuTexto.txt","r");
    char leitura;


    if (file == NULL){
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    int i = 0, total_palavras = 0;
    while (fscanf(file,"%s",texto[i].palavra) == 1){

        for (int j = 0; texto[i].palavra[j] != '\0'; j++){
            if (!isalpha(texto[i].palavra[j])){
                texto[i].palavra[j] = '\0';
                break;
            }
        }
        i++;
        total_palavras++;
    }

    for (int i = 0; i < total_palavras; i++){
        printf("%s ",texto[i].palavra);
    }


return 0;
}
