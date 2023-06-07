
typedef struct no No;

struct no{
    int cod;
    char nome[30];
    int preco;
    int pos;
    struct no *proximo;
};

typedef struct lista Lista;

struct lista{
    struct no *ini;
    struct no *fim;
    int tam;
};

void criar_lista(Lista *lista);

void inserir_ordenado(Lista *lista, int cod, char string[30], int preco);

void imprimir(Lista *lista);

No* remover_no_meio(Lista *lista, int loc);