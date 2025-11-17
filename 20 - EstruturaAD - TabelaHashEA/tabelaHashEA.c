#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tabelaHashEA.h"

static int funcao_hash_simples(int chave, int cap){
    int h = chave % cap;
    if(h < 0) h += cap;
    return h;
}

static CelulaHash* alocar_vetor_simples(int cap){
    CelulaHash* v = (CelulaHash*) malloc(sizeof(CelulaHash) * cap);
    if(!v){
        return NULL;
    }
    for(int i = 0; i < cap; i++){
        v[i].chave = 0;
        v[i].valor = 0;
        v[i].estado = CELULA_VAZIA;
    }
    return v;
}

TabelaHashSimples* criarTabelaSimples(int cap){
    if(cap <= 0) return NULL;

    TabelaHashSimples* th = (TabelaHashSimples*) malloc(sizeof(TabelaHashSimples));
    if(!th){
        return NULL;
    }
    th->vetor = alocar_vetor_simples(cap);

    if(!th->vetor) {free(th); return NULL;}

    th->capacidade = cap;
    th->qtd_elementos = 0;
    th->qtd_tombstones = 0;
    return th;
}

bool inserirElementoTabela(TabelaHashSimples* th, int chave, int valor){
    if(!th) return false;

    if(th->qtd_elementos >= th->capacidade){
        return false;
    }

    int cap = th->capacidade;
    int idx = funcao_hash_simples(chave, cap);
    int primeira_tombstone = -1;

    for(int i = 0; i < cap; ++i){
        int pos = (idx + i) % cap;
        CelulaHash* c = &th->vetor[pos];

        if(c->estado == CELULA_VAZIA){
            int alvo = (primeira_tombstone != -1) ? primeira_tombstone : pos;
            CelulaHash* d = &th->vetor[alvo];
            d->chave = chave;
            d->valor = valor;
            d->estado = CELULA_OCUPADA;
            th->qtd_elementos++;
            if(primeira_tombstone != -1) th->qtd_tombstones--;
            return true;
        }
        if(c->estado == CELULA_REMOVIDA){
            if(primeira_tombstone == -1) primeira_tombstone = pos;
        }
        else if(c->estado == CELULA_OCUPADA){
            if(c->chave == chave){
                return false;
            }
        }
    }
    return false;
}

bool atualizarElemento(TabelaHashSimples* th, int chave, int novoValor){
    if(!th) return false;

    int cap = th->capacidade;
    int idx = funcao_hash_simples(chave, cap);

    for(int i = 0; i < cap; ++i){
        int pos = (idx + i) % cap;
        CelulaHash* c = &th->vetor[pos];

        if(c->estado == CELULA_VAZIA){
            return false;
        }
        else if(c->estado == CELULA_OCUPADA && c->chave == chave){
            c->valor = novoValor;
            return true;
        }
    }
    return false;
}

int buscarElemento(TabelaHashSimples* th, int chave, bool* encontrado){
    if(!th) return -1;

    int cap = th->capacidade;
    int idx = funcao_hash_simples(chave, cap);

    for(int i = 0; i < cap; ++i){
        int pos = (idx + i) % cap;
        CelulaHash* c = &th->vetor[pos];

        if(c->estado == CELULA_VAZIA){
            *encontrado = false;
            return -1;
        }
        else if(c->estado == CELULA_OCUPADA && c->chave == chave){
            *encontrado = true;
            return c->valor;
        }
    }
    *encontrado = false;
    return -1;
}

bool removerElemento(TabelaHashSimples* th, int chave){
    if(!th) return false;

    int cap = th->capacidade;
    int idx = funcao_hash_simples(chave, cap);

    for(int i = 0; i < cap; ++i){
        int pos = (idx + i) % cap;
        CelulaHash* c = &th->vetor[pos];

        if(c->estado == CELULA_VAZIA){
            return false;
        }
        else if(c->estado == CELULA_OCUPADA && c->chave == chave){
            c->estado = CELULA_REMOVIDA;
            th->qtd_elementos--;
            th->qtd_tombstones++;
            return true;
        }
    }
    return false;
}

void exibirTabela(TabelaHashSimples* th){
    if(!th) {
        printf("\n Tabela nula...\n");
        return;
    }
    printf("\n ===== Conteudo da Tabela =====\n");
    printf("\nCapacida = %d, QTD Elementos = %d, QTD Tombstones = %d.\n", th->capacidade, th->qtd_elementos, th->qtd_tombstones);

    for(int i = 0; i < th->capacidade; i++){
        CelulaHash* c = &th->vetor[i];
        printf("[%d] : ", i);

        if(c->estado == CELULA_VAZIA){
            printf("VAZIO...\n");
        }
        else if(c->estado == CELULA_REMOVIDA){
            printf("REMOVIDO....\n");
        }
        else{
            printf("OCUPADO -> chave: %d, valor: %d.\n", c->chave, c->valor);
        }
    }
    printf("\n================================\n");
}

void limparTabela(TabelaHashSimples* th){
    if(!th) return;

    for(int i = 0; i < th->capacidade; i++){
        th->vetor[i].estado = CELULA_VAZIA;
        th->vetor[i].chave = 0;
        th->vetor[i].valor = 0;
    }
    th->qtd_elementos = 0;
    th->qtd_tombstones = 0;
}

void destruirTabela(TabelaHashSimples* th){
    if(!th) return;
    if(th->vetor) free(th->vetor);
    free(th);
}

int contarElementos(TabelaHashSimples* th){
    if(!th) return -1;
    return th->qtd_elementos;
}

int capacidadeTabela(TabelaHashSimples* th){
    if(!th) return -1;
    return th->capacidade;
}
