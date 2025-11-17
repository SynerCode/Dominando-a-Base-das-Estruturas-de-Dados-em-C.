#include <stdio.h>
#include <stdlib.h>
#include "listaDE.h"

int main(){

    NoDuplo* lista = NULL;

    ld_inserir_inicio(&lista, 10);
    ld_inserir_fim(&lista, 20);
    ld_inserir_fim(&lista, 20);
    ld_inserir_fim(&lista, 40);
    ld_inserir_fim(&lista, 40);
    printf("\nFrente.\n");
    ld_exibir_frente(lista);

    NoDuplo* cauda = ld_obter_cauda(lista);
    printf("\nTras.\n");
    ld_exibir_tras(cauda);

    printf("\nAtualizando.\n");
    ld_atualizar_primeiro(lista, 20, 35);
    ld_exibir_frente(lista);


    ld_remover_valor(&lista, 20);
    printf("\nRemovendo.\n");
    printf("\nFrente.\n");
    ld_exibir_frente(lista);
    printf("\nTras.\n");
    ld_exibir_tras(cauda);

    ld_limpar(&lista);
    printf("\nFrente.\n");
    ld_exibir_frente(lista);

    return 0;
}
