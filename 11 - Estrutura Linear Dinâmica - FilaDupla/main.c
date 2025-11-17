#include <stdio.h>
#include <stdlib.h>
#include "filaDupla.h"

int main(){
    FilaDupla* fd = filaDupla_criar();

    filaDupla_inserir_frente(fd, 10);
    filaDupla_inserir_frente(fd, 20);
    filaDupla_inserir_frente(fd, 30);
    filaDupla_inserir_traseira(fd, 40);
    filaDupla_inserir_traseira(fd, 50);
    filaDupla_inserir_traseira(fd, 60);
    filaDupla_inserir_frente(fd, 70);

    filaDupla_imprimir(fd);

    int v;

    if(filaDupla_peek_frente(fd, &v)){
        printf("\nInformacao do inicio : %d\n", v);
    }

    if(filaDupla_peek_traseira(fd, &v)){
        printf("\nInformacao do fim : %d\n", v);
    }

    int pos = filaDupla_buscar(fd, 10);

    printf("\nPosicao do valor 10 (0 = frente) : %d\n", pos);

    if(filaDupla_atualizar(fd, 10, 99)){
        printf("\nValor 10 atualizado por 99...\n");
        filaDupla_imprimir(fd);
    }

    if(filaDupla_remover_frente(fd, &v)){
        printf("\nValor removido Frente : %d\n", v);
        filaDupla_imprimir(fd);
    }

    if(filaDupla_remover_traseira(fd, &v)){
        printf("\nValor removido Tras : %d\n", v);
        filaDupla_imprimir(fd);
    }

    filaDupla_limpar(fd);
    filaDupla_imprimir(fd);

    filaDupla_destruir(fd);


    return 0;
}
