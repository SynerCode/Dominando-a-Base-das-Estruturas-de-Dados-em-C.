#include <stdio.h>
#include "grafoLDP.h"

int main() {
    Grafo *g = inicializarGrafo();
    int opcao, dado, origem, destino, indice;

    do {
        printf("\n===== MENU GRAFO =====\n");
        printf("1 - Inserir vertice\n");
        printf("2 - Atualizar vertice\n");
        printf("3 - Remover vertice\n");
        printf("4 - Inserir aresta\n");
        printf("5 - Remover aresta\n");
        printf("6 - Verificar aresta\n");
        printf("7 - Exibir grafo\n");
        printf("8 - Mostrar caminho\n");
        printf("9 - Contar arestas\n");
        printf("10 - Grau de vertice\n");
        printf("11 - Limpar grafo\n");
        printf("12 - Destruir grafo e sair\n");
        printf("\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o dado do vertice: ");
                scanf("%d", &dado);
                inserirVertice(g, dado);
                break;

            case 2:
                printf("\nIndice do vertice a atualizar: ");
                scanf("%d", &indice);
                printf("\nNovo dado: ");
                scanf("%d", &dado);
                atualizarVertice(g, indice, dado);
                break;

            case 3:
                printf("\nIndice do vertice a remover: ");
                scanf("%d", &indice);
                removerVertice(g, indice);
                break;

            case 4:
                printf("\nOrigem da aresta: ");
                scanf("%d", &origem);
                printf("\nDestino da aresta: ");
                scanf("%d", &destino);
                printf("\nDigite o peso da aresta: ");
                scanf("%d", &dado);
                inserirAresta(g, origem, destino, dado);
                break;

            case 5:
                printf("\nOrigem da aresta: ");
                scanf("%d", &origem);
                printf("\nDestino da aresta: ");
                scanf("%d", &destino);
                removerAresta(g, origem, destino);
                break;

            case 6:
                printf("\nOrigem da aresta: ");
                scanf("%d", &origem);
                printf("\nDestino da aresta: ");
                scanf("%d", &destino);
                if (verificarAresta(g, origem, destino))
                    printf("\nExiste aresta.\n");
                else
                    printf("\nNao existe aresta.\n");
                break;

            case 7:
                exibirGrafo(g);
                break;

            case 8:
                printf("\nOrigem da aresta: ");
                scanf("%d", &origem);
                printf("\nDestino da aresta: ");
                scanf("%d", &destino);
                mostrarCaminho(g, origem, destino);
                break;

            case 9:
                printf("\nTotal de arestas: %d\n", contarArestas(g));
                break;

            case 10:
                printf("\nVertice para calcular o grau: ");
                scanf("%d", &indice);
                grauVertice(g, indice);
                break;

            case 11:
                limparGrafo(g);
                printf("\nGrafo limpo!\n");
                break;

            case 12:
                destruirGrafo(g);
                printf("\nGrafo destruido. Encerrando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 12);

    return 0;
}
