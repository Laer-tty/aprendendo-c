
typedef struct no NoArv;

typedef struct no {
    char nome[50];
    char nome_conjuge[50];
    struct NoArv* filho_mais_velho;
    struct NoArv* proximo_irmao;
};

NoArv* criar_no(char* nome, char* nome_conjuge);
NoArv* buscar_no(NoArv* raiz, char* nome);
NoArv* inserir_filho(NoArv* pai, char* nome, char* nome_conjuge);
void imprimir_arvore(NoArv* raiz, int nivel);

NoArv* carregaArquivo(NoArv* raiz);
void salvar_arvore(NoArv* raiz);
