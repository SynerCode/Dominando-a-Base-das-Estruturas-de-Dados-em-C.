#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.h"

int main(){

    FilaEstatica* fila = fila_estatica_criar();

    if(fila_estatica_vazia(fila)){
       printf("\nFila Vazia, inserir valor...\n");
    }

    fila_estatica_enfileirar(fila, 10);
    fila_estatica_enfileirar(fila, 20);
    fila_estatica_enfileirar(fila, 30);
    fila_estatica_enfileirar(fila, 40);
    fila_estatica_enfileirar(fila, 50);
    fila_estatica_enfileirar(fila, 60);
    fila_estatica_enfileirar(fila, 70);

    fila_estatica_imprimir(fila);

    int frente;
    if(fila_estatica_frente(fila, &frente)){
        printf("\nFrente atual : %d\n", frente);
    }

    int removido;
    if(fila_estatica_desenfileirar(fila, &removido)){
        printf("\nRemovido : %d\n", removido);
    }

    fila_estatica_imprimir(fila);

    if(fila_estatica_atualizar(fila, 20, 50)){
        printf("\nAtualizado 20 -> 50");
        fila_estatica_imprimir(fila);
    }

    ///0 - 1
    int pos = fila_estatica_buscar(fila, 30);
    printf("\nPosicao de 30 na fila (0 = frente): %d\n\n", pos);


    printf("\nQTDD de elementos da fila: %d\n\n", fila_estatica_tamanho(fila));

    fila_estatica_limpar(fila);
    fila_estatica_imprimir(fila);

    fila_estatica_destruir(fila);


    return 0;
}
