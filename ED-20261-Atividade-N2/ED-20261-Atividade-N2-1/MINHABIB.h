#ifndef MINHABIB_H
#define MINHABIB_H

typedef struct No {
int valor;
struct No *esq;
struct No *dir;
} No;

// Função principal de diagnóstico da atividade
void analisar_arvore(No* raiz, int valorBusca);
// Funções auxiliares obrigatórias para organização
void imprimir_nos_internos(No* raiz);
void imprimir_folhas(No* raiz);
void imprimir_niveis(No* raiz, int nivel_atual);
int calcular_altura(No* no);
int calcular_profundidade(No* raiz, int valor, int profundidade_atual);
void imprimir_ancestrais(No* raiz, int valor);
void imprimir_descendentes(No* no);

#endif