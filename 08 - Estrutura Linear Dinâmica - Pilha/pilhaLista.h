#ifndef PILHALISTA_H
#define PILHALISTA_H
#include <stdbool.h>

typedef struct NoPilha{
    int dado;
    struct NoPilha* prox;
}NoPilha;

typedef struct PilhaLista{
    NoPilha* topo;
    int tam;
}PilhaLista;

PilhaLista* pilha_lista_criar();
void pilha_lista_destruir(PilhaLista* p);
bool pilha_lista_vazia(const PilhaLista* p);
bool pilha_lista_empilhar(PilhaLista* p, int valor);
bool pilha_lista_desempilhar(PilhaLista* p, int* refMemoria);
bool pilha_lista_topo(const PilhaLista* p, int* refMemoria);
int pilha_lista_tamanho(const PilhaLista* p);
bool pilha_lista_atualizar_topo(PilhaLista* p, int novoValor);
int pilha_lista_buscar(const PilhaLista* p, int valor);
void pilha_lista_imprimir(const PilhaLista* p);
void pilha_lista_limpar(PilhaLista* p);

#endif // PILHALISTA_H
