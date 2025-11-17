#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabelaHashES.h"

static int funcaoHash(int chave){
    return chave % TAMANHO_TABELA;
}

static No* criarNo(int chave, int valor){
    No* novo = (No*) malloc(sizeof(No));
    if(!novo){
        printf("\nERROR: sem memoria para criar o no...\n");
        return NULL;
    }
    novo->valor = valor;
    novo->chave = chave;
    novo->prox = NULL;
    return novo;
}

tabelaHash* inicializarTabela(){
    tabelaHash* ht = (tabelaHash*) malloc(sizeof(tabelaHash));
    if(!ht){
        printf("\nERROR: sem memoria para criar a tabela....\n");
        return NULL;
    }

    for(int i = 0; i < TAMANHO_TABELA; i++){
        ht->tabela[i] = NULL;
    }
    return ht;
}

void inserirElemento(tabelaHash* ht, int chave, int valor){

    if(buscarElemento(ht, chave)){
        printf("\nChave duplicada, insira outra chave.....\n");
        return;
    }

    int indice = funcaoHash(chave);
    No* novo = criarNo(chave, valor);

    novo->prox = ht->tabela[indice];
    ht->tabela[indice] = novo;

    printf("\nElemento (%d -> %d) inserido no indice [%d].\n", chave, valor, indice);
}

bool atualizarValor(tabelaHash* ht, int chave, int novoValor){
    No* aux = buscarElemento(ht, chave);

    if(!aux){
        printf("\nElemento nao encontrado...\n");
        return false;
    }
    aux->valor = novoValor;

    printf("\nValor atualizado com chave %d para o novo valor %d.", chave, novoValor);
    return true;
}

bool removerElemento(tabelaHash* ht, int chave){
    int indice = funcaoHash(chave);
    No* atual = ht->tabela[indice];
    No* anterior = NULL;

    while(atual != NULL){
        if(atual->chave == chave){
            if(anterior == NULL){
                ht->tabela[indice] = atual->prox;
            }
            else{
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("\nElemento removido com sucesso....\n");
            return true;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("\nElemento nao encontrado....\n");
    return false;
}

No* buscarElemento(tabelaHash* ht, int chave){
    int indice = funcaoHash(chave);
    No* aux = ht->tabela[indice];

    while(aux != NULL){
        if(aux->chave == chave){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void exibirTabela(tabelaHash* ht){
    printf("\n======== Conteudo da Tabela Hash ========\n");

    for(int i = 0; i < TAMANHO_TABELA; i++){
        printf("[%d] : ", i);
        No* aux = ht->tabela[i];
        while(aux != NULL){
            printf(" (%d -> %d) -> ", aux->chave, aux->valor);
            aux = aux->prox;
        }
        printf("NULL.\n");
    }
    printf("\n=========================================\n");
}

void limparTabela(tabelaHash* ht){
    for(int i = 0; i < TAMANHO_TABELA; i++){
        No* aux = ht->tabela[i];
        while(aux != NULL){
            No* temp = aux;
            aux = aux->prox;
            free(temp);
        }
        ht->tabela[i] = NULL;
    }
    printf("\nDados excluidos com sucesso....\n");
}

void destruirTabela(tabelaHash* ht){
    limparTabela(ht);
    free(ht);
    printf("\nEstrutura destruida....\n");
}

