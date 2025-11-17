#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

static NoFila* fila_dinamica_no(int valor){
    NoFila* n = (NoFila*) malloc(sizeof(NoFila));
    if(!n){
        fprintf(stderr, "\nERROR: sem memoria para criar o no...\n");
        exit(EXIT_FAILURE);
    }
    n->dado = valor;
    n->prox = NULL;
    return n;
}

FilaDinamica* fila_dinamica_criar(){
    FilaDinamica* f = (FilaDinamica*) malloc(sizeof(FilaDinamica));
    if(!f){
        fprintf(stderr, "ERROR: Sem memoria para criar a fila....\n");
        exit(EXIT_FAILURE);
    }
    f->frente = NULL;
    f->tras = NULL;
    f->tamanho = 0;
    return f;
}

void fila_dinamica_destruir(FilaDinamica* f){
    if(!f) return;
    fila_dinamica_limpar(f);
    free(f);
    printf("\nFila destruida....\n");
}

bool fila_dinamica_vazia(const FilaDinamica* f){
    return (f->tamanho == 0);
}

bool fila_dinamica_enfileirar(FilaDinamica* f, int valor){
    if(!f) return false;
    NoFila* n = fila_dinamica_no(valor);
    if(f->tras == NULL){
        f->frente = n;
        f->tras = n;
    }
    else{
        f->tras->prox = n;
        f->tras = n;
    }
    f->tamanho += 1;
    return true;
}

bool fila_dinamica_desenfileirar(FilaDinamica* f, int* refMemoria){
    if(f->frente == NULL) return false;
    NoFila* rem = f->frente;
    if(refMemoria) *refMemoria = rem->dado;
    f->frente = rem->prox;
    if(f->frente == NULL){
       f->tras = NULL;
    }
    free(rem);
    f->tamanho -= 1;
    return true;
}

bool fila_dinamica_frente(const FilaDinamica* f, int* refMemoria){
    if(f->frente == NULL) return false;
    if(refMemoria) *refMemoria = f->frente->dado;
    return true;
}

int fila_dinamica_tamanho(const FilaDinamica* f){
    return f->tamanho;
}

int fila_dinamica_buscar(const FilaDinamica* f, int valor){
    NoFila* p = f->frente;
    int pos = 0;
    while(p){
        if(p->dado == valor) return pos;
        p = p->prox;
        pos += 1;
    }
    return -1;
}

bool fila_dinamica_atualizar(FilaDinamica* f, int antigo, int novo){
    NoFila* p = f->frente;
    while(p){
        if(p->dado == antigo){
            p->dado = novo;
            return true;
        }
        p = p->prox;
    }
    return false;
}

void fila_dinamica_imprimir(const FilaDinamica* f){
    if(f->frente == NULL){
        printf("\nNada para mostrar, fila vazia....\n");
        return;
    }
    printf("\nInicio filaD....\n");
    NoFila* p = f->frente;
    while(p){
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("\nFim da filaD...\n");
}

void fila_dinamica_limpar(FilaDinamica* f){
    NoFila* p = f->frente;
    while(p){
        NoFila* prox = p->prox;
        free(p);
        p = prox;
    }
    f->frente = NULL;
    f->tras = NULL;
    f->tamanho = 0;
}
