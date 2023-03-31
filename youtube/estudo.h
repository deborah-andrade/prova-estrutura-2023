#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int conteudo;
    struct no *esq, *dir;
}No;

typedef struct{
    No *raiz;  /*começo da arvore, a raiz*/
}ArvB;

void iniserir(ArvB *arv, int valor);
void inserirEsq(No *no, int valor);
void inserirDir(No *no, int valor);
void imprimir(No *raiz);