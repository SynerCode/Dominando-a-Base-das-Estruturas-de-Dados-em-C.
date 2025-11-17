#ifndef TABELAHASHES_H
#define TABELAHASHES_H
#include <stdbool.h>

#define TAMANHO_TABELA 10

typedef struct No{
    int valor;
    int chave;
    struct No* prox;
}No;

typedef struct tabelaHash{
    No* tabela[TAMANHO_TABELA];
}tabelaHash;

tabelaHash* inicializarTabela();
void inserirElemento(tabelaHash* ht, int chave, int valor);
bool atualizarValor(tabelaHash* ht, int chave, int novoValor);
bool removerElemento(tabelaHash* ht, int chave);
No* buscarElemento(tabelaHash* ht, int chave);
void exibirTabela(tabelaHash* ht);
void limparTabela(tabelaHash* ht);
void destruirTabela(tabelaHash* ht);

#endif // TABELAHASHES_H
