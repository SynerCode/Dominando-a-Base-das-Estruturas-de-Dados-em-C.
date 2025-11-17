#ifndef PILHAARRAY_H
#define PILHAARRAY_H
#include <stdbool.h>

#define PILHA_ARRAY_CAPACIDADE 5

typedef struct PilhaArray{
    int topo;
    int dados[PILHA_ARRAY_CAPACIDADE];
}PilhaArray;

PilhaArray* pilha_array_criar();
void pilha_array_destruir(PilhaArray* p);
bool pilha_array_vazia(const PilhaArray* p);
bool pilha_array_cheia(const PilhaArray* p);
bool pilha_array_empilhar(PilhaArray* p, int valor);
bool pilha_array_desempilhar(PilhaArray* p, int* refMemoria);
bool pilha_array_topo(const PilhaArray* p, int* refMemoria);
int pilha_array_tamanho(const PilhaArray* p);
bool pilha_array_atualizar_topo(PilhaArray* p, int novo_val);
int pilha_array_buscar(const PilhaArray* p, int valor);
void pilha_array_imprimir(const PilhaArray* p);
void pilha_array_limpar(PilhaArray* p);

#endif // PILHAARRAY_H
