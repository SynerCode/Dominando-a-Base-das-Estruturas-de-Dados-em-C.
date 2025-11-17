#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabelaHashEA.h"

int main(void) {
    int cap;
    printf("Capacidade da tabela (vetor fixo): ");
    if (scanf("%d", &cap) != 1) return 0;

    TabelaHashSimples* th = criarTabelaSimples(cap);
    if (!th) { printf("Erro ao criar tabela\n"); return 0; }

    int opc;
    do {
        printf("\n--- MENU HASH SIMPLES ---\n");
        printf("1 Inserir.\n");
        printf("2 Atualizar.\n");
        printf("3 Buscar.\n");
        printf("4 Remover.\n");
        printf("5 Exibir tabela.\n");
        printf("6 Limpar tabela.\n");
        printf("7 Contar elementos.\n");
        printf("8 Destruir e sair.\n");
        printf("\nEscolha: ");
        if (scanf("%d", &opc) != 1) break;

        if (opc == 1) {
            int ch, val;
            printf("Chave: "); scanf("%d", &ch);
            printf("Valor: "); scanf("%d", &val);
            if (inserirElementoTabela(th, ch, val)) printf("Inserido.\n");
            else printf("Falha inserir: duplicata ou sem espaco.\n");
        }
        else if (opc == 2) {
            int ch, val;
            printf("Chave: "); scanf("%d", &ch);
            printf("Novo valor: "); scanf("%d", &val);
            if (atualizarElemento(th, ch, val)) printf("Atualizado.\n");
            else printf("Chave nao encontrada.\n");
        }
        else if (opc == 3) {
            int ch; bool enc;
            printf("Chave: "); scanf("%d", &ch);
            int v = buscarElemento(th, ch, &enc);
            if (enc) printf("Encontrado valor = %d\n", v);
            else printf("Nao encontrado.\n");
        }
        else if (opc == 4) {
            int ch;
            printf("Chave: "); scanf("%d", &ch);
            if (removerElemento(th, ch)) printf("Removido.\n");
            else printf("Chave nao encontrada.\n");
        }
        else if (opc == 5) {
            exibirTabela(th);
        }
        else if (opc == 6) {
            limparTabela(th);
            printf("Limpo.\n");
        }
        else if (opc == 7) {
            printf("Elementos: %d / Capacidade: %d (tombstones: %d)\n",
                   contarElementos(th), capacidadeTabela(th), th->qtd_tombstones);
        }
        else if (opc == 8) {
            destruirTabela(th);
            printf("Destruido. Saindo.\n");
            break;
        }
        else printf("Opcao invalida.\n");

    } while (1);

    return 0;
}
