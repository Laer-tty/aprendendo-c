#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvorepersistencia.h"

void monta_tela() {
    printf("    -----------------------");
    printf("\n\t1 - Ler dados do arquivo\n\t2 - Inserir pessoa na arvore genealogica\n\t3 - Listar arvore genealogica\n\t4 - Sair e Gravar dados do arquivo\n");
    printf("    -----------------------\n\t");
}

void termina_opcao() {
    printf("\n\t<tecle ENTER para continuar>"); getchar(); getchar();
}

void limpa_tela() {
    system("cls");
}

char escolhe_opcao() {
    return getchar();
}

int main() {
    NoArv *raiz = NULL;
    char nome[50], nome_conjuge[50], nome_pai[50], opcao;
    raiz = carregaArquivo(raiz);

    while (1) {
        limpa_tela();
        monta_tela();
        printf("Escolha uma opcao: ");
        opcao = escolhe_opcao();
        switch (opcao) {
            case '1':
                printf("\n\tImpressao da Arvore Genealogica:\n\n");
                imprimir_arvore(raiz, 0);
                termina_opcao();
                break;
            case '2':
                printf("\n\tDigite um nome: ");
                scanf("%s", nome);
                printf("\n\tDigite o nome do conjuge: ");
                scanf("%s", nome_conjuge);
                printf("\n\tDigite o nome do pai (ou NULL se for raiz): ");
                scanf("%s", nome_pai);
                if (strcmp(nome_pai, "NULL") == 0) {
                    raiz = criar_no(nome, nome_conjuge);
                } else {
                    NoArv* pai = buscar_no(raiz, nome_pai);
                    if (pai != NULL) {
                        inserir_filho(pai, nome, nome_conjuge);
                        printf("\tValor inserido com sucesso.\n");
                    } else {
                        printf("\tPai nao encontrado.\n");
                    }
                }
                termina_opcao();
                break;
            case '3':
                printf("\n\tImpressao da Arvore Genealogica:\n\n");
                imprimir_arvore(raiz, 0);
                termina_opcao();
                break;
            case '4':
                salvar_arvore(raiz);
                exit(1);
                break;
            default:
                printf("\n\tOpcao invalida!\n");
                termina_opcao();
                break;
        }
    }
}
