#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char cargo[20];
    int num_candidato;
    char nome[80];
    char partido[10];
    long quantidade_votos;
} candidato;
typedef candidato elemento;

/* DECLARACOES GLOBAIS DE CONSTANTES */
const elemento VL_NULO = {"", 0, "", "", 0};

#include "tad_lst2.h"
#include "persistencia.h"

tipo_lista lista;

void monta_tela() {
    printf("\n1 - ler arquivo");
   	printf("\n2 - listar candidatos com quantidade de votos");
   	printf("\n3 - cadastrar candidato");
   	printf("\n4 - editar candidato");
   	printf("\n5 - excluir candidato");
   	printf("\n6 - votar candidato");
   	printf("\n9 - salvar e sair\n");
}

char escolhe_opcao() {
    char op;
    scanf(" %c", &op);
	return op;
}

int posicao(int tam) {
	int pos;
	if (tam > 0) {
   		do {
			printf("\nDigite a posicao: ");
         		scanf("%d",&pos);
      		} while ((pos<0) || (pos>lista.tamanho+1));
	return pos;
   }
   else
      	return 1;
}

int limpa_tela() {
	system("cls");
}

int entra_cargo(char *cargo) {
	printf("\nQual o cargo do candidato? "); scanf("%s", cargo);
}

int entra_num_candidato(int *num_candidato) {
	printf("\nQual o numero do candidato? "); scanf("%d", num_candidato);
}

int entra_nome(char *nome) {
	printf("\nQual o nome do candidato? "); scanf("%s", nome);
}

int entra_partido(char *partido) {
    printf("\nQual o partido do candidato? "); scanf("%s", partido);
}

void incluir() {
	int pos; elemento elem=VL_NULO;
	limpa_tela();
    entra_cargo(elem.cargo);
	entra_num_candidato(&elem.num_candidato);
	entra_nome(&elem.nome);
	entra_partido(&elem.partido);
	pos = posicao(tamanho(lista));
   	if (incluir_elemento(&lista,pos,elem))
       		printf("Candidato incluido com sucesso!");
	getchar();
}

void listar() {
	int i, tam; elemento elem;
	limpa_tela(); printf("\n");
   tam = tamanho(lista);
   if (tam > 0) {
	   for (i=1;i<=tam;i++) {
	      if (obter_elemento(lista,i,&elem))
	         printf("\n%d - %s - %d - %s - %s - %ld", i, elem.cargo, elem.num_candidato, elem.nome, elem.partido, elem.quantidade_votos);
      }
   }
   else
      printf("Lista vazia");
   printf("\n<tecle ENTER para continuar>");getchar();getchar();
}

void urna() {
	int i, tam; elemento elem;
	limpa_tela(); printf("\n");
   tam = tamanho(lista);
   if (tam > 0) {
	   for (i=1;i<=tam;i++) {
	      if (obter_elemento(lista,i,&elem))
	         printf("\n%d - Nome: %s - Numero: %d - Cargo: %s", i, elem.nome, elem.num_candidato, elem.cargo);
      }
   }
   else
      printf("Lista vazia.");
   printf("\n<tecle ENTER para continuar>");getchar();getchar();
}

void listar_candidatos_votos() {
	int i, tam; elemento elem;
    limpa_tela(); printf("\n");
   tam = tamanho(lista);
   if (tam > 0) {
	   for (i=1;i<=tam;i++) {
	      if (obter_elemento(lista,i,&elem))
	         printf("\n%d - Nome do candidato: %s - Votos: %d", i,elem.nome, elem.quantidade_votos);
      }
   }
   else
      printf("Lista vazia");
   printf("\n<tecle ENTER para continuar>");getchar();getchar();
}

void alterar() {
	int pos; elemento elem=VL_NULO;
	limpa_tela();
	listar();
	pos = posicao(tamanho(lista));
	entra_cargo(&elem.cargo);
	entra_num_candidato(&elem.num_candidato);
	entra_nome(&elem.nome);
	entra_partido(&elem.partido);
   	if (alterar_elemento(&lista,pos,elem))
       		printf("Elemento alterado com sucesso!");
	getchar();
}

void excluir() {
	int pos;
	limpa_tela();
	listar();
	pos = posicao(tamanho(lista));
	if (excluir_elemento(&lista,pos))
       		printf("Elemento excluído com sucesso!");
	getchar();
}

void vota_candidato() {
    int voto,tam,i,candidato_encontrado = 0;elemento elem = VL_NULO;
    tam = tamanho(lista);
    limpa_tela();
    urna();

    if (tam > 0) {
        printf("\nDigite o codigo do candidato que voce deseja votar: ");
        scanf("%d",&voto);

        for (i=1;i<=tam;i++) {
            obter_elemento(lista,i,&elem);
            if (elem.num_candidato == voto) {
                printf("\nVoce votou no candidato: %s",elem.nome);
                elem.quantidade_votos++;
                candidato_encontrado = 1;
                alterar_elemento(&lista,i,elem);
                printf("\n<tecle ENTER para continuar>");getchar();getchar();
            }
        }

        if (!candidato_encontrado) {
            printf("\nCandidato nao encontrado.");
            printf("\n<tecle ENTER para continuar>");getchar();getchar();
        }
    }
}

int main() {
	char opcao;
	inicializa_lista(&lista);
	carregar_lista(&lista);
   do {
        limpa_tela();
   	    monta_tela();
        opcao = escolhe_opcao();
   	switch (opcao) {
      	case '1':
         	 listar();
           break;
        case '2':
             listar_candidatos_votos();
           break;
      	case '3':
         	 incluir();
           break;
      	case '4':
        	 alterar();
           break;
      	case '5':
         	 excluir();
           break;
        case '6':
             vota_candidato();
             break;
         case '9':
	         gravar_lista(lista);
         	 exit(1);
           break;
      }
   } while (1);
}
