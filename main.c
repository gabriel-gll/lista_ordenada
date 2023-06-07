#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"arquivo.h"

int main(){
    Lista *lista=(Lista*)malloc(sizeof(Lista));
    No *removido=NULL;
    int loc=0;
    int cod=0,preco=0,n=0;
    char string[30];

    criar_lista(lista);

    printf("\nA Lista e programada para ser ordenada em relacao ao numero do codigo do item (do menor codigo do intem para o maior)\n\n");

    do{
        printf("Escolha entre opcao 0 (encerrar programa) | opcao 1 (inserir ordenado) | opcao 2 (remover em posicao) | opcao 3 (imprimir)\n");
        scanf("%d",&n);
        printf("\n");
        switch(n){
            case 0:
                printf("Esta e a saida do programa\n");
                break;
            case 1:
                printf("\n(OBS: A Lista sempre ficara ordenada, nao importando a ordem em que seja inserida os numeros de codigo dos itens)\n");
                printf("Insira o codigo do item\n");
                scanf("%d",&cod);
                printf("Informe o nome do item\n");
                fflush(stdin);
                gets(string);
                fflush(stdin);
                printf("Informe o preco do item\n");
                scanf("%d",&preco);
                inserir_ordenado(lista,cod,string,preco);
                printf("\n");
                break;
            case 2:
                printf("\nDigite em qual posicao a remocao sera realizada (OBS: A primeira posicao e a posicao 0)\n");
                printf("Estado da Lista atual: \n\n");
                imprimir(lista);
                scanf("%d",&loc);
                removido=remover_no_meio(lista,loc);
                if(removido != NULL){
                    printf("Foi removido o item de codigo: %d | nome: %s | preco: %d\n",removido->cod,removido->nome,removido->preco);
                }
                printf("\n");
                break;
            case 3:
                printf("\n");
                imprimir(lista);
                printf("\n");
                break;
            default:
                printf("Opcao invalida,digite novamente\n");
        }
    }while(n != 0);
    return 0;
}