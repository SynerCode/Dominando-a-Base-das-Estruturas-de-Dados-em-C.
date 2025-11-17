#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.h"
///
FilaEstatica* fila_estatica_criar(){
    FilaEstatica* f = (FilaEstatica*) malloc(sizeof(FilaEstatica));
    if(!f){
        fprintf(stderr,"\nERROR: sem memoria para criar a fila...\n");
        exit(EXIT_FAILURE);
    }
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    return f;
}
///
void fila_estatica_destruir(FilaEstatica* f){
    if(!f) return;
    free(f);
    printf("\nFila destruida...\n");
}
///
bool fila_estatica_vazia(const FilaEstatica* f){
    return (f->tamanho == 0);
}

bool fila_estatica_cheia(const FilaEstatica* f){
    return (f->tamanho >= FILA_ESTATICA_CAPACIDADE);
}
///
bool fila_estatica_enfileirar(FilaEstatica* f, int valor){
    if(fila_estatica_cheia(f)){
        printf("\nNao foi possivel enfileirar o valor %d, fila cheia....\n", valor);
        return false;
    }
    f->dado[f->fim] = valor;
    f->fim = (f->fim + 1) % FILA_ESTATICA_CAPACIDADE;
    f->tamanho += 1;
    return true;
}
///
bool fila_estatica_desenfileirar(FilaEstatica* f, int* refMemoria){
    if(fila_estatica_vazia(f)) return false;
    if(refMemoria) *refMemoria = f->dado[f->inicio];
    f->inicio = (f->inicio + 1) % FILA_ESTATICA_CAPACIDADE;
    f->tamanho -= 1;
    return true;
}
///
bool fila_estatica_frente(const FilaEstatica* f, int* refMemoria){
    if(fila_estatica_vazia(f)) return false;
    if(refMemoria) *refMemoria = f->dado[f->inicio];
    return true;
}
///
int fila_estatica_tamanho(const FilaEstatica* f){
    return f->tamanho;
}
///
int fila_estatica_buscar(const FilaEstatica* f, int valor){
    int idx = f->inicio;
    for(int i = 0; i < f->tamanho; ++i){
        if(f->dado[idx] == valor) return i+1;
        idx = (idx + 1) % FILA_ESTATICA_CAPACIDADE;
    }
    return -1;
}
///
bool fila_estatica_atualizar(FilaEstatica* f, int vlAntigo, int vlNovo){
    int idx = f->inicio;
    for(int i = 0; i < f->tamanho; ++i){
        if(f->dado[idx] == vlAntigo){
            f->dado[idx] = vlNovo;
            return true;
        }
        idx = (idx + 1) % FILA_ESTATICA_CAPACIDADE;
    }
    return false;
}
///
void fila_estatica_imprimir(const FilaEstatica* f){
    if(fila_estatica_vazia(f)){
        printf("\nFila Vazia...\n");
        return;
    }
    int idx = f->inicio;
    printf("\nInicio da Fila...\n");
    for(int i = 0; i < f->tamanho; ++i){
        printf("%d -> ", f->dado[idx]);
        idx = (idx + 1) % FILA_ESTATICA_CAPACIDADE;
    }
    printf("\nFim da Fila...\n");
}
///
void fila_estatica_limpar(FilaEstatica* f){
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}
