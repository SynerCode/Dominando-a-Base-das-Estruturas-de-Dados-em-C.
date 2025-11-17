#include "listaCircular.h"
#include <stdio.h>
#include <stdlib.h>

static NoCircular* lc_criar_no(int valor){
    NoCircular* n = (NoCircular*) malloc(sizeof(NoCircular));
    if(!n){
        fprintf(stderr,"\nERRO: Sem memoria ao criar o no circular\n.");
        exit(EXIT_FAILURE);
    }
    n->dado = valor;
    n->prox = NULL;
    return n;
}

void lc_inserir_inicio(LCCauda* cauda, int valor){
    NoCircular* n = lc_criar_no(valor);
    if(*cauda == NULL){
        n->prox = n;
        *cauda = n;
        return;
    }
    n->prox = (*cauda)->prox;
    (*cauda)->prox = n;
}

void lc_inserir_fim(LCCauda* cauda, int valor){
    NoCircular* n = lc_criar_no(valor);
    if(*cauda == NULL){
        n->prox = n;
        *cauda = n;
        return;
    }
    n->prox = (*cauda)->prox;
    (*cauda)->prox = n;
    *cauda = n;
}

NoCircular* lc_buscar(LCCauda cauda, int valor){
    if(cauda == NULL) return NULL;
    NoCircular* p = cauda->prox;
    do{
        if(p->dado ==  valor) return p;
        p = p->prox;
    }while(p != cauda->prox);
    return NULL;
}

bool lc_atualizar_primeiro(LCCauda cauda, int antigo, int novo){
    NoCircular* no = lc_buscar(cauda, antigo);
    if(!no) return false;
    no->dado = novo;
    return true;
}

bool lc_remover_valor(LCCauda* cauda, int valor){
    if(*cauda == NULL) return false;

    NoCircular* anterior = *cauda;
    NoCircular* atual = (*cauda)->prox;

    do{
        if(atual->dado == valor){
            if(atual == anterior){
                *cauda = NULL;
            }
            else{
                anterior->prox = atual->prox;
                if(atual == *cauda){
                    *cauda = anterior;
                }
            }
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->prox;

    }while(anterior != *cauda);

    return false;
}

void lc_exibir(LCCauda cauda){
    if(cauda == NULL){
        printf("\nLista Circular Vazia....\n");
        return;
    }
    NoCircular* p = cauda->prox;

    do{
        printf("%d -> ", p->dado);
        p = p->prox;

    }while(p != cauda->prox);
    printf("(volta ao inicio)\n");
}

void lc_limpar(LCCauda* cauda){
    if(*cauda == NULL) return;
    NoCircular* primeiro = (*cauda)->prox;
    NoCircular* p = primeiro;

    do{
        NoCircular* prox = p->prox;
        free(p);
        p = prox;

    }while(p != primeiro);
    *cauda = NULL;
}
