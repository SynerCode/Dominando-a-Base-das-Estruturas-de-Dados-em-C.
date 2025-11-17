#ifndef LISTASE_H
#define LISTASE_H
#include <stdbool.h>

typedef struct NoSimples{
    int dado;
    struct NoSimples* prox;
}NoSimples;

void ls_inserir_inicio(NoSimples** cabeca, int valor);
void ls_inserir_fim(NoSimples** cabeca, int valor);
NoSimples* ls_buscar(NoSimples* cabeca, int valor);
bool ls_atualizar_primeiro(NoSimples* cabeca, int antigo, int novo);
bool ls_remover_valor(NoSimples** cabeca, int valor);
void ls_exibir(const NoSimples* cabeca);
void ls_limpar(NoSimples** cabeca);

#endif // LISTASE_H
