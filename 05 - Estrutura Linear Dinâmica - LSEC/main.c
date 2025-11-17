#include <stdio.h>
#include <stdlib.h>
#include "listaCircular.h"

int main(){
    LCCauda cauda = NULL;

    lc_inserir_fim(&cauda, 10);
    lc_inserir_inicio(&cauda, 20);
    lc_inserir_inicio(&cauda, 20);
    lc_inserir_inicio(&cauda, 30);
    lc_inserir_inicio(&cauda, 30);
    lc_inserir_fim(&cauda, 40);
    printf("\nDados da lista circular\n");
    lc_exibir(cauda);

    lc_atualizar_primeiro(cauda, 20, 15);
    printf("\nDados da lista circular\n");
    lc_exibir(cauda);

    lc_remover_valor(&cauda, 20);
    printf("\nDados da lista circular\n");
    lc_exibir(cauda);

    printf("\nLimpando a lista circular...\n");
    lc_limpar(&cauda);
    printf("\nDados da lista circular\n");
    lc_exibir(cauda);

    return 0;
}
