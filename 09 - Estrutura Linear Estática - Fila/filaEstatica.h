#ifndef FILAESTATICA_H
#define FILAESTATICA_H
#include <stdbool.h>

#define FILA_ESTATICA_CAPACIDADE 5

typedef struct FilaEstatica{
    int dado[FILA_ESTATICA_CAPACIDADE];
    int inicio;
    int fim;
    int tamanho;
}FilaEstatica;

FilaEstatica* fila_estatica_criar();
void fila_estatica_destruir(FilaEstatica* f);
bool fila_estatica_vazia(const FilaEstatica* f);
bool fila_estatica_cheia(const FilaEstatica* f);
bool fila_estatica_enfileirar(FilaEstatica* f, int valor);
bool fila_estatica_desenfileirar(FilaEstatica* f, int* refMemoria);
bool fila_estatica_frente(const FilaEstatica* f, int* refMemoria);
int fila_estatica_tamanho(const FilaEstatica* f);
int fila_estatica_buscar(const FilaEstatica* f, int valor);
bool fila_estatica_atualizar(FilaEstatica* f, int vlAntigo, int vlNovo);
void fila_estatica_imprimir(const FilaEstatica* f);
void fila_estatica_limpar(FilaEstatica* f);

#endif // FILAESTATICA_H
