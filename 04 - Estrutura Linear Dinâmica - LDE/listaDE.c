#include "listaDE.h"
#include <stdio.h>
#include <stdlib.h>

static NoDuplo* ld_criar_no(int valor){
    NoDuplo* n = (NoDuplo*) malloc(sizeof(NoDuplo));
    if(!n){
        fprintf(stderr,"\nERROR: sem memoria para criar o no.\n");
        exit(EXIT_FAILURE);
    }
    n->dado = valor;
    n->prox = NULL;
    n->ant = NULL;
    return n;
}

void ld_inserir_inicio(NoDuplo** cabeca, int valor){
    NoDuplo* n = ld_criar_no(valor);
    n->prox = *cabeca;
    n->ant = NULL;
    if(*cabeca != NULL){
        (*cabeca)->ant = n;
    }
    *cabeca = n;
}

void ld_inserir_fim(NoDuplo** cabeca, int valor){
    NoDuplo* n = ld_criar_no(valor);
    if(*cabeca == NULL){
        *cabeca = n;
        return;
    }
    NoDuplo* p = *cabeca;
    while(p->prox != NULL) p = p->prox;
    p->prox = n;
    n->ant = p;
}

NoDuplo* ld_buscar(NoDuplo* cabeca, int valor){
    NoDuplo* p = cabeca;
    while(p != NULL){
        if(p->dado == valor) return p;
        p = p->prox;
    }
    return NULL;
}

bool ld_atualizar_primeiro(NoDuplo* cabeca, int antigo, int novo){
    NoDuplo* no = ld_buscar(cabeca, antigo);
    if(!no) return false;
    no->dado = novo;
    return true;
}

bool ld_remover_valor(NoDuplo** cabeca, int valor){
    NoDuplo* p = *cabeca;
    while(p != NULL && p->dado != valor){
        p = p->prox;
    }
    if(!p) return false;
    if(p->ant){
        ///         P
        /// 1 - 2 - 3 - 4 - 5
        ///     A
        /// 1 - 2 - 3 - 4 - 5
        ///             B
        /// 1 - 2 - 3 - 4 - 5
        ///     A-------B
        /// 1 - 2 - 3 - 4 - 5
        p->ant->prox = p->prox;
    }
    else{
        *cabeca = p->prox;
    }
    if(p->prox){
        p->prox->ant = p->ant;
    }
    free(p);
    return true;
}

void ld_exibir_frente(const NoDuplo* cabeca){
    const NoDuplo* p = cabeca;
    while(p != NULL){
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("NULL.\n");
}

void ld_exibir_tras(const NoDuplo* cauda){
    const NoDuplo* p = cauda;
    while(p != NULL){
        printf("%d <- ", p->dado);
        p = p->ant;
    }
    printf("NULL.\n");
}

NoDuplo* ld_obter_cauda(NoDuplo* cabeca){
    if(!cabeca) return NULL;
    NoDuplo* p = cabeca;
    while(p->prox != NULL) p = p->prox;
    return p;
}

void ld_limpar(NoDuplo** cabeca){
    NoDuplo* p = *cabeca;
    while(p != NULL){
        NoDuplo* prox = p->prox;
        free(p);
        p = prox;
    }
    *cabeca = NULL;
}
