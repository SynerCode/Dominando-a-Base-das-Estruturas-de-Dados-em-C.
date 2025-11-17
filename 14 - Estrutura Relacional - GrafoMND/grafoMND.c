#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafoMND.h"

Grafo* inicializarGrafo(){
    Grafo *g = (Grafo*) malloc(sizeof(Grafo));
    if(!g){
        printf("\nError: sem memoria para criar o grafo...\n");
        return NULL;
    }
    g->qtdVertices = 0;
    g->matriz = NULL;
    g->vertices = NULL;
    return g;
}

void inserirVertice(Grafo *g, int dado){
    int novoTamanho = g->qtdVertices + 1;

    g->vertices = (Vertice*) realloc(g->vertices, novoTamanho * sizeof(Vertice));
    g->vertices[g->qtdVertices].dado = dado;

    int **novaMatriz = (int**) malloc(novoTamanho * sizeof(int*));
    for(int i = 0; i < novoTamanho; i++){
        novaMatriz[i] = (int*) calloc(novoTamanho, sizeof(int));
    }

    for(int i = 0; i < g->qtdVertices; i++){
        for(int j = 0; j < g->qtdVertices; j++){
            novaMatriz[i][j] = g->matriz[i][j];
        }
    }

    for(int i = 0; i < g->qtdVertices; i++){
        free(g->matriz[i]);
    }
    free(g->matriz);

    g->matriz = novaMatriz;
    g->qtdVertices = novoTamanho;
}

void atualizarVertice(Grafo *g, int indice, int novoDado){
    if(indice < 0 || indice >= g->qtdVertices){
        printf("\nERROR: Indice invalido....\n");
        return;
    }
    g->vertices[indice].dado = novoDado;
}

void removerVertice(Grafo *g, int indice){
    if(indice < 0 || indice >= g->qtdVertices){
        printf("\nERROR: indice invalido...\n");
        return;
    }

    int novoTamanho = g->qtdVertices - 1;
    int **novaMatriz = (int**) malloc(novoTamanho * sizeof(int*));

    for(int i = 0; i < novoTamanho; i++){
        novaMatriz[i] = (int*) calloc(novoTamanho, sizeof(int));
    }

    int x = 0;
    for(int i = 0; i < g->qtdVertices; i++){
        if(i == indice) continue;
        int y = 0;
        for(int j = 0; j < g->qtdVertices; j++){
            if(j == indice) continue;
            novaMatriz[x][y++] = g->matriz[i][j];
        }
        x++;
    }

    for(int i = 0; i < g->qtdVertices; i++){
        free(g->matriz[i]);
    }
    free(g->matriz);

    Vertice *novoVetor = (Vertice*) malloc(novoTamanho * sizeof(Vertice));

    for(int i = 0, k = 0; i < g->qtdVertices; i++){
        if(i != indice) novoVetor[k++] = g->vertices[i];
    }

    free(g->vertices);
    g->matriz = novaMatriz;
    g->vertices = novoVetor;
    g->qtdVertices = novoTamanho;
}

void inserirAresta(Grafo *g, int origem, int destino){
    if(origem < 0 || destino < 0 || origem >= g->qtdVertices || destino >= g->qtdVertices){
        printf("\nERROR: indices invalidos....\n");
        return;
    }
    g->matriz[origem][destino] = 1;
    g->matriz[destino][origem] = 1;
}

void removerAresta(Grafo *g, int origem, int destino){
    if(origem < 0 || destino < 0 || origem >= g->qtdVertices || destino >= g->qtdVertices){
        printf("\nERROR: indices invalidos....\n");
        return;
    }
    g->matriz[origem][destino] = 0;
    g->matriz[destino][origem] = 0;
}

int verificarAresta(Grafo *g, int origem, int destino){
    if(origem < 0 || destino < 0 || origem >= g->qtdVertices || destino >= g->qtdVertices){
        printf("\nERROR: indices invalidos....\n");
        return 0;
    }
    return g->matriz[origem][destino];
}

void exibirGrafo(Grafo *g){
    mostrarVertices(g);
    imprimirMatriz(g);
}

void mostrarVertices(Grafo *g){
    printf("\n------ Vertices ------\n\n");
    for(int i = 0; i < g->qtdVertices; i++){
        printf("[%d] = %d\n", i, g->vertices[i].dado);
    }
    printf("\n\n");
}

int contarArestas(Grafo *g){
    int total = 0;
    for(int i = 0; i < g->qtdVertices; i++){
        for(int j = i; j < g->qtdVertices; j++){
            if(g->matriz[i][j]) total++;
        }
    }
    return total;
}

int grauVertice(Grafo *g, int indice){
    int grau = 0;
    for(int j = 0; j < g->qtdVertices; j++){
        if(g->matriz[indice][j]) grau++;
        if(indice == j && g->matriz[indice][j]) grau++;
    }
    return grau;
}

void limparGrafo(Grafo *g){
    for(int i = 0; i < g->qtdVertices; i++){
        free(g->matriz[i]);
    }
    free(g->matriz);
    free(g->vertices);
    g->qtdVertices = 0;
    g->matriz = NULL;
    g->vertices = NULL;
}

void destruirGrafo(Grafo *g){
    for(int i = 0; i < g->qtdVertices; i++){
        free(g->matriz[i]);
    }
    free(g->matriz);
    free(g->vertices);
    g->qtdVertices = 0;
    g->matriz = NULL;
    g->vertices = NULL;
    free(g);
}

static bool dfsExisteCaminho(Grafo* g, int atual, int destino, bool* visitado){
    if(atual == destino){
        return true;
    }

    visitado[atual] = true;
    for(int i = 0; i < g->qtdVertices; i++){
        if(g->matriz[atual][i] && !visitado[i]){
            if(dfsExisteCaminho(g, i, destino, visitado)){
                return true;
            }
        }
    }
    return false;
}

void mostrarCaminho(Grafo* g, int origem, int destino){
    if(origem < 0 || destino < 0 || origem >= g->qtdVertices || destino >= g->qtdVertices){
        printf("\nERROR: indices Invalidos.....\n");
        return;
    }

    bool* visitado = (bool*) calloc (g->qtdVertices, sizeof(bool));
    if(!visitado){
        printf("\nERROR: sem memoria alocada para vetor visitado....\n");
        return;
    }

    if(dfsExisteCaminho(g, origem, destino, visitado)){
        printf("\nExiste um caminho entre %d e %d.", origem, destino);
    }
    else{
        printf("\nNAO Existe um caminho entre %d e %d.", origem, destino);
    }

    free(visitado);
}

void imprimirMatriz(Grafo* g){
    printf("\n------- Matriz de Adjacencias -------\n\n");
    for(int i = 0; i < g->qtdVertices; i++){
        for(int j = 0; j < g->qtdVertices; j++){
            printf("%d ", g->matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
