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

}

void iniserir(ArvB *arv, int valor){
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
            inserirEsq(arv->raiz, valor); /**/
        }

        else {
            inserirDir(arv->raiz, valor);
        }
    }
}