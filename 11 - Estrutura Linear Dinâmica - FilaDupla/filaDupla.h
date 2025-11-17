#ifndef FILADUPLA_H
#define FILADUPLA_H
#include <stdbool.h>

typedef struct NoFilaDupla{
    int dado;
    struct NoFilaDupla* prox;
    struct NoFilaDupla* ant;
}NoFilaDupla;

typedef struct FilaDupla{
    NoFilaDupla* frente;
    NoFilaDupla* tras;
    int tamanho;
}FilaDupla;

FilaDupla* filaDupla_criar();
void filaDupla_destruir(FilaDupla* fd);
bool filaDupla_vazia(const FilaDupla* fd);
int filaDupla_tamanho(const FilaDupla* fd);
bool filaDupla_inserir_frente(FilaDupla* fd, int valor);
bool filaDupla_inserir_traseira(FilaDupla* fd, int valor);
bool filaDupla_remover_frente(FilaDupla* fd, int* refMemoria);
bool filaDupla_remover_traseira(FilaDupla* fd, int* refMemoria);
bool filaDupla_peek_frente(const FilaDupla* fd, int* refMemoria);
bool filaDupla_peek_traseira(const FilaDupla* fd, int* refMemoria);
int filaDupla_buscar(const FilaDupla* fd, int valor);
bool filaDupla_atualizar(FilaDupla* fd, int antigo, int novo);
void filaDupla_imprimir(const FilaDupla* fd);
void filaDupla_limpar(FilaDupla* fd);

#endif // FILADUPLA_H
