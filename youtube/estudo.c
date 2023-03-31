#include <stdio.h>
#include <stdlib.h>
#include "estudo.h"



void inserirEsq(No *no, int valor){ /*confere primeiro se tem algo na esquerda*/
     if (no->esq == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no->esq = novo;
    }
    else {
        if (valor < no->esq->conteudo){
            inserirEsq(no->esq, valor);
        }
        else {
            inserirDir(no->esq, valor);
        }
        
    }
}

void inserirDir(No *no, int valor){
    if (no->dir == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no->dir = novo;
    }
    else {
        if (valor > no->dir->conteudo){
            inserirDir(no->dir, valor);
        }
        else {
            inserirEsq(no->dir, valor);
         }
     }

}

void inserir(ArvB *arv, int valor){
    if (arv->raiz == NULL) {
        No *novo = (No*)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        arv->raiz = novo; 
 /*isso é para raiz for nula, recebendo seu primeiro no*/
    }
    
    else { /*se o valor q vou adc for menor que o da raiz, irei para a esquerda */
        if (valor< arv->raiz->conteudo) {
            inserirEsq(arv->raiz, valor);
        }

        else {
            inserirDir(arv->raiz, valor);
        }
    }
}

void imprimir(No *raiz){
    if (raiz != NULL) {
        imprimir(raiz->esq);
        printf("%d ", raiz->conteudo);
        imprimir(raiz->dir);  //(*raiz.esquerda )
    }
}

int main(){
    int op, valor;
    ArvB arv;
    arv.raiz = NULL; /*usa ponto pois não ha ponteiros, fazendo manipulação de objetos. é ponteiro, usa seta, não é usa ponto */

    do
    {
        printf("\n0- sair\n1-inserir\n2-imprimir\n");
        scanf("%d", &op);


        switch (op) {
            case 0: 
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserir(&arv, valor);
                break;
            case 2:
                imprimir(arv.raiz);
         }
    } while (op != 0);
    
}