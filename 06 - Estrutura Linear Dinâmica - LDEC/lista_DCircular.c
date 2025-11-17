#include <stdio.h>
#include <stdlib.h>
#include "lista_DCircular.h"

static NoDuploCircular* ldc_criar_no(int valor){
    NoDuploCircular* n = (NoDuploCircular*) malloc(sizeof(NoDuploCircular));
    if(!n){
        fprintf(stderr, "\nERRO: Sem memoria para criar o no...\n");
        exit(EXIT_FAILURE);
    }
    n->dado = valor;
    n->prox = n->ant = NULL;
    return n;
}

void ldc_inserir_inicio(LDCCauda* cauda, int valor){
    NoDuploCircular* n = ldc_criar_no(valor);
    if(*cauda == NULL){
        n->prox = n;
        n->ant = n;
        *cauda = n;
        return;
    }
    NoDuploCircular* primeiro = (*cauda)->prox;
    n->prox = primeiro;
    n->ant = *cauda;
    primeiro->ant = n;
    (*cauda)->prox = n;
}

void ldc_inserir_fim(LDCCauda* cauda, int valor){
    NoDuploCircular* n = ldc_criar_no(valor);
    if(*cauda == NULL){
        n->prox = n;
        n->ant = n;
        *cauda = n;
        return;
    }
    NoDuploCircular* primeiro = (*cauda)->prox;
    n->prox = primeiro;
    n->ant = *cauda;
    primeiro->ant = n;
    (*cauda)->prox = n;
    *cauda = n;
}

NoDuploCircular* ldc_buscar(LDCCauda cauda, int valor){
    if(cauda == NULL) return NULL;
    NoDuploCircular* p = cauda->prox;
    do{
        if(p->dado == valor) return p;
        p = p->prox;
    }while(p != cauda->prox);
    return NULL;
}

bool ldc_atualizar_primeiro(LDCCauda cauda, int antigo, int novo){
    NoDuploCircular* n = ldc_buscar(cauda, antigo);
    if(!n) return false;
    n->dado = novo;
    return true;
}

bool ldc_remover_valor(LDCCauda* cauda, int valor){
    if(*cauda == NULL) return false;
    NoDuploCircular* p = (*cauda)->prox;
    do{
        if(p->dado == valor){
            if(p->prox == p){
                *cauda = NULL;
            }
            else{
                p->ant->prox = p->prox;
                p->prox->ant = p->ant;
                if(p == *cauda){
                    *cauda = p->ant;
                }
            }
            free(p);
            return true;
        }
        p = p->prox;
    }while(p != (*cauda)->prox);
    return false;
}

void ldc_exibir(LDCCauda cauda){
    if(cauda == NULL){
        printf("\nLista DC Vazia...\n");
        return;
    }
    NoDuploCircular* p = cauda->prox;
    do{
        printf("%d -> ", p->dado);
        p = p->prox;
    }while(p != cauda->prox);
    printf("(Voltou para o inicio)\n");
}

void ldc_exibir_reverso(LDCCauda cauda){
    if(cauda == NULL){
        printf("\nLista DC vazia...\n");
        return;
    }
    NoDuploCircular* p = cauda;
    do{
        printf("%d -> ", p->dado);
        p = p->ant;
    }while(p != cauda);
    printf("(Volta ao fim)\n");
}

void ldc_limpar(LDCCauda* cauda){
    if(*cauda == NULL) return;
    NoDuploCircular* primeiro = (*cauda)->prox;
    NoDuploCircular* p = primeiro;
    do{
        NoDuploCircular* prox = p->prox;
        free(p);
        p = prox;
    }while(p != primeiro);
    *cauda = NULL;
}
