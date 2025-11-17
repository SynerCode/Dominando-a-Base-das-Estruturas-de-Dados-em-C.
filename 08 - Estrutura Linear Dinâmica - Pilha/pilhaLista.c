#include <stdio.h>
#include <stdlib.h>
#include "pilhaLista.h"

static NoPilha* criar_no(int valor){
    NoPilha* n = (NoPilha*) malloc(sizeof(NoPilha));
    if(!n){
        fprintf(stderr,"\nErro: sem espeaco na memoria...\n");
        exit(EXIT_FAILURE);
    }
    n->dado = valor;
    n->prox = NULL;
    return n;
}

PilhaLista* pilha_lista_criar(){
    PilhaLista* p = (PilhaLista*) malloc(sizeof(PilhaLista));
    if(!p){
        fprintf(stderr,"\nErro: erro ao criar a pilha...\n");
        exit(EXIT_FAILURE);
    }
    p->topo = NULL;
    p->tam = 0;
    return p;
}

void pilha_lista_destruir(PilhaLista* p){
    if(!p) return;
    pilha_lista_limpar(p);
    free(p);
}

bool pilha_lista_vazia(const PilhaLista* p){
    return (p->topo == NULL);
}

bool pilha_lista_empilhar(PilhaLista* p, int valor){
    NoPilha* n = criar_no(valor);
    n->prox = p->topo;
    p->topo = n;
    p->tam += 1;
    return true;
}

bool pilha_lista_desempilhar(PilhaLista* p, int* refMemoria){
    if(pilha_lista_vazia(p)) return false;
    NoPilha* n = p->topo;
    if(refMemoria) *refMemoria = n->dado;
    p->topo = n->prox;
    free(n);
    p->tam -= 1;
    return true;
}

bool pilha_lista_topo(const PilhaLista* p, int* refMemoria){
    if(pilha_lista_vazia(p)) return false;
    if(refMemoria) *refMemoria = p->topo->dado;
    return true;
}

int pilha_lista_tamanho(const PilhaLista* p){
    return p->tam;
}

bool pilha_lista_atualizar_topo(PilhaLista* p, int novoValor){
    if(pilha_lista_vazia(p)) return false;
    p->topo->dado = novoValor;
    return true;
}

int pilha_lista_buscar(const PilhaLista* p, int valor){
    NoPilha* atual = p->topo;
    int pos = 0;
    while(atual){
        if(atual->dado == valor) return pos;
        atual = atual->prox;
        pos += 1;
    }
    return -1;
}

void pilha_lista_imprimir(const PilhaLista* p){
    printf("\nPilha....\n");
    NoPilha* atual = p->topo;
    while(atual){
        printf("\n%d", atual->dado);
        atual = atual->prox;
    }
    printf("\n....fim...\n");
}

void pilha_lista_limpar(PilhaLista* p){
    NoPilha* atual = p->topo;
    while(atual){
        NoPilha* prox = atual->prox;
        free(atual);
        atual = prox;
    }
    p->topo = NULL;
    p->tam = 0;
}
