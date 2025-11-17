#ifndef FILADINAMICA_H
#define FILADINAMICA_H
#include <stdbool.h>

typedef struct NoFila{
    int dado;
    struct NoFila* prox;
}NoFila;

typedef struct FilaDinamica{
    NoFila* frente;
    NoFila* tras;
    int tamanho;
}FilaDinamica;

FilaDinamica* fila_dinamica_criar();
void fila_dinamica_destruir(FilaDinamica* f);
bool fila_dinamica_vazia(const FilaDinamica* f);
bool fila_dinamica_enfileirar(FilaDinamica* f, int valor);
bool fila_dinamica_desenfileirar(FilaDinamica* f, int* refMemoria);
bool fila_dinamica_frente(const FilaDinamica* f, int* refMemoria);
int fila_dinamica_tamanho(const FilaDinamica* f);
int fila_dinamica_buscar(const FilaDinamica* f, int valor);
bool fila_dinamica_atualizar(FilaDinamica* f, int antigo, int novo);
void fila_dinamica_imprimir(const FilaDinamica* f);
void fila_dinamica_limpar(FilaDinamica* f);

#endif // FILADINAMICA_H
