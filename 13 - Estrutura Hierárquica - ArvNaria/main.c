#include <stdio.h>
#include <stdlib.h>
#include "arvNaria.h"

void exibirMenu(){
    printf("\n\n=========== Menu - ARVORE N-ARIA ===========\n\n");
    printf(" 1 - Inserir raiz\n");
    printf(" 2 - Inserir Filho\n");
    printf(" 3 - Atualizar No.\n");
    printf(" 4 - Remover Sub-Arvore.\n");
    printf(" 5 - Remover No mantendo filhos.\n");
    printf(" 6 - Contar Nos.\n");
    printf(" 7 - Contar Folhas.\n");
    printf(" 8 - Altura da Arvore.\n");
    printf(" 9 - Profundidade de um No.\n");
    printf("10 - Grau Maximo da Arvore.\n");
    printf("11 - Largura da Arvore.\n");
    printf("12 - Mostrar Percurso Pre-Ordem.\n");
    printf("13 - Mostrar Percurso Pos-Ordem.\n");
    printf("14 - Mostrar Percurso Por Nivel.\n");
    printf("15 - Mostrar Sub-Arvore a partir de Valor.\n");
    printf("16 - Imprimir Arvore em formato Visual.\n");
    printf(" 0 - Sair.\n");
    printf("\nEscolha uma Opcao : ");
}

int main(){

    ArvoreNariaListaLimit* arvore = criarArvoreListaLimit();
    int opcao, valor, valor2;

    do{
        exibirMenu();
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao){
            case 1:
                printf("\nDigite o valor da Raiz: ");
                scanf("%d", &valor);
                if(inserirRaizListaLimit(arvore, valor)) printf("\nRaiz inserida com Sucesso!\n");
                else printf("\nFalha ao inserir raiz (ja existe ou erro de memoria...).\n");
                break;

            case 2:
                printf("\nDigite o valor do pai: ");
                scanf("%d", &valor);
                printf("\nDigite o valor do novo Elemento: ");
                scanf("%d", &valor2);
                if(inserirFilhoListaLimit(arvore, valor, valor2)) printf("\nFilho inserido com sucesso!\n");
                else printf("\nFalha ao inserir filho (pai inexistente, limite atingido ou erro).\n");
                break;

            case 3:
                printf("\nDigite o valor do no a atualizar: ");
                scanf("%d", &valor);
                printf("\nDigite o novo valor: ");
                scanf("%d", &valor2);
                if(atualizarNoListaLimit(arvore, valor, valor2)) printf("\nNo atualizado com sucesso!\n");
                else printf("\nFalha: no nao encontrado.\n");
                break;

            case 4:
                printf("\nDigite o valor do no cuja sub-arvore deseja remover: ");
                scanf("%d", &valor);
                if(removerSubarvoreListaLimit(arvore, valor)) printf("\nSub-Arvore removida com sucesso!\n");
                else printf("\nFalha ao remover sub-arvore (valor nao existe ou erro).\n");
                break;

            case 5:
                printf("\nDigite o valor do no a remover (mantendo filhos): ");
                scanf("%d", &valor);
                if(removerNoMantendoFilhosListaLimit(arvore, valor)) printf("\nNo removida e filhos preservados com sucesso!\n");
                else printf("\nFalha ao remover o elemento (limite excedido ou valor inexistente).\n");
                break;

            case 6:
                printf("\nTotal de Nos: %d.\n", contarNosListaLimit(arvore->raiz));
                break;

            case 7:
                printf("\nTotal de Folhas: %d.\n", contarFolhasListaLimit(arvore->raiz));
                break;

            case 8:
                printf("\nAltura da Arvore: %d.\n", alturaListaLimit(arvore->raiz));
                break;

            case 9:
                printf("\nDigite o valor do No: ");
                scanf("%d", &valor);
                printf("\nProfundidade: %d", profundidadeListaLimit(arvore->raiz, valor, 0));
                break;

            case 10:
                printf("\nGrau da Arvore: %d.\n", grauArvoreListaLimit(arvore->raiz));
                break;

            case 11:
                printf("\nLargura da Arvore: %d.\n", larguraArvoreListaLimit(arvore->raiz));
                break;

            case 12:
                printf("\nPercurso em Pre-Ordem: " );
                preOrdemListaLimit(arvore->raiz);
                printf("\n");
                break;

            case 13:
                printf("\nPercurso em Pos-Ordem: " );
                posOrdemListaLimit(arvore->raiz);
                printf("\n");
                break;

            case 14:
                printf("\nPercurso Por Nivel: " );
                porNivelListaLimit(arvore->raiz);
                printf("\n");
                break;

            case 15:
                printf("\nDigite o valor da Sub-Arvore para mostrar: ");
                scanf("%d", &valor);
                mostrarSubarvoreListaLimit(arvore->raiz, valor);
                break;

            case 16:
                printf("\nArvore (Formato Visual) : \n\n\n");
                imprimirArvoreListaLimit(arvore->raiz, 0);
                break;

            case 0:
                printf("\nSaindo do Sistema......\n");
                break;

            default:
                printf("\nOpcao invalida.\nTente novamente....\n");
                break;

        }

    }while(opcao != 0);

    destruirArvoreListaLimit(arvore);
    return 0;
}

