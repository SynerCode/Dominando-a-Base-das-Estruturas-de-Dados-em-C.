#include <stdlib.h>
#include <stdio.h>
#include "arvNaria.h"

static NoListaLimit* criarNoListaLimit(int valor){
    NoListaLimit* no = (NoListaLimit*) malloc(sizeof(NoListaLimit));
    if(!no){
        printf("\nERROR: sem memoria para criar o no....\n");
        return NULL;
    }
    no->dado = valor;
    no->qtdFilhos = 0;
    no->primeiroFilho = NULL;
    no->proximoIrmao = NULL;
    no->pai = NULL;
    return no;
}

ArvoreNariaListaLimit* criarArvoreListaLimit(){
    ArvoreNariaListaLimit* arv = (ArvoreNariaListaLimit*) malloc(sizeof(ArvoreNariaListaLimit));
    if(!arv){
        printf("\nERROR: sem memoria para criar a arvore....\n");
        return NULL;
    }
    arv->raiz = NULL;
    return arv;
}

void destruirArvoreListaLimit(ArvoreNariaListaLimit* arvore){
    if(!arvore) return;
    if(arvore->raiz) limparSubarvoreListaLimit(arvore->raiz);
    free(arvore);
}

bool inserirRaizListaLimit(ArvoreNariaListaLimit* arvore, int valorRaiz){
    if(!arvore) return false;
    if(arvore->raiz != NULL) return false;
    arvore->raiz = criarNoListaLimit(valorRaiz);
    return arvore->raiz != NULL;
}

bool inserirFilhoListaLimit(ArvoreNariaListaLimit* arvore, int valorPai, int valorNovo){
    if(!arvore || arvore->raiz == NULL) return false;

    NoListaLimit* pai = buscarNoListaLimit(arvore->raiz, valorPai);
    if(!pai) return false;

    if(pai->qtdFilhos >= N_FILHOS_MAX) return false;

    NoListaLimit* novo = criarNoListaLimit(valorNovo);
    if(!novo) return false;

    if(pai->primeiroFilho == NULL){
        pai->primeiroFilho = novo;
    }
    else{
        NoListaLimit* atual = pai->primeiroFilho;
        while(atual->proximoIrmao) atual = atual->proximoIrmao;
        atual->proximoIrmao = novo;
    }
    novo->pai = pai;
    pai->qtdFilhos += 1;
    return true;
}

bool atualizarNoListaLimit(ArvoreNariaListaLimit* arvore, int valorAntigo, int novoValor){
    if(!arvore || arvore->raiz == NULL) return false;
    NoListaLimit* no = buscarNoListaLimit(arvore->raiz, valorAntigo);
    if(!no) return false;
    no->dado = novoValor;
    return true;
}

bool removerSubarvoreListaLimit(ArvoreNariaListaLimit* arvore, int valor){
    if(!arvore || arvore->raiz == NULL) return false;
    if(arvore->raiz->dado == valor){
        limparSubarvoreListaLimit(arvore->raiz);
        arvore->raiz = NULL;
        return true;
    }
    NoListaLimit** pilha = (NoListaLimit**) malloc(sizeof(NoListaLimit*) * 1024);
    if(!pilha) return false;
    int top = 0;
    pilha[top++] = arvore->raiz;
    while(top > 0){
        NoListaLimit* atual = pilha[--top];
        NoListaLimit* anterior = NULL;
        NoListaLimit* filho = atual->primeiroFilho;
        while(filho){
            if(filho->dado == valor){
                if(anterior == NULL) atual->primeiroFilho = filho->proximoIrmao;
                else anterior->proximoIrmao = filho->proximoIrmao;
                if(atual->qtdFilhos > 0) atual->qtdFilhos -= 1;
                limparSubarvoreListaLimit(filho);
                free(pilha);
                return true;
            }
            if(filho->primeiroFilho) pilha[top++] = filho->primeiroFilho;
            anterior = filho;
            filho = filho->proximoIrmao;
        }
    }
    free(pilha);
    return false;
}

static void ajustarPaisRec(NoListaLimit* no){
    if(!no) return;
    NoListaLimit* filho = no->primeiroFilho;
    while(filho){
        filho->pai = no;
        ajustarPaisRec(filho);
        filho = filho->proximoIrmao;
    }
}

bool removerNoMantendoFilhosListaLimit(ArvoreNariaListaLimit* arvore, int valor){
    if(!arvore || arvore->raiz == NULL) return false;
    NoListaLimit* alvo = buscarNoListaLimit(arvore->raiz, valor);
    if(!alvo) return false;
    NoListaLimit* pai = alvo->pai;
    /// Elemento é a raiz da estrutura.
    if(pai == NULL){
        if(alvo->qtdFilhos == 0){
            free(alvo);
            arvore->raiz = NULL;
            return true;
        }
        NoListaLimit* novoRoot = alvo->primeiroFilho;
        int totalFilhosNovoRoot = novoRoot->qtdFilhos;
        NoListaLimit* ir = novoRoot->proximoIrmao;
        while(ir) { totalFilhosNovoRoot += 1; ir = ir->proximoIrmao; }
        if(totalFilhosNovoRoot > N_FILHOS_MAX) return false;
        novoRoot->pai = NULL;
        alvo->primeiroFilho = NULL;
        alvo->qtdFilhos = 0;
        free(alvo);
        arvore->raiz = novoRoot;
        ajustarPaisRec(novoRoot);
        return true;
    }
    /// ELE tem pai, não é a raiz
    else{
        if(alvo->qtdFilhos == 0){
            NoListaLimit* atual = pai->primeiroFilho;
            NoListaLimit* anterior = NULL;
            while (atual){
                if( atual == alvo){
                    if(anterior == NULL) pai->primeiroFilho = atual->proximoIrmao;
                    else anterior->proximoIrmao = atual->proximoIrmao;
                    if(pai->qtdFilhos > 0) pai->qtdFilhos -= 1;
                    free(alvo);
                    return true;
                }
                anterior = atual;
                atual = atual->proximoIrmao;
            }
            return false;
        }
        /// Quando tem filhos
        if(pai->qtdFilhos + alvo->qtdFilhos > N_FILHOS_MAX + 1) return false;
        NoListaLimit* ultimoPai = pai->primeiroFilho;
        if(ultimoPai == NULL){
            pai->primeiroFilho = alvo->primeiroFilho;
        }
        else{
            while(ultimoPai->proximoIrmao) ultimoPai = ultimoPai->proximoIrmao;
            ultimoPai->proximoIrmao = alvo->primeiroFilho;
        }
        NoListaLimit* f = alvo->primeiroFilho;
        while(f){
            f->pai = pai;
            f = f->proximoIrmao;
        }
        pai->qtdFilhos += (alvo->qtdFilhos - 1);
        NoListaLimit* atual = pai->primeiroFilho;
        NoListaLimit* anterior = NULL;
        while(atual){
            if(atual == alvo){
                if(anterior == NULL) pai->primeiroFilho = atual->proximoIrmao;
                else anterior->proximoIrmao = atual->proximoIrmao;
                break;
            }
            anterior = atual;
            atual = atual->proximoIrmao;
        }
        alvo->primeiroFilho = NULL;
        alvo->qtdFilhos = 0;
        free(alvo);
        return true;
    }
}

NoListaLimit* buscarNoListaLimit(NoListaLimit* raiz, int valor){
    if(!raiz) return NULL;
    if(raiz->dado == valor) return raiz;
    NoListaLimit* filho = raiz->primeiroFilho;
    while(filho){
        NoListaLimit* res = buscarNoListaLimit(filho, valor);
        if(res) return res;
        filho = filho->proximoIrmao;
    }
    return NULL;
}

void mostrarSubarvoreListaLimit(NoListaLimit* raiz, int valor){
    NoListaLimit* no = buscarNoListaLimit(raiz, valor);
    if(!no){
        printf("\nValor %d nao encontrado.....\n", valor);
        return;
    }
    preOrdemListaLimit(no);
    printf("\n\n");
}

int contarNosListaLimit(NoListaLimit* raiz){
    if(!raiz) return 0;
    int soma = 1;
    NoListaLimit* filho = raiz->primeiroFilho;
    while(filho){
        soma += contarNosListaLimit(filho);
        filho = filho->proximoIrmao;
    }
    return soma;
}

int contarFolhasListaLimit(NoListaLimit* raiz){
    if(!raiz) return 0;
    if(raiz->primeiroFilho == NULL) return 1;
    ///if(raiz->qtdFilhos == 0) return 1;
    int soma = 0;
    NoListaLimit* filho = raiz->primeiroFilho;
    while(filho){
        soma += contarFolhasListaLimit(filho);
        filho = filho->proximoIrmao;
    }
    return soma;
}

int alturaListaLimit(NoListaLimit* raiz){
    if(!raiz) return -1;
    int maior = -1;
    NoListaLimit* filho = raiz->primeiroFilho;
    while(filho){
        int h = alturaListaLimit(filho);
        if(h > maior) maior = h;
        filho = filho->proximoIrmao;
    }
    return maior + 1;
}

int profundidadeListaLimit(NoListaLimit* raiz, int valor, int nivel){
    if(!raiz) return -1;
    if(raiz->dado == valor) return nivel;
    NoListaLimit* filho = raiz->primeiroFilho;
    while(filho){
        int r = profundidadeListaLimit(filho, valor, nivel + 1);
        if(r != -1) return r;
        filho = filho->proximoIrmao;
    }
    return -1;
}

int grauArvoreListaLimit(NoListaLimit* raiz){
    if(!raiz) return 0;
    int max = raiz->qtdFilhos;
    NoListaLimit* filho = raiz->primeiroFilho;
    while(filho){
        int g = grauArvoreListaLimit(filho);
        if(g > max) max = g;
        filho = filho->proximoIrmao;
    }
    return max;
}

int larguraArvoreListaLimit(NoListaLimit* raiz){
    if(!raiz) return 0;
    int capacidade = 256;
    NoListaLimit** fila = (NoListaLimit**) malloc(sizeof(NoListaLimit*) * capacidade);
    if(!fila) return 0;
    int inicio = 0;
    int fim = 0;
    fila[fim++] = raiz;
    int maxL = 0;
    while(inicio < fim){
        int nivelCount = fim - inicio;
        if(nivelCount > maxL) maxL = nivelCount;
        for(int i = 0; i < nivelCount; ++i){
            NoListaLimit* atual = fila[inicio++];
            NoListaLimit* filho = atual->primeiroFilho;
            while(filho){
                if(fim >= capacidade){
                    capacidade *= 2;
                    fila = (NoListaLimit**) realloc(fila, sizeof(NoListaLimit*) * capacidade);
                }
                fila[fim++] = filho;
                filho = filho->proximoIrmao;
            }
        }
    }
    free(fila);
    return maxL;
}

void preOrdemListaLimit(NoListaLimit* raiz){
    if(!raiz) return;
    printf("%d -> ", raiz->dado);
    NoListaLimit* filho = raiz->primeiroFilho;
    while(filho){
        preOrdemListaLimit(filho);
        filho = filho->proximoIrmao;
    }
}

void posOrdemListaLimit(NoListaLimit* raiz){
    if(!raiz) return;
    NoListaLimit* filho = raiz->primeiroFilho;
    while(filho){
        posOrdemListaLimit(filho);
        filho = filho->proximoIrmao;
    }
    printf("%d -> ", raiz->dado);
}

void porNivelListaLimit(NoListaLimit* raiz){
    if(!raiz) return;
    int capacidade = 256;
    NoListaLimit** fila = (NoListaLimit**) malloc(sizeof(NoListaLimit*) * capacidade);
    if(!fila) return;
    int inicio = 0;
    int fim = 0;
    fila[fim++] = raiz;
    while(inicio < fim){
        NoListaLimit* atual = fila[inicio++];
        printf("%d -> ", atual->dado);
        NoListaLimit* filho = atual->primeiroFilho;
        while(filho){
            if(fim >= capacidade){
                capacidade *= 2;
                fila = (NoListaLimit**) realloc(fila, sizeof(NoListaLimit*) * capacidade);
            }
            fila[fim++] = filho;
            filho = filho->proximoIrmao;
        }
    }
    free(fila);
}

void imprimirArvoreListaLimit(NoListaLimit* raiz, int nivel){
    if(!raiz) return;
    NoListaLimit** filhos = (NoListaLimit**) malloc(sizeof(NoListaLimit*) * N_FILHOS_MAX);
    int quantidadeFilhos = 0;
    NoListaLimit* filhoAtual = raiz->primeiroFilho;
    while(filhoAtual){
        filhos[quantidadeFilhos++] = filhoAtual;
        filhoAtual = filhoAtual->proximoIrmao;
    }
    for(int i = quantidadeFilhos - 1; i >= 0; --i) {
        imprimirArvoreListaLimit(filhos[i], nivel + 1);
    }
    for(int i = 0; i < nivel; ++i) printf("  ");

    printf("%d\n", raiz->dado);
    free(filhos);
}

void limparSubarvoreListaLimit(NoListaLimit* raiz){
    if(!raiz) return;
    NoListaLimit* filho = raiz->primeiroFilho;
    while(filho){
        NoListaLimit* prox = filho->proximoIrmao;
        limparSubarvoreListaLimit(filho);
        filho = prox;
    }
    free(raiz);
}
