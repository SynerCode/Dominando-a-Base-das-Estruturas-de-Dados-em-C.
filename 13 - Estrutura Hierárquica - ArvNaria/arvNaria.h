#ifndef ARVNARIA_H
#define ARVNARIA_H
#include <stdbool.h>
#define N_FILHOS_MAX 4

typedef struct NoListaLimit{
    int dado;
    int qtdFilhos;
    struct NoListaLimit* primeiroFilho;
    struct NoListaLimit* proximoIrmao;
    struct NoListaLimit* pai;
}NoListaLimit;

typedef struct ArvoreNariaListaLimit {
    NoListaLimit* raiz;
}ArvoreNariaListaLimit;

ArvoreNariaListaLimit* criarArvoreListaLimit();
void destruirArvoreListaLimit(ArvoreNariaListaLimit* arvore);
bool inserirRaizListaLimit(ArvoreNariaListaLimit* arvore, int valorRaiz);
bool inserirFilhoListaLimit(ArvoreNariaListaLimit* arvore, int valorPai, int valorNovo);
bool atualizarNoListaLimit(ArvoreNariaListaLimit* arvore, int valorAntigo, int novoValor);
bool removerSubarvoreListaLimit(ArvoreNariaListaLimit* arvore, int valor);
bool removerNoMantendoFilhosListaLimit(ArvoreNariaListaLimit* arvore, int valor);
NoListaLimit* buscarNoListaLimit(NoListaLimit* raiz, int valor);
void mostrarSubarvoreListaLimit(NoListaLimit* raiz, int valor);
int contarNosListaLimit(NoListaLimit* raiz);
int contarFolhasListaLimit(NoListaLimit* raiz);
int alturaListaLimit(NoListaLimit* raiz);
int profundidadeListaLimit(NoListaLimit* raiz, int valor, int nivel);
int grauArvoreListaLimit(NoListaLimit* raiz);
int larguraArvoreListaLimit(NoListaLimit* raiz);
void preOrdemListaLimit(NoListaLimit* raiz);
void posOrdemListaLimit(NoListaLimit* raiz);
void porNivelListaLimit(NoListaLimit* raiz);
void imprimirArvoreListaLimit(NoListaLimit* raiz, int nivel);
void limparSubarvoreListaLimit(NoListaLimit* raiz);

#endif // ARVNARIA_H
