#ifndef TABELAHASHEA_H
#define TABELAHASHEA_H
#include <stdbool.h>

typedef enum EstadoCelula{
    CELULA_VAZIA,
    CELULA_OCUPADA,
    CELULA_REMOVIDA
}EstadoCelula;

typedef struct CelulaHash{
    int chave;
    int valor;
    EstadoCelula estado;
}CelulaHash;

typedef struct TabelaHashSimples{
    CelulaHash* vetor;
    int capacidade;
    int qtd_elementos;
    int qtd_tombstones;
}TabelaHashSimples;

TabelaHashSimples* criarTabelaSimples(int cap);
bool inserirElementoTabela(TabelaHashSimples* th, int chave, int valor);
bool atualizarElemento(TabelaHashSimples* th, int chave, int novoValor);
int buscarElemento(TabelaHashSimples* th, int chave, bool* encontrado);
bool removerElemento(TabelaHashSimples* th, int chave);
void exibirTabela(TabelaHashSimples* th);
void limparTabela(TabelaHashSimples* th);
void destruirTabela(TabelaHashSimples* th);
int contarElementos(TabelaHashSimples* th);
int capacidadeTabela(TabelaHashSimples* th);

#endif // TABELAHASHEA_H
