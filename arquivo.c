#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arquivo.h"

void criar_lista(Lista *lista){
    lista->ini=NULL;
    lista->fim=NULL;
    lista->tam=0;
}

void imprimir(Lista *lista){
    No *aux;
    aux=lista->ini;
    if(lista->ini){
        do{
            printf("Codigo: %d\n",aux->cod);
            printf("Nome: %s\n",aux->nome);
            printf("Preco: %d\n",aux->preco);
            printf("\n");
            aux=aux->proximo;
        }while(aux != NULL);
    }else{
        printf("A lista esta vazia\n");
    }
}

void inserir_ordenado(Lista *lista, int cod, char string[30], int preco){
    No *novo_no=(No*)malloc(sizeof(No));
    No *aux;
    aux=lista->ini;
    int cont=0,igual=0;

    if(lista->ini != NULL){

        do{
            if(aux->cod == cod){
                igual=1;
            }
            aux=aux->proximo;
        }while(aux != NULL);
    }

    if(igual == 0){

    
        if(novo_no){
            novo_no->cod=cod;
            strcpy(novo_no->nome,string);
            novo_no->preco=preco;
            if(lista->ini == NULL){
                novo_no->proximo=NULL;
                lista->ini=novo_no;
                lista->fim=novo_no;
            }
            else if(novo_no->cod < lista->ini->cod){
                novo_no->proximo=lista->ini;
                lista->ini=novo_no;
            }
            else if(novo_no->cod > lista->fim->cod){
                lista->fim->proximo=novo_no;
                lista->fim=novo_no;
                novo_no->proximo=NULL;
            }
            else{
                aux=lista->ini;
                while(novo_no->cod > aux->proximo->cod){
                    aux=aux->proximo;
                }
                novo_no->proximo=aux->proximo;
                aux->proximo=novo_no;
            }
            lista->tam++;
        }
    }else{
        printf("A Lista ja possui um codigo igual, digite um outro\n");
    }
}

No* remover_no_meio(Lista *lista, int loc){
    No *aux, *remover=NULL;
    int cont=0,tam=0;
    aux=lista->ini;

    tam=lista->tam;

    do{
        aux->pos=cont;
        cont++;
        aux=aux->proximo;
    }while(aux != NULL);

    if(loc > tam-1 || loc < 0){
        printf("Falha, posicao invalida\n");
    }
    else{
        aux=lista->ini;
        if(lista->ini){
            if(loc == 0 && aux->pos == loc){
                if(lista->ini == lista->fim){
                    remover=lista->ini;
                    lista->ini=NULL;
                    lista->fim=NULL;
                }
                else{
                    remover=lista->ini;
                    lista->ini=remover->proximo;
                }
            }
            else{
                aux=lista->ini;
                do{
                    if(aux->proximo->pos == loc){
                        if(lista->fim == aux->proximo){
                            remover=aux->proximo;
                            aux->proximo=remover->proximo;
                            lista->fim=aux;
                        }
                        else{
                            remover=aux->proximo;
                            aux->proximo=remover->proximo;
                        }
                    }
                    aux=aux->proximo;
                }while(remover == NULL);
            }
            lista->tam--;
        }
    }
    return remover;
}