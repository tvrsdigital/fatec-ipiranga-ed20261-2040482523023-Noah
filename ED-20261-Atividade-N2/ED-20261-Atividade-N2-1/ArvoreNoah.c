#include "arvore.h"

// Inserção da arvore 
noh* inserir(noh* raiz, int valor) {
    if (raiz == NULL) {
        noh *novo = (noh*) malloc(sizeof(noh));
        if (novo == NULL) return NULL; // Segurança de memória
        novo->conteudo = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        return novo;
    }
    if (valor < raiz->conteudo) {
        raiz->esquerdo = inserir(raiz->esquerdo, valor);
    } else if (valor > raiz->conteudo) {
        raiz->direito = inserir(raiz->direito, valor);
    }
    return raiz;
}

// Identifica a raiz 
void identificaRaiz(noh* raiz) {
    if (raiz != NULL) printf("Raiz: %d\n", raiz->conteudo);
}

// Identifica Nós Internos 
void identificaInternos(noh* raiz) {
    if (raiz == NULL) return;
    if (raiz->esquerdo != NULL || raiz->direito != NULL) {
        printf("%d ", raiz->conteudo);
    }
    identificaInternos(raiz->esquerdo);
    identificaInternos(raiz->direito);
}

// Identifica as Folhas (ou nós externos)
void identificaFolhas(noh* raiz) {
    if (raiz == NULL) return;
    if (raiz->esquerdo == NULL && raiz->direito == NULL) {
        printf("%d ", raiz->conteudo);
    }
    identificaFolhas(raiz->esquerdo);
    identificaFolhas(raiz->direito);
}

// Identifica os Graus 
void identificaGrau(noh* raiz) {
    if (raiz == NULL) return;
    int grau = 0;
    if (raiz->esquerdo != NULL) grau++;
    if (raiz->direito != NULL) grau++;
    printf("Nó %d: Grau %d\n", raiz->conteudo, grau);
    identificaGrau(raiz->esquerdo);
    identificaGrau(raiz->direito);
}

// Identifica os níveis 
void imprimirNivel(noh* raiz, int nivelDesejado, int nivelAtual) {
    if (raiz == NULL) return;
    if (nivelAtual == nivelDesejado) {
        printf("%d ", raiz->conteudo);
    } else {
        imprimirNivel(raiz->esquerdo, nivelDesejado, nivelAtual + 1);
        imprimirNivel(raiz->direito, nivelDesejado, nivelAtual + 1);
    }
}

// Identifica os descendentes
void identificaDescendentes(noh* raiz) {
    if (raiz == NULL) return;
    printf("%d ", raiz->conteudo);
    identificaDescendentes(raiz->esquerdo);
    identificaDescendentes(raiz->direito);
}

// Identifica os ancestrais 
bool identificaAncestrais(noh* raiz, int alvo) {
    if (raiz == NULL) return false;
    if (raiz->conteudo == alvo) return true;
    if (identificaAncestrais(raiz->esquerdo, alvo) || identificaAncestrais(raiz->direito, alvo)) {
        printf("%d ", raiz->conteudo);
        return true;
    }
    return false;
}

int maior (int a, int b){
    if (a > b) return a; 
    else return b; 
}
int AlturaNo(noh* raiz){
    if(raiz == NULL) return -1;
    int AlturaEsq = AlturaNo(raiz->esquerdo);
    int AlturaDir = AlturaNo(raiz->direito); 

    return 1 + maior(AlturaEsq, AlturaDir); 
} 

int ProfundidadeNo(noh* raiz, int alvo, int profundidadeAtual){
    if(raiz == NULL) return -1; 
    if (raiz->conteudo == alvo){
        return profundidadeAtual; 
    }
    if (alvo < raiz->conteudo) {
        return ProfundidadeNo(raiz->esquerdo, alvo, profundidadeAtual + 1);
    } else {
        return ProfundidadeNo(raiz->direito, alvo, profundidadeAtual + 1);
    }
}

void ExibirSubArvore(noh* raiz, int valorRaizSub) {
    if (raiz == NULL) return;

    if (raiz->conteudo == valorRaizSub) {
        printf("Sub-árvore (raiz %d):\n", valorRaizSub);
        identificaDescendentes(raiz);  
        printf("\n");
        return;
    }

    // Continua procurando o nó pela árvore de busca
    if (valorRaizSub < raiz->conteudo) {
        ExibirSubArvore(raiz->esquerdo, valorRaizSub);
    } else {
        ExibirSubArvore(raiz->direito, valorRaizSub);
    }
}