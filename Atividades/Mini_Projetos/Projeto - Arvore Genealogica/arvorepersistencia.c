#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvorepersistencia.h"

NoArv* criar_no(char* nome, char* nome_conjuge) {
    NoArv* novo_no = (NoArv*) malloc(sizeof(NoArv));
    if (novo_no != NULL) {
        strcpy(novo_no->nome, nome);
        strcpy(novo_no->nome_conjuge, nome_conjuge);
        novo_no->filho_mais_velho = NULL;
        novo_no->proximo_irmao = NULL;
    }
    return novo_no;
}

NoArv* buscar_no(NoArv* raiz, char* nome) {
    if (raiz == NULL) {
        return NULL;
    }
    if (strcmp(raiz->nome, nome) == 0) {
        return raiz;
    }
    NoArv* no_encontrado = buscar_no(raiz->filho_mais_velho, nome);
    if (no_encontrado != NULL) {
        return no_encontrado;
    }
    return buscar_no(raiz->proximo_irmao, nome);
}

NoArv* inserir_filho(NoArv* pai, char* nome, char* nome_conjuge) {
    if (pai == NULL) {
        return criar_no(nome, nome_conjuge);
    }
    if (pai->filho_mais_velho == NULL) {
        pai->filho_mais_velho = criar_no(nome, nome_conjuge);
    } else {
        NoArv* irmao = pai->filho_mais_velho;
        while (irmao->proximo_irmao != NULL) {
            irmao = irmao->proximo_irmao;
        }
        irmao->proximo_irmao = criar_no(nome, nome_conjuge);
    }
    return pai;
}

void imprimir_arvore(NoArv* raiz, int nivel) {
    if (raiz) {
        for (int i = 0; i < nivel; i++) {
            printf("  ");
        }
        printf("%s - %s\n", raiz->nome, raiz->nome_conjuge);
        imprimir_arvore(raiz->filho_mais_velho, nivel + 1);
        imprimir_arvore(raiz->proximo_irmao, nivel);
    }
}

NoArv* carregaArquivo(NoArv* raiz) {
    FILE* arquivo = fopen("arvore_genealogica.txt", "r");

    if (arquivo == NULL) {
        arquivo = fopen("arvore_genealogica.txt", "w");
        if (arquivo != NULL) fclose(arquivo);
        return NULL;
    }

    char nome[50], nome_conjuge[50], nome_pai[50];

    while (fscanf(arquivo, "%s %s %s", nome, nome_conjuge, nome_pai) != EOF) {
        if (strcmp(nome_pai, "NULL") == 0) {
            raiz = criar_no(nome, nome_conjuge);
        } else {
            NoArv* no_pai = buscar_no(raiz, nome_pai);
            if (no_pai != NULL) {
                inserir_filho(no_pai, nome, nome_conjuge);
            }
        }
    }

    fclose(arquivo);
    return raiz;
}

void salvar_em_ordem(NoArv* raiz, char* nome_pai, FILE* arquivo) {
    if (raiz) {
        fprintf(arquivo, "%s %s %s\n", raiz->nome, raiz->nome_conjuge, nome_pai);

        salvar_em_ordem(raiz->filho_mais_velho, raiz->nome, arquivo);

        salvar_em_ordem(raiz->proximo_irmao, nome_pai, arquivo);
    }
}

void salvar_arvore(NoArv* raiz) {
    FILE* arquivo = fopen("arvore_genealogica.txt", "w");
    if (arquivo == NULL) return;

    salvar_em_ordem(raiz, "NULL", arquivo);
    fclose(arquivo);
}

