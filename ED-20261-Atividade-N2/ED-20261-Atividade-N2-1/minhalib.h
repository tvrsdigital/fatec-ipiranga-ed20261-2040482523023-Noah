#ifndef ARVORE_H
#define ARVORE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura conforme sua lógica [cite: 12]
typedef struct noh {
    int conteudo;
    struct noh *esquerdo;
    struct noh *direito;
} noh;

// Assinaturas das funções que você desenvolveu
noh* inserir(noh* raiz, int valor);
void identificaRaiz(noh* raiz);
void identificaInternos(noh* raiz);
void identificaFolhas(noh* raiz);
void identificaGrau(noh* raiz);
void imprimirNivel(noh* raiz, int nivelDesejado, int nivelAtual);
void identificaDescendentes(noh* raiz);
bool identificaAncestrais(noh* raiz, int alvo);
int maior (int a, int b); 
int AlturaNo(noh* raiz); 
int ProfundidadeNo(noh* raiz, int alvo, int profundidadeAtual); 
void ExibirSubArvore(noh* raiz, int valorRaizSub); 


#endif