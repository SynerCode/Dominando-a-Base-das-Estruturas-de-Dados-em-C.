#include <stdio.h>
#include <stdlib.h>
#include "arvoreB.h"

static No* criarNo(int valor){
    No* novo = (No*) malloc(sizeof(No));
    if(!novo){
        fprintf(stderr,"\nERROR: sem memoria para criar o no...\n");
        exit(EXIT_FAILURE);
    }
    novo->dado = valor;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    return novo;
}

Arvore* criarArvore(){
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));
    if(!arvore){
        fprintf(stderr,"\nERROR: Sem memoria para criar a arvore....\n");
        exit(EXIT_FAILURE);
    }
    arvore->raiz = NULL;
    return arvore;
}

void destruirArvore(Arvore* arvore){
    if(arvore == NULL) return;
    limparArvore(arvore->raiz);
    free(arvore);
}

bool inserirNo(Arvore* arvore, int valor){
    if(arvore == NULL) return false;

    No* novo = criarNo(valor);
    if(novo == NULL) return false;

    if(arvore->raiz == NULL){
        arvore->raiz = novo;
        return true;
    }

    No** fila = (No**) malloc(sizeof(No*) * 1000);
    int inicio = 0;
    int fim = 0;

    fila[fim++] = arvore->raiz;

    while(inicio < fim){
        No* atual = fila[inicio++];
        if(atual->esquerdo == NULL){
            atual->esquerdo = novo;
            free(fila);
            return true;
        }
        else{
            fila[fim++] = atual->esquerdo;
        }
        if(atual->direito == NULL){
            atual->direito = novo;
            free(fila);
            return true;
        }
        else{
            fila[fim++] = atual->direito;
        }
    }
    free(fila);
    return false;
}

bool atualizarNo(Arvore* arvore, int valorAntigo, int novoValor){
    if(arvore == NULL || arvore->raiz == NULL) return false;
    No* no = buscarNo(arvore->raiz, valorAntigo);
    if(no == NULL) return false;
    no->dado = novoValor;
    return true;
}

bool removerNo(Arvore* arvore, int valor){
    if(arvore == NULL || arvore->raiz == NULL) return false;

    No* noAlvo = NULL;
    No* ultimo = NULL;
    No* paiUltimo = NULL;

    No** fila = (No**) malloc(sizeof(No*) * 1000);
    int inicio = 0;
    int fim = 0;
    fila[fim++] = arvore->raiz;

    while(inicio < fim){
        No* atual = fila[inicio++];

        if(atual->dado == valor) noAlvo = atual;

        if(atual->esquerdo != NULL){
            paiUltimo = atual;
            fila[fim++] = atual->esquerdo;
        }
        if(atual->direito != NULL){
            paiUltimo = atual;
            fila[fim++] = atual->direito;
        }
        ultimo = atual;
    }

    if(noAlvo != NULL){
        noAlvo->dado = ultimo->dado;

        if(paiUltimo->direito == ultimo) paiUltimo->direito = NULL;
        else if(paiUltimo->esquerdo == ultimo) paiUltimo->esquerdo = NULL;

        free(ultimo);
        free(fila);
        return true;
    }

    free(fila);
    return false;
}

int contarNos(No* no){
    if(no == NULL) return 0;
    return 1 + contarNos(no->esquerdo) + contarNos(no->direito);
}

int contarFolhas(No* no){
    if(no == NULL) return 0;
    if(no->esquerdo == NULL && no->direito == NULL) return 1;
    return contarFolhas(no->esquerdo) + contarFolhas(no->direito);
}

int altura(No* no){
    if(no == NULL) return -1;
    int esq = altura(no->esquerdo);
    int dir = altura(no->direito);
    return 1 + (esq > dir ? esq : dir);
}

int profundidade(No* raiz, int valor, int nivel){
    if(raiz == NULL) return -1;
    if(raiz->dado == valor) return nivel;
    int esq = profundidade(raiz->esquerdo, valor, nivel + 1);
    if(esq != -1) return esq;
    return profundidade(raiz->direito, valor, nivel + 1);
}

int grauDaArvore(No* no){
    if(no == NULL) return 0;
    int grau = 0;
    if(no->esquerdo != NULL) grau++;
    if(no->direito != NULL) grau++;
    int grauEsq = grauDaArvore(no->esquerdo);
    int grauDir = grauDaArvore(no->direito);
    int maxGrau = grauEsq > grauDir ? grauEsq : grauDir;
    return grau > maxGrau ? grau : maxGrau;
}

int largura(No* raiz){
    if(raiz == NULL) return 0;

    int maxLargura = 0;
    No** fila = (No**) malloc(sizeof(No*) * 1000);
    int inicio = 0;
    int fim = 0;
    fila[fim++] = raiz;

    while(inicio < fim){
        int nivelCount = fim - inicio;
        if(nivelCount > maxLargura) maxLargura = nivelCount;

        for(int i = 0; i < nivelCount; i++){
            No* atual = fila[inicio++];

            if(atual->esquerdo != NULL) fila[fim++] = atual->esquerdo;
            if(atual->direito != NULL) fila[fim++] = atual->direito;
        }
    }
    free(fila);
    return maxLargura;
}

No* buscarNo(No* raiz, int valor){
    if(raiz == NULL) return NULL;
    if(raiz->dado == valor) return raiz;
    No* esq = buscarNo(raiz->esquerdo, valor);
    if(esq != NULL) return esq;
    return buscarNo(raiz->direito, valor);
}

void preOrdem(No* raiz){
    if(raiz == NULL) return;
    printf("%d - ", raiz->dado);
    preOrdem(raiz->esquerdo);
    preOrdem(raiz->direito);
}

void emOrdem(No* raiz){
    if(raiz == NULL) return;
    emOrdem(raiz->esquerdo);
    printf("%d - ", raiz->dado);
    emOrdem(raiz->direito);
}

void posOrdem(No* raiz){
    if(raiz == NULL) return;
    posOrdem(raiz->esquerdo);
    posOrdem(raiz->direito);
    printf("%d - ", raiz->dado);
}

void porNivel(No* raiz){
    if(raiz == NULL) return;

    No** fila = (No**) malloc(sizeof(No*) * 1000);
    int inicio = 0;
    int fim = 0;
    fila[fim++] = raiz;

    while(inicio < fim){
        No* atual = fila[inicio++];
        printf("%d - ", atual->dado);

        if(atual->esquerdo != NULL) fila[fim++] = atual->esquerdo;
        if(atual->direito != NULL) fila[fim++] = atual->direito;
    }
    free(fila);
}

void imprimirArvore(No* raiz, int nivel){
    if(raiz == NULL) return;
    imprimirArvore(raiz->direito, nivel + 1);
    for(int i = 0; i < nivel; i++) printf("  ");
    printf("%d\n", raiz->dado);
    imprimirArvore(raiz->esquerdo, nivel + 1);
}

void limparArvore(No* raiz){
    if(raiz == NULL) return;
    limparArvore(raiz->esquerdo);
    limparArvore(raiz->direito);
    free(raiz);
}
