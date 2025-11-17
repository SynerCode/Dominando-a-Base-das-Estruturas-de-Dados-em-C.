#include <stdio.h>
#include <stdlib.h>
#include "pilhaLista.h"

int main(){

    PilhaLista* p = pilha_lista_criar();

    if(pilha_lista_vazia(p)){
        printf("\nPilha Vazia....\n");
    }

    pilha_lista_empilhar(p, 10);
    pilha_lista_empilhar(p, 20);
    pilha_lista_empilhar(p, 30);
    pilha_lista_empilhar(p, 40);
    pilha_lista_imprimir(p);

    int topo;
    if(pilha_lista_topo(p, &topo)){
       printf("\nTopo atual : %d\n", topo);
    }
    pilha_lista_imprimir(p);

    pilha_lista_atualizar_topo(p, 80);
    printf("\nPilha depois de atualizar...\n");
    pilha_lista_imprimir(p);

    int pos = pilha_lista_buscar(p, 25);
    printf("\nBusca por 25 : %s (pos %d).\n", (pos >= 0) ? "encontrado" : "nao encontrado", pos);

    int v;
    while(pilha_lista_desempilhar(p, &v)){
        printf("\nDesempilhando : %d.", v);
    }

    pilha_lista_destruir(p);

    return 0;
}
