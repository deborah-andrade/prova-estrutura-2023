#include <stdio.h>
#include <stdlib.h>
#include "estudo.h"
#include "estudo.c"

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