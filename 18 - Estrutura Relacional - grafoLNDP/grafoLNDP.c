#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafoLNDP.h"

Grafo* inicializarGrafo(){
    Grafo* g = (Grafo*) malloc(sizeof(Grafo));
    if(!g){
        printf("\nERROR: sem memoria para criar o grafo....\n");
        return NULL;
    }
    g->vertices = NULL;
    g->qtdVertices = 0;
    return g;
}

void inserirVertice(Grafo *g, int dado){
    g->vertices = (Vertice*) realloc(g->vertices, (g->qtdVertices + 1) * sizeof(Vertice));
    g->vertices[g->qtdVertices].dado = dado;
    g->vertices[g->qtdVertices].listaArestas = NULL;
    g->qtdVertices++;
}

void atualizarVertice(Grafo *g, int indice, int novoDado){
    if(indice < 0 || indice >= g->qtdVertices){
        printf("\nERROR: indice invalido....\n");
        return;
    }
    g->vertices[indice].dado = novoDado;
}

void removerVertice(Grafo *g, int indice){
    if(!g) return;
    if(indice < 0 || indice >= g->qtdVertices){
        printf("\nERROR: indice invalido...\n");
        return;
    }

    for(int i = 0; i < g->qtdVertices; i++){
        if(i == indice) continue;
        Aresta* atual = g->vertices[i].listaArestas;
        Aresta* anterior = NULL;

        while(atual){
            if(atual->destino == indice){
                Aresta* temp = atual;
                if(anterior) anterior->prox = atual->prox;
                else g->vertices[i].listaArestas = atual->prox;
                atual = atual->prox;
                free(temp);
                continue;
            }
            anterior = atual;
            atual = atual->prox;
        }
    }

    Aresta* a = g->vertices[indice].listaArestas;
    while(a){
        Aresta* temp = a;
        a = a->prox;
        free(temp);
    }
    g->vertices[indice].listaArestas = NULL;

    for(int i = 0; i < g->qtdVertices; i++){
        Aresta* aux = g->vertices[i].listaArestas;
        while(aux){
            if(aux->destino > indice) aux->destino--;
            aux = aux->prox;
        }
    }

    for(int i = indice; i < g->qtdVertices - 1; i++){
        g->vertices[i] = g->vertices[i + 1];
    }
    g->qtdVertices--;

    if(g->qtdVertices == 0){
        free(g->vertices);
        g->vertices = NULL;
    }
    else{
        Vertice* novo = (Vertice*) realloc(g->vertices, g->qtdVertices * sizeof(Vertice));
        if(novo) g->vertices = novo;
    }
}

void inserirAresta(Grafo *g, int origem, int destino, int peso){
    if(origem < 0 || destino < 0 || origem >= g->qtdVertices || destino >= g->qtdVertices){
        printf("\nERROR: indices invalidos...\n");
        return;
    }

    Aresta* arestaAB = (Aresta*) malloc( sizeof(Aresta));
    Aresta* arestaBA = (Aresta*) malloc( sizeof(Aresta));
    if(!arestaAB || !arestaBA){
        printf("\nERROR: sem memoria para alocar uma nova aresta....\n");
        return;
    }

    if(origem == destino){
        arestaAB->destino = destino;
        arestaAB->peso = peso;
        arestaAB->prox = g->vertices[origem].listaArestas;
        g->vertices[origem].listaArestas = arestaAB;
    }
    else{
        arestaAB->destino = destino;
        arestaAB->peso = peso;
        arestaAB->prox = g->vertices[origem].listaArestas;
        g->vertices[origem].listaArestas = arestaAB;

        arestaBA->destino = origem;
        arestaBA->peso = peso;
        arestaBA->prox = g->vertices[destino].listaArestas;
        g->vertices[destino].listaArestas = arestaBA;
    }
}

static void remover(Grafo* g, int origem, int destino){
    Aresta* atual = g->vertices[origem].listaArestas;
    Aresta* anterior = NULL;

    while(atual){
        if(atual->destino == destino){
            if(anterior) anterior->prox = atual->prox;
            else g->vertices[origem].listaArestas = atual->prox;

            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

void removerAresta(Grafo *g, int origem, int destino){
    if(origem < 0 || destino < 0 || origem >= g->qtdVertices || destino >= g->qtdVertices){
        printf("\nERROR: indices invalidos...\n");
        return;
    }

    remover(g, origem, destino);
    remover(g, destino, origem);
}

int verificarAresta(Grafo *g, int origem, int destino){
    if(origem < 0 || destino < 0 || origem >= g->qtdVertices || destino >= g->qtdVertices){
        printf("\nERROR: indices invalidos...\n");
        return -1;
    }

    Aresta* aux = g->vertices[origem].listaArestas;
    while(aux){
       if(aux->destino == destino) return aux->peso;
       aux = aux->prox;
    }
    return 0;
}

void exibirGrafo(Grafo *g){
    mostrarVertices(g);
    printf("\n----- Listas de Adjacencia ------\n\n");

    for(int i = 0; i < g->qtdVertices; i++){
        printf("[%d] -> ", i);
        Aresta* a = g->vertices[i].listaArestas;
        while(a){
            printf(" (%d, peso : %d) -> ", a->destino, a->peso);
            a = a->prox;
        }
        printf("NULL.\n");
    }
}

void mostrarVertices(Grafo *g){
    printf("\n----- Vertices -----\n\n");
    for(int i = 0; i < g->qtdVertices; i++){
        printf("[%d] = %d\n", i , g->vertices[i].dado);
    }
    printf("\n\n");
}

int contarArestas(Grafo *g){
    int total = 0;
    int lacos = 0;

    for(int i = 0; i < g->qtdVertices; i++){
        Aresta* a = g->vertices[i].listaArestas;
        while(a){
            if(a->destino == i){
                lacos++;
            }
            else{
                total++;
            }
            a = a->prox;
        }
    }
    total = total / 2;
    total += lacos;

    return total;
}

int grauVertice(Grafo *g, int indice){
    if(indice < 0 || indice >= g->qtdVertices){
        printf("\nERROR: indice invalido....\n");
        return -1;
    }

    int grau = 0;
    Aresta* a = g->vertices[indice].listaArestas;

    while(a){
        if(a->destino == indice){
            grau += 2;
        }
        else{
            grau += 1;
        }
        a = a->prox;
    }
    printf("\nGrau do vertice [%d]: %d\n\n", indice, grau);

    return grau;
}

void limparGrafo(Grafo *g){
    for(int i = 0; i < g->qtdVertices; i++){
        Aresta* a = g->vertices[i].listaArestas;
        while(a){
            Aresta* temp = a;
            a = a->prox;
            free(temp);
        }
    }
    free(g->vertices);
    g->vertices = NULL;
    g->qtdVertices = 0;
}

void destruirGrafo(Grafo *g){
    limparGrafo(g);
    free(g);
}

static bool dfsExisteCaminho(Grafo *g, int atual, int destino, bool* visitado){
    if(atual == destino) return true;

    visitado[atual] = true;

    Aresta* a = g->vertices[atual].listaArestas;
    while(a){
        if(!visitado[a->destino]){
            if(dfsExisteCaminho(g, a->destino, destino, visitado))
                return true;
        }
        a = a->prox;
    }
    return false;
}

void mostrarCaminho(Grafo* g, int origem, int destino){
    bool* visitado = (bool*) calloc(g->qtdVertices, sizeof(bool));
    if(!visitado){
        printf("\nERROR: sem memoria para criar o vetor visitado....\n");
        return;
    }

    if(dfsExisteCaminho(g, origem, destino, visitado)){
        printf("\nExiste um caminho entre [%d] e [%d].\n", origem, destino);
    }
    else{
        printf("\nNAO existe um caminho entre [%d] e [%d].\n", origem, destino);
    }
    free(visitado);
}
