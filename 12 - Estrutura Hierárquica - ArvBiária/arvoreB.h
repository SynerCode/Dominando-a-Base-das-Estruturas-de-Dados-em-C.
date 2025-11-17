#ifndef ARVOREB_H
#define ARVOREB_H
#include <stdbool.h>

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
}No;

typedef struct Arvore {
    No* raiz;
}Arvore;

Arvore* criarArvore();
void destruirArvore(Arvore* arvore);
bool inserirNo(Arvore* arvore, int valor);
bool atualizarNo(Arvore* arvore, int valorAntigo, int novoValor);
bool removerNo(Arvore* arvore, int valor);
int contarNos(No* no);
int contarFolhas(No* no);
int altura(No* no);
int profundidade(No* raiz, int valor, int nivel);
int grauDaArvore(No* no);
int largura(No* raiz);
No* buscarNo(No* raiz, int valor);
void preOrdem(No* raiz);
void emOrdem(No* raiz);
void posOrdem(No* raiz);
void porNivel(No* raiz);
void imprimirArvore(No* raiz, int nivel);
void limparArvore(No* raiz);

#endif // ARVOREB_H
