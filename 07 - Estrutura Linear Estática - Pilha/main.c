#include <stdio.h>
#include <stdlib.h>
#include "pilhaArray.h"

int main(){

    PilhaArray* p = pilha_array_criar();

    if(pilha_array_vazia(p)){
        printf("\nA pilha esta vazia....\n");
    }

    pilha_array_empilhar(p, 10);
    pilha_array_empilhar(p, 20);
    pilha_array_empilhar(p, 30);
    pilha_array_empilhar(p, 40);

    if(pilha_array_cheia(p)){
        printf("\nA pilha esta cheia....\n");
    }
    else{
        printf("\nA pilha NAO esta cheia....\n");
    }

    pilha_array_empilhar(p, 50);

    if(pilha_array_cheia(p)){
        printf("\nA pilha esta cheia....\n");
    }
    else{
        printf("\nA pilha NAO esta cheia....\n");
    }

    pilha_array_imprimir(p);


    int topo;
    if(pilha_array_topo(p, &topo)){
        printf("\nTopo atual : %d", topo);
    }

    int pos = pilha_array_buscar(p, 55);
    printf("\nBusca por 55 : %s (indice: %d)\n", (pos >= 0) ? "encontrado" : "nao encontrado", pos);


    int v;

    while(pilha_array_desempilhar(p, &v)){
        printf("\nDesempilhando: %d", v);
    }

    pilha_array_destruir(p);
    printf("\nDepois da destruicao....\n");
    pilha_array_imprimir(p);

    return 0;
}
