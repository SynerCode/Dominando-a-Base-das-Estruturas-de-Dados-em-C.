#include <stdio.h>
#include <stdlib.h>
#include "arvoreB.h"

int main() {

    Arvore* arvore = criarArvore();
    int opcao, valor, novoValor;

    do{
        printf("\n============= Menu Arvore Binaria =============\n");
        printf("1 - Inserir no. \n");
        printf("2 - Atualizar no. \n");
        printf("3 - Remover no. \n");
        printf("4 - Buscar no. \n");
        printf("5 - Mostrar numeros de nos e folhas. \n");
        printf("6 - Mostrar altura, grau, largura. \n");
        printf("7 - Mostrar a profundidade de um no. \n");
        printf("8 - Percursos (Pre, Em Ordem, Pos e Nivel. \n");
        printf("9 - Imprimir a Arvore. \n");
        printf("10 - Limpar a Arvore. \n");
        printf("0 - SAIR.....\n");
        printf("\n\nEscolha a opcao : ");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                printf("\nDigite o valor do no : ");
                scanf("%d", &valor);
                if(inserirNo(arvore, valor))
                    printf("\nNo %d inserido com sucesso!\n", valor);
                else printf("\nFalha ao inserir no...\n");
                break;

            case 2:
                printf("\nDigite o valor antigo : ");
                scanf("%d", &valor);
                printf("\nDigite o novo valor : ");
                scanf("%d", &novoValor);
                if(atualizarNo(arvore, valor, novoValor))
                    printf("\nNo %d atualizado para %d...\n", valor, novoValor);
                else printf("\nNo não foi encontrado....\n");
                break;

            case 3:
                printf("\nDigite o valor do no para remover : ");
                scanf("%d", &valor);
                if(removerNo(arvore, valor))
                    printf("\nNo %d removido com sucesso...\n", valor);
                else printf("\nNo nao encontrado....\n");

            case 4:
                printf("\nDigite o valor para buscar na arvore : ");
                scanf("%d", &valor);
                No* encontrado = buscarNo(arvore->raiz, valor);
                if(encontrado != NULL)
                    printf("\nNo %d encontrado...\n", valor);
                else printf("\nNo nao encontrado...\n");
                break;

            case 5:
                printf("\nNumero de nos: %d.\n", contarNos(arvore->raiz));
                printf("\nNumero de folhas : %d.\n", contarFolhas(arvore->raiz));
                break;

            case 6:
                printf("\nAltura da arvore : %d.\n", altura(arvore->raiz));
                printf("\nGrau da arvore : %d.\n", grauDaArvore(arvore->raiz));
                printf("\nLargura da arvore : %d.\n", largura(arvore->raiz));
                break;

            case 7:
                printf("\nDigite o valor do no para profundidade : ");
                scanf("%d", &valor);
                int prof = profundidade(arvore->raiz, valor, 0);
                if(prof != -1)
                    printf("\nProfundidade do %d: %d.\n", valor, prof);
                else printf("\nNo nao encontrado....\n");
                break;

            case 8:
                printf("\nPre-Ordem.\n");
                preOrdem(arvore->raiz);
                printf("\nEm Ordem.\n");
                emOrdem(arvore->raiz);
                printf("\nPos-Ordem.\n");
                posOrdem(arvore->raiz);
                printf("\nPor Nivel.\n");
                porNivel(arvore->raiz);
                printf("\n\n");
                break;

            case 9:
                printf("\nArvore visual...\n\n\n");
                imprimirArvore(arvore->raiz, 0);
                printf("\n\n");
                break;

            case 10:
                limparArvore(arvore->raiz);
                arvore->raiz = NULL;
                printf("\nArvore limpa....\n");
                break;

            case 0:
                destruirArvore(arvore);
                printf("\nArvore destruida....\n");
                printf("\nSaindo do sistema....\n");
                break;

            default:
                printf("\nOpcao invalida....\n");
        }

    }while(opcao != 0);

    return 0;
}
