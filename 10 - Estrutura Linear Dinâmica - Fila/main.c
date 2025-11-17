#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

int main(){
    FilaDinamica* f = fila_dinamica_criar();

    if(fila_dinamica_vazia(f)){
        printf("\nFila vazia....\n");
    }

    fila_dinamica_enfileirar(f, 10);
    fila_dinamica_enfileirar(f, 20);
    fila_dinamica_enfileirar(f, 30);
    fila_dinamica_enfileirar(f, 40);

    fila_dinamica_imprimir(f);

    int frente;
    if(fila_dinamica_frente(f, &frente)){
        printf("\nDado inicial da fila : %d\n", frente);
    }

    int rem;
    if(fila_dinamica_desenfileirar(f, &rem)){
        printf("\nFoi removido o valor : %d\n", rem);
    }

    fila_dinamica_imprimir(f);

    if(fila_dinamica_atualizar(f, 20, 55)){
        printf("\nAtualizando 20 -> 55...\n");
        fila_dinamica_imprimir(f);
    }

    int pos = fila_dinamica_buscar(f, 30);
    printf("\nPosicao do valor 30 : %d\n", pos);

    int tamanho = fila_dinamica_tamanho(f);
    printf("\nQTDD de elementos da fila : %d\n", tamanho);

    fila_dinamica_limpar(f);

    if(fila_dinamica_vazia(f)){
        printf("\nFila vazia....\n");
    }

    fila_dinamica_destruir(f);

    return 0;
}
