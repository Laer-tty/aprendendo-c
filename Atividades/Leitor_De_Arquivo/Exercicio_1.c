#include <stdio.h>
#include <stdlib.h>

int main(){
    int pessoas;
    char sexo;
    char nome[20];
    int idade;


    FILE *file = fopen("Exercicio_1.txt","w");

    if (file == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    printf("Quantas pessoas voce quer cadastrar? ");
    scanf("%d",&pessoas);

    for(int i = 0;i < pessoas;i++){
        printf("---------------------------");

        printf("\nQual o seu sexo? (M/F) ");
        scanf(" %c",&sexo);

        printf("\nQual o seu primeiro nome? ");
        scanf("%s",nome);

        printf("\nQual a sua idade? ");
        scanf("%d",&idade);

        fprintf(file, "%c %s %d\n", sexo, nome, idade);
    }
    fclose(file);
    return 0;
}
