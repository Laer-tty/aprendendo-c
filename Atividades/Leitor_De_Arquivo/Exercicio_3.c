#include <stdio.h>
#include <stdlib.h>

struct Pessoa{
    char nome[50];
    char endereco[100];
    int idade;
    char telefone[15];
    struct Data {
        int dia;
        int mes;
        int ano;
    }data_nascimento;
};

int main(){
    FILE *file = fopen("Registro_pessoa.txt","w");
    int n;

    if (file == NULL){
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    printf("Quantas pessoas voce quer cadastrar? ");
    scanf("%d", &n);
    struct Pessoa pessoa[n];

    for (int i = 0; i < n;i++){

        printf("Digite seu nome completo: \n");
        scanf("%*c");
        fgets(pessoa[i].nome, 50, stdin);

        printf("Digite seu endereco: \n");
        fgets(pessoa[i].endereco, 100, stdin);


        printf("Digite sua idade: \n");
        scanf("%d", &pessoa[i].idade);

        printf("Digite seu telefone: (Ex: ## #####-####)\n");
        scanf("%*c");
        fgets(pessoa[i].telefone, 15, stdin);

        printf("Digite sua data de nascimento. (Ex: DD MM AAAA)\n");
        scanf("%d %d %d", &pessoa[i].data_nascimento.dia, &pessoa[i].data_nascimento.mes, &pessoa[i].data_nascimento.ano);

        printf("------------------------\n");

        fprintf(file,"Nome: %s", pessoa[i].nome);
        fprintf(file,"Endereco: %s", pessoa[i].endereco);
        fprintf(file,"Idade: %d\n", pessoa[i].idade);
        fprintf(file,"Telefone: %s", pessoa[i].telefone);
        fprintf(file,"Data de Nascimento: %d/%d/%d\n", pessoa[i].data_nascimento.dia, pessoa[i].data_nascimento.mes, pessoa[i].data_nascimento.ano);
        fprintf(file,"------------------------\n");
    }
    fclose(file);
    return 0;
}
