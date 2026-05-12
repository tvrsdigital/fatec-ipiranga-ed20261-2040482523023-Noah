/*----------------------------------------------------------------------------------*/
/*                                FATEC-Ipiranga                                    */        
/*                            ADS - Estrutura de Dados                              */
/*                             Id da Atividade: Atividade-N2-1                      */
/*             Objetivo: Explorando a anatomia da árvore binária                    */
/*                                                                                  */
/*                                  Autor: Noah Tavares Bastos                      */
/*                                                                   Data:05/05/2026*/
/*----------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <MINHABIB.h> 

typedef struct No {
int valor;
struct No *esq;
struct No *dir;
} No;

int calcular_altura(No* no) {
    if (no == NULL) return -1;
    int alt_esq = calcular_altura(no->esq);
    int alt_dir = calcular_altura(no->dir);
    return (alt_esq > alt_dir ? alt_esq : alt_dir) + 1;
}

int calcular_profundidade(No* raiz, int valor, int profundidade_atual) {
    if (raiz == NULL) return -1;
    if (raiz->valor == valor) return profundidade_atual;
    
    int esq = calcular_profundidade(raiz->esq, valor, profundidade_atual + 1);
    if (esq != -1) return esq;
    
    return calcular_profundidade(raiz->dir, valor, profundidade_atual + 1);
}

void imprimir_nos_internos(No* raiz) {
    if (raiz == NULL) return;
    if (raiz->esq != NULL || raiz->dir != NULL) {
        printf("%d ", raiz->valor);
        imprimir_nos_internos(raiz->esq);
        imprimir_nos_internos(raiz->dir);
    }
}

void imprimir_folhas(No* raiz) {
    if (raiz == NULL) return;
    if (raiz->esq == NULL && raiz->dir == NULL) {
        printf("%d ", raiz->valor);
    } else {
        imprimir_folhas(raiz->esq);
        imprimir_folhas(raiz->dir);
    }
}

void imprimir_niveis(No* raiz, int nivel_alvo) {
    if (raiz == NULL) return;
    if (nivel_alvo == 0) printf("%d ", raiz->valor);
    else {
        imprimir_niveis(raiz->esq, nivel_alvo - 1);
        imprimir_niveis(raiz->dir, nivel_alvo - 1);
    }
}

void imprimir_descendentes(No* no) {
    if (no == NULL) return;
    if (no->esq != NULL) {
        printf("%d ", no->esq->valor);
        imprimir_descendentes(no->esq);
    }
    if (no->dir != NULL) {
        printf("%d ", no->dir->valor);
        imprimir_descendentes(no->dir);
    }
}

void imprimir_ancestrais(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) return;

    printf("%d ", raiz->valor);

    if (valor < raiz->valor)
        imprimir_ancestrais(raiz->esq, valor);
    else
        imprimir_ancestrais(raiz->dir, valor);
}

// Localiza o ponteiro de um nó específico para análises de subárvore
No* buscar_no(No* raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) return raiz;
    No* esq = buscar_no(raiz->esq, valor);
    if (esq != NULL) return esq;
    return buscar_no(raiz->dir, valor);
}

void imprimir_pre_ordem(No* n) {
    if (n == NULL) return;
    printf("%d ", n->valor);
    imprimir_pre_ordem(n->esq);
    imprimir_pre_ordem(n->dir);
}

// --- Função Principal de Diagnóstico ---

void analisar_arvore(No* raiz, int valorBusca) {
    if (raiz == NULL) {
        printf("Arvore vazia.\n");
        return;
    }

    printf("=== ANALISES COMPLETAS ===\n");
    printf("Raiz da arvore: %d\n", raiz->valor);

    printf("Nos internos: ");
    imprimir_nos_internos(raiz);
    printf("\nFolhas (externos): ");
    imprimir_folhas(raiz);
    
    printf("\nExibicao por niveis:\n");
    int h = calcular_altura(raiz);
    for (int i = 0; i <= h; i++) {
        printf("Nivel %d: ", i);
        imprimir_niveis(raiz, i);
        printf("\n");
    }

    printf("\n=== ANALISES ESPECIFICAS (Valor: %d) ===\n", valorBusca);
    No* alvo = buscar_no(raiz, valorBusca);

    if (alvo == NULL) {
        printf("Valor %d nao encontrado na arvore.\n", valorBusca);
        return;
    }

    // Grau do nó
    int grau = (alvo->esq != NULL) + (alvo->dir != NULL);
    printf("Grau do no: %d\n", grau);

    // Ancestrais
    printf("Ancestrais: ");
    if (raiz->valor == valorBusca) {
    printf("O no eh a propria raiz (sem ancestrais).");
    } else {
    imprimir_ancestrais(raiz, valorBusca);
    }
    printf("\n");
    
    // Descendentes
    printf("\nDescendentes: ");
    imprimir_descendentes(alvo);

    // Altura e Profundidade
    printf("\nAltura do no: %d", calcular_altura(alvo));
    printf("\nProfundidade do no: %d", calcular_profundidade(raiz, valorBusca, 0));

    // Sub-árvore
    printf("\nSub-arvore a partir do no %d (Pre-ordem): ", valorBusca);
    // Reutilizando lógica de impressão de descendentes incluindo o próprio nó
    imprimir_pre_ordem(alvo);
    printf("\n------------------------------------------\n");
}
