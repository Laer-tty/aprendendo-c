#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Aluno{
    int sequencial;
    int matricula;
    char nome[50];
};

void carregar_Dados(){
    FILE *file = fopen("Relacao_aluno.txt","r");
    char linha[100];

    printf("-----------------------------\n");
    if (file == NULL){
        printf("Erro ao abrir o arquivo.");

        exit(1);
    }
    while (fgets(linha, sizeof(linha), file)){
        printf("%s", linha);
    }

    fclose(file);
}

void cadastrar_Aluno(){
    FILE *file = fopen("Relacao_aluno.txt","a");
    FILE *file2 = fopen("Relacao_aluno.txt","r");
    struct Aluno al;
    al.sequencial = 0;
    int maior_sequencial = 0;

    if (file == NULL){
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    while (fscanf(file2,"%d %d %s", &al.sequencial, &al.matricula, al.nome) == 3){
        if (al.sequencial > maior_sequencial){
            maior_sequencial = al.sequencial;
        }
    }

    printf("-----------------------------\n");
    printf("Digite a matricula do aluno: ");
    scanf("%d",&al.matricula);

    printf("Digite o nome do aluno: ");
    scanf("%*c");
    fgets(al.nome, 50, stdin);

    al.sequencial = maior_sequencial  + 1;
    fprintf(file,"%d %d %s",al.sequencial,al.matricula, al.nome);

    fclose(file2);
    fclose(file);
    printf("Aluno cadastrado.");
}

void editar_Aluno(){
    struct Aluno al;
    int matricula;
    int escolha;
    int aluno_encontrado = 0;
    FILE *file = fopen("Relacao_aluno.txt","r");
    FILE *tempFile = fopen("temp.txt","w");

    if (file == NULL){
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    printf("Digite a matricula do aluno que voce quer editar: ");
    scanf("%d",&matricula);

    while (fscanf(file,"%d %d %s", &al.sequencial, &al.matricula, al.nome) == 3){
        if (matricula == al.matricula){
            aluno_encontrado++;
            printf("1 - Sequencial\n2 - Matricula\n3 - Nome\nO que voce deseja editar? ");
            scanf ("%d",&escolha);

            switch(escolha){
            case 1:
                printf("Digite o novo valor para Sequencial: ");
                scanf("%d", &al.sequencial);
                break;
            case 2:
                printf("Digite o novo valor para Matricula: ");
                scanf("%d", &al.matricula);
                break;
            case 3:
                printf("Digite o novo valor para Nome: ");
                scanf("%s", &al.nome);
                break;
            default:
                printf("Valor invalido.\n");
                break;
            }
        }
        fprintf(tempFile, "%d %d %s\n", al.sequencial, al.matricula, al.nome);
    }
    if (aluno_encontrado){
        printf("Edicao concluida.");
    } else {
        printf("Matricula nao encontrada.");
    }
    fclose(file);
    fclose(tempFile);

    remove("Relacao_aluno.txt");
    rename("temp.txt", "Relacao_aluno.txt");
}

void deletar_Aluno(){
    struct Aluno al;
    int matricula;
    int aluno_encontrado = 0;
    FILE *file = fopen("Relacao_aluno.txt","r");
    FILE *tempFile = fopen("temp_file.txt", "w");

    if (file == NULL){
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    printf("Digite a matricula do aluno que voce quer editar: ");
    scanf("%d",&matricula);

    while (fscanf(file,"%d %d %s", &al.sequencial, &al.matricula, al.nome) == 3){
        if (matricula != al.matricula){
            fprintf(tempFile, "%d %d %s\n", al.sequencial, al.matricula, al.nome);
        } else {
            aluno_encontrado++;
        }
    }

    if (aluno_encontrado){
        printf("Remocao concluida.");
    } else {
        printf("Matricula nao encontrada.");
    }
    fclose(file);
    fclose(tempFile);

    remove("Relacao_aluno.txt");
    rename("temp_file.txt", "Relacao_aluno.txt");
}

void ordenar_Alunos(){
    struct Aluno al[100];
    int escolha;
    int i,j,aux_int;
    char aux_str[50];
    FILE *file = fopen("Relacao_aluno.txt","r");
    FILE *file_temp = fopen("temp.txt", "w");

    if (file == NULL){
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }

    printf("1 - Ordenar por Sequencial\n2 - Ordenar por Matricula\n3 - Ordenar por Nome\nPor qual maneira voce deseja ordenar? ");
    scanf("%d", &escolha);

    int num_alunos = 0;
    while (fscanf(file,"%d %d %s", &al[num_alunos].sequencial, &al[num_alunos].matricula, al[num_alunos].nome) == 3){
        num_alunos++;
    }

    for (i = 0; i < num_alunos - 1; i++) {
        for (j = i + 1; j < num_alunos; j++) {
            switch (escolha){
            case 1:
                if (al[i].sequencial > al[j].sequencial) {
                    aux_int = al[i].sequencial;
                    al[i].sequencial = al[j].sequencial;
                    al[j].sequencial = aux_int;
                }
                break;
            case 2:
                if (al[i].matricula > al[j].matricula) {
                    aux_int = al[i].matricula;
                    al[i].matricula = al[j].matricula;
                    al[j].matricula = aux_int;
                }
                break;
            case 3:
                if (strcmp(al[i].nome, al[j].nome) > 0) {
                    strcpy(aux_str, al[i].nome);
                    strcpy(al[i].nome, al[j].nome);
                    strcpy(al[j].nome, aux_str);
                }
                break;
            default:
                printf("Valor invalido.");
                break;
            }
        }
    }
    for (i = 0; i < num_alunos; i++) {
        fprintf(file_temp, "%d %d %s\n", al[i].sequencial, al[i].matricula, al[i].nome);
    }
    printf("Alunos Ordenados.");

    fclose(file);
    fclose(file_temp);
    remove("Relacao_aluno.txt");
    rename("temp.txt", "Relacao_aluno.txt");
}

void pesquisar_Aluno(){
    struct Aluno al;
    int escolha;
    char nome_aluno[50];
    int matricula_aluno;
    int aluno_encontrado = 0;
    FILE *file = fopen("Relacao_aluno.txt","r");

    if (file == NULL){
        printf("Erro ao abrir o arquivo.");
        exit(1);
    }
    printf("-----------------------------\n");
    printf("1 - Pesquisar por Nome\n2 - Pesquisar por Matricula\nO que voce deseja fazer? ");
    scanf("%d", &escolha);

    switch (escolha){
    case 1:
        printf("Qual o nome do aluno que voce deseja pesquisar? ");
        scanf("%s",nome_aluno);

        while (fscanf(file,"%d %d %s", &al.sequencial, &al.matricula, al.nome) == 3){
            if (strcmp(nome_aluno, al.nome) == 0){
                printf("Aluno encontrado.\n");
                printf("Sequencial: %d Matricula: %d  Nome: %s",al.sequencial,al.matricula,al.nome);
                aluno_encontrado++;
            }
        }
        if (!aluno_encontrado){
            printf("Aluno nao encontrado.");
        }
        fclose(file);
        break;
    case 2:
        printf("Qual a matricula do aluno que voce deseja pesquisar? ");
        scanf("%d",&matricula_aluno);

        while (fscanf(file,"%d %d %s", &al.sequencial, &al.matricula, al.nome) == 3){
            if (matricula_aluno == al.matricula){
                printf("Aluno encontrado.\n");
                printf("Sequencial: %d  Matricula: %d  Nome: %s",al.sequencial,al.matricula,al.nome);
                aluno_encontrado++;
            }
        }
        if (!aluno_encontrado){
            printf("Aluno nao encontrado.");
        }
        fclose(file);
        break;
    default:
        printf("Valor invalido.");
        break;
    }
}

int main(){
    int escolha;
    struct Aluno a1;

    while (escolha != 9){

        printf("\n-----------------------------");
        printf("\n0 - Carregar dados do arquivo\n1 - Cadastrar aluno\n2 - Editar aluno\n3 - Deletar aluno\n4 - Ordenar alunos\n5 - Pesquisar aluno\n9 - Gravar e sair\n");
        printf("O que voce deseja fazer? ");
        scanf("%d",&escolha);

        switch(escolha){
        case 0:
            carregar_Dados();
            break;
        case 1:
            cadastrar_Aluno();
            break;
        case 2:
            editar_Aluno();
            break;
        case 3:
            deletar_Aluno();
            break;
        case 4:
            ordenar_Alunos();
            break;
        case 5:
            pesquisar_Aluno();
            break;
        case 9:
            break;
        default:
            printf("Valor invalido.\n");
            break;
        }
    }
    return 0;
}
