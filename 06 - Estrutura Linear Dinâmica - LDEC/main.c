#include <stdio.h>
#include <stdlib.h>
#include "lista_DCircular.h"

int main(){

    LDCCauda cauda = NULL;

    ldc_inserir_fim(&cauda, 10);
    ldc_inserir_inicio(&cauda, 20);
    ldc_inserir_inicio(&cauda, 20);
    ldc_inserir_inicio(&cauda, 30);
    ldc_inserir_inicio(&cauda, 30);
    ldc_inserir_fim(&cauda, 40);

    printf("\nNormal...\n");
    ldc_exibir(cauda);

    printf("\nReverso...\n");
    ldc_exibir_reverso(cauda);

    ldc_atualizar_primeiro(cauda, 20, 15);
    printf("\nNormal...\n");
    ldc_exibir(cauda);

    ldc_remover_valor(&cauda, 30);
    printf("\nNormal...\n");
    ldc_exibir(cauda);

    ldc_remover_valor(&cauda, 20);
    printf("\nNormal...\n");
    ldc_exibir(cauda);

    ldc_limpar(&cauda);
    printf("\nNormal...\n");
    ldc_exibir(cauda);

    return 0;
}
