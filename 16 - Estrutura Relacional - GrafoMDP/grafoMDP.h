#ifndef GRAFOMDP_H
#define GRAFOMDP_H

typedef struct Vertice {
    int dado;
}Vertice;

typedef struct Grafo{
    int **matriz;
    Vertice *vertices;
    int qtdVertices;
}Grafo;

Grafo* inicializarGrafo();
void inserirVertice(Grafo *g, int dado);
void atualizarVertice(Grafo *g, int indice, int novoDado);
void removerVertice(Grafo *g, int indice);
void inserirAresta(Grafo *g, int origem, int destino, int peso);
void removerAresta(Grafo *g, int origem, int destino);
int verificarAresta(Grafo *g, int origem, int destino);
void exibirGrafo(Grafo *g);
void mostrarVertices(Grafo *g);
int contarArestas(Grafo *g);
int grauVertice(Grafo *g, int indice);
void limparGrafo(Grafo *g);
void destruirGrafo(Grafo *g);
void mostrarCaminho(Grafo* g, int origem, int destino);
void imprimirMatriz(Grafo* g);

#endif // GRAFOMND_H

