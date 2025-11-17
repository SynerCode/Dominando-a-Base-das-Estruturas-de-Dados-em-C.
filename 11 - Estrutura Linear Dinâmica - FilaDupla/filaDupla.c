#include <stdio.h>
#include <stdlib.h>
#include "filaDupla.h"

static NoFilaDupla* criar_no(int valor){
    NoFilaDupla* n = (NoFilaDupla*) malloc(sizeof(NoFilaDupla));
    if(!n){
        fprintf(stderr,"\nERROR: sem memoria para criar o no fila dupla...\n");
        exit(EXIT_FAILURE);
    }
    n->dado = valor;
    n->prox = NULL;
    n->ant = NULL;
    return n;
}

FilaDupla* filaDupla_criar(){
    FilaDupla* fd = (FilaDupla*) malloc(sizeof(FilaDupla));
    if(!fd){
        fprintf(stderr,"\nERROR: sem memoria para criar a fila dupla...\n");
        exit(EXIT_FAILURE);
    }
    fd->frente = NULL;
    fd->tras = NULL;
    fd->tamanho = 0;
    return fd;
}

void filaDupla_destruir(FilaDupla* fd){
    if(!fd) return;
    filaDupla_limpar(fd);
    free(fd);
}

bool filaDupla_vazia(const FilaDupla* fd){
    return (fd->tamanho == 0);
}

int filaDupla_tamanho(const FilaDupla* fd){
    return fd->tamanho;
}

bool filaDupla_inserir_frente(FilaDupla* fd, int valor){
    NoFilaDupla* n = criar_no(valor);
    if(fd->frente == NULL){
        fd->frente = n;
        fd->tras = n;
    }
    else{
        n->prox = fd->frente;
        fd->frente->ant = n;
        fd->frente = n;
    }
    fd->tamanho += 1;
    return true;
}

bool filaDupla_inserir_traseira(FilaDupla* fd, int valor){
    NoFilaDupla* n = criar_no(valor);
    if(fd->tras == NULL){
        fd->frente = n;
        fd->tras = n;
    }
    else{
        n->ant = fd->tras;
        fd->tras->prox = n;
        fd->tras = n;
    }
    fd->tamanho += 1;
    return true;
}

bool filaDupla_remover_frente(FilaDupla* fd, int* refMemoria){
    if(filaDupla_vazia(fd)) return false;
    NoFilaDupla* rem = fd->frente;
    if(refMemoria) *refMemoria = rem->dado;
    fd->frente = rem->prox;
    if(fd->frente != NULL){
        fd->frente->ant = NULL;
    }
    else{
        fd->tras = NULL;
    }
    free(rem);
    fd->tamanho -= 1;
    return true;
}

bool filaDupla_remover_traseira(FilaDupla* fd, int* refMemoria){
    if(filaDupla_vazia(fd)) return false;
    NoFilaDupla* rem = fd->tras;
    if(refMemoria) *refMemoria = rem->dado;
    fd->tras = rem->ant;
    if(fd->tras != NULL){
        fd->tras->prox = NULL;
    }
    else{
        fd->frente = NULL;
    }
    free(rem);
    fd->tamanho -= 1;
    return true;
}

bool filaDupla_peek_frente(const FilaDupla* fd, int* refMemoria){
    if(filaDupla_vazia(fd)) return false;
    if(refMemoria) *refMemoria = fd->frente->dado;
    return true;
}

bool filaDupla_peek_traseira(const FilaDupla* fd, int* refMemoria){
    if(filaDupla_vazia(fd)) return false;
    if(refMemoria) *refMemoria = fd->tras->dado;
    return true;
}

int filaDupla_buscar(const FilaDupla* fd, int valor){
    NoFilaDupla* p = fd->frente;
    int pos = 0;
    while(p){
        if(p->dado == valor) return pos;
        p = p->prox;
        pos += 1;
    }
    return -1;
}

bool filaDupla_atualizar(FilaDupla* fd, int antigo, int novo){
    NoFilaDupla* p = fd->frente;
    while(p){
        if(p->dado == antigo){
            p->dado = novo;
            return true;
        }
        p = p->prox;
    }
    return false;
}

void filaDupla_imprimir(const FilaDupla* fd){
    if(filaDupla_vazia(fd)){
        printf("\nFila dupla esta vazia.....\n");
        return;
    }
    printf("\nFila Dupla Inicio ->....\n");
    NoFilaDupla* p = fd->frente;
    while(p){
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("\nFila Dupla Final -> ....\n");
}

void filaDupla_limpar(FilaDupla* fd){
    NoFilaDupla* p = fd->frente;
    while(p){
        NoFilaDupla* prox = p->prox;
        free(p);
        p = prox;
    }
    fd->frente = NULL;
    fd->tras = NULL;
    fd->tamanho = 0;
}
