#include "listaSE.h"
#include <stdio.h>
#include <stdlib.h>

static NoSimples* ls_criar_no(int valor){
    NoSimples* n = (NoSimples*) malloc(sizeof(NoSimples));
    if(!n){
        fprintf(stderr, "\nErro: sem memoria ao criar o no.\n");
        exit(EXIT_FAILURE);
    }
    n->dado = valor;
    n->prox = NULL;
    return n;
}

void ls_inserir_inicio(NoSimples** cabeca, int valor){
    NoSimples* n = ls_criar_no(valor);
    n->prox = *cabeca;
    *cabeca = n;
}

void ls_inserir_fim(NoSimples** cabeca, int valor){
    NoSimples* n = ls_criar_no(valor);
    if(*cabeca == NULL){
        *cabeca = n;
        return;
    }
    NoSimples* p = *cabeca;
    while(p->prox != NULL){
        p = p->prox;
    }
    p->prox = n;
}

NoSimples* ls_buscar(NoSimples* cabeca, int valor) {
    NoSimples* p = cabeca;
    while(p != NULL){
        if(p->dado == valor) return p;
        p = p->prox;
    }
    return NULL;
}

bool ls_atualizar_primeiro(NoSimples* cabeca, int antigo, int novo){
    NoSimples* no = ls_buscar(cabeca, antigo);
    if(!no) return false;
    no->dado = novo;
    return true;
}

bool ls_remover_valor(NoSimples** cabeca, int valor){
    NoSimples* p = *cabeca;
    NoSimples* ant = NULL;
    while(p != NULL && p->dado != valor){
        ant = p;
        p = p->prox;
    }
    if(p == NULL) return false;
    if(ant == NULL){
        *cabeca = p->prox;
    }
    else{
        ant->prox = p->prox;
    }
    free(p);
    return true;
}

void ls_exibir(const NoSimples* cabeca){
    const NoSimples* p = cabeca;
    while(p != NULL){
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("NULL. \n");
}

void ls_limpar(NoSimples** cabeca){
    NoSimples* p = *cabeca;
    while(p != NULL){
        NoSimples* prox = p->prox;
        free(p);
        p = prox;
    }
    *cabeca = NULL;
}
