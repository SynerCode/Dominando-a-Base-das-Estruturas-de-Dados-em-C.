#include <stdio.h>
#include <stdlib.h>
#include "tabelaHashES.h"

int main() {
    tabelaHash* ht = inicializarTabela();
    int opcao, chave, valor;
    No* resultado;

    do {
        printf("\n===== MENU TABELA HASH (ENCADEAMENTO SEPARADO) =====\n");
        printf("1. Inserir elemento\n");
        printf("2. Atualizar valor\n");
        printf("3. Buscar elemento\n");
        printf("4. Remover elemento\n");
        printf("5. Exibir tabela\n");
        printf("6. Limpar tabela\n");
        printf("7. Destruir tabela e sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a chave (inteiro): ");
                scanf("%d", &chave);
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirElemento(ht, chave, valor);
                break;

            case 2:
                printf("Digite a chave a atualizar: ");
                scanf("%d", &chave);
                printf("Digite o novo valor: ");
                scanf("%d", &valor);
                atualizarValor(ht, chave, valor);
                break;

            case 3:
                printf("Digite a chave a ser buscada: ");
                scanf("%d", &chave);
                resultado = buscarElemento(ht, chave);
                if (resultado)
                    printf("Elemento encontrado: (%d -> %d)\n", resultado->chave, resultado->valor);
                else
                    printf("Chave nao encontrada!\n");
                break;

            case 4:
                printf("Digite a chave a ser removida: ");
                scanf("%d", &chave);
                removerElemento(ht, chave);
                break;

            case 5:
                exibirTabela(ht);
                break;

            case 6:
                limparTabela(ht);
                break;

            case 7:
                destruirTabela(ht);
                printf("Encerrando programa...\n");
                return 0;

            default:
                printf("Opcao invalida!\n");
        }

    } while (1);
}
