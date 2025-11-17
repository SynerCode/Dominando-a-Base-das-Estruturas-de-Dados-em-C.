#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include <stdbool.h>

typedef struct NoCircular{
    int dado;
    struct NoCircular* prox;
}NoCircular;

typedef NoCircular* LCCauda;

void lc_inserir_inicio(LCCauda* cauda, int valor);
void lc_inserir_fim(LCCauda* cauda, int valor);
NoCircular* lc_buscar(LCCauda cauda, int valor);
bool lc_atualizar_primeiro(LCCauda cauda, int antigo, int novo);
bool lc_remover_valor(LCCauda* cauda, int valor);
void lc_exibir(LCCauda cauda);
void lc_limpar(LCCauda* cauda);

#endif // LISTACIRCULAR_H
