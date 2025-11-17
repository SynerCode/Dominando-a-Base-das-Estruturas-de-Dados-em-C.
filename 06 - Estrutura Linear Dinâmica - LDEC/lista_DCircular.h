#ifndef LISTA_DCIRCULAR_H
#define LISTA_DCIRCULAR_H
#include <stdbool.h>

typedef struct NoDuploCircular{
    int dado;
    struct NoDuploCircular* prox;
    struct NoDuploCircular* ant;
}NoDuploCircular;

typedef NoDuploCircular* LDCCauda;

void ldc_inserir_inicio(LDCCauda* cauda, int valor);
void ldc_inserir_fim(LDCCauda* cauda, int valor);
NoDuploCircular* ldc_buscar(LDCCauda cauda, int valor);
bool ldc_atualizar_primeiro(LDCCauda cauda, int antigo, int novo);
bool ldc_remover_valor(LDCCauda* cauda, int valor);
void ldc_exibir(LDCCauda cauda);
void ldc_exibir_reverso(LDCCauda cauda);
void ldc_limpar(LDCCauda* cauda);

#endif // LISTA_DCIRCULAR_H
