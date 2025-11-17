#include <stdio.h>
#include <stdlib.h>
#include "pilhaArray.h"

PilhaArray* pilha_array_criar(){
    PilhaArray* p = (PilhaArray*) malloc(sizeof(PilhaArray));
    if(!p){
        fprintf(stderr,"\nErro: problema na criacao da pilha...\n");
        exit(EXIT_FAILURE);
    }
    p->topo = -1;
    return p;
}

void pilha_array_destruir(PilhaArray* p){
    if(!p) return;
    free(p);
}

bool pilha_array_vazia(const PilhaArray* p){
    return (p->topo == -1);
}

bool pilha_array_cheia(const PilhaArray* p){
    return (p->topo >= PILHA_ARRAY_CAPACIDADE -1);
}

bool pilha_array_empilhar(PilhaArray* p, int valor){
    if(pilha_array_cheia(p)) return false;
    p->topo += 1;
    p->dados[p->topo] = valor;
    return true;
}

bool pilha_array_desempilhar(PilhaArray* p, int* refMemoria){
    if(pilha_array_vazia(p)) return false;
    if(refMemoria) *refMemoria = p->dados[p->topo];
    p->topo -= 1;
    return true;
}

bool pilha_array_topo(const PilhaArray* p, int* refMemoria){
    if(pilha_array_vazia(p)) return false;
    if(refMemoria) *refMemoria = p->dados[p->topo];
    return true;
}

int pilha_array_tamanho(const PilhaArray* p){
    return (p->topo + 1);
}

bool pilha_array_atualizar_topo(PilhaArray* p, int novo_val){
    if(pilha_array_vazia(p)) return false;
    p->dados[p->topo] = novo_val;
    return true;
}

int pilha_array_buscar(const PilhaArray* p, int valor){
    for(int i = p->topo; i >= 0 ; i--){
        if(p->dados[i] == valor) return i;
    }
    return -1;
}

void pilha_array_imprimir(const PilhaArray* p){
    printf("\nPilha....\n");
    for(int i = p->topo; i >= 0; i--){
        printf("%d \n", p->dados[i]);
    }
    printf("\n");
}

void pilha_array_limpar(PilhaArray* p){
    p->topo = -1;
}
