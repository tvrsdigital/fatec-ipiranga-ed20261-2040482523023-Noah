RA: 2040482523023 - Noah Tavares Bastos 

#include <stdio.h> 
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *esq;
    struct No *dir;
} No; 

No* inserir (No *raiz, int valor){
    if (raiz == NULL){
         raiz = (No*)malloc(sizeof(No));
         raiz->dado = valor; 
         raiz->esq = NULL;  
         raiz->dir = NULL; 
    return raiz; 
    }
    if(valor < raiz->dado){
        raiz->esq = inserir(raiz->esq,valor);
    } else{
        raiz->dir = inserir(raiz->dir,valor); 
    }
    return raiz; 
}

int alturaNo(No *no){
    if (no == NULL) return -1; 
    int alt_esq = alturaNo(no->esq);
    int alt_dir = alturaNo(no->dir); 
    return 1 + (alt_esq>alt_dir ? alt_esq : alt_dir); 
}

int profundidadeNo(No* raiz, int valor, int prof) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return prof;
    int esq = profundidadeNo(raiz->esq, valor, prof + 1);
    if (esq != -1) return esq;
    return profundidadeNo(raiz->dir, valor, prof + 1);

}

int grauNo(No *no) {
    if (no == NULL) return 0; // Uma boa prática para evitar falhas de segmentação
    if (no->esq == NULL && no->dir == NULL) {
        return 0;
    }
    if (no->esq != NULL && no->dir != NULL) {
        return 2;
    }
    return 1;
}

No* buscar(No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) return raiz;
    if (valor < raiz->dado) return buscar(raiz->esq, valor);
    return buscar(raiz->dir, valor);
}

void percursoEmOrdemGrau(No* raiz) {
    if (raiz != NULL) {
        percursoEmOrdemGrau(raiz->esq); // Visita a esquerda
        printf("No %d -> Grau: %d\n", raiz->dado, grauNo(raiz)); // Visita a raiz
        percursoEmOrdemGrau(raiz->dir); // Visita a direita
    }
}

void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    
    // 1. Visita e libera as subárvores primeiro
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    
    // 2. Só agora que os filhos sumiram, libera o nó atual
    free(raiz);
}

int main(){
    // No início da main:
    No* raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    for(int i = 0; i < 11; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("--- Item A: Alturas ---\n");
    printf("Altura do no 50: %d\n", alturaNo(buscar(raiz, 50)));
    printf("Altura do no 30: %d\n", alturaNo(buscar(raiz, 30)));
    printf("Altura do no 70: %d\n", alturaNo(buscar(raiz, 70)));
    printf("Altura do no 20: %d\n", alturaNo(buscar(raiz, 20)));
    printf("Altura do no 10: %d\n", alturaNo(buscar(raiz, 10)));

    printf("\n--- Item B: Profundidades ---\n");
    printf("Profundidade do no 50: %d\n", profundidadeNo(raiz, 50, 0));
    printf("Profundidade do no 30: %d\n", profundidadeNo(raiz, 30, 0));
    printf("Profundidade do no 70: %d\n", profundidadeNo(raiz, 70, 0));
    printf("Profundidade do no 45: %d\n", profundidadeNo(raiz, 45, 0));
    printf("Profundidade do no 10: %d\n", profundidadeNo(raiz, 10, 0));

    printf("\n--- Item C: Grau de cada no (Em-Ordem) ---\n");
    percursoEmOrdemGrau(raiz);

    printf("\n--- Item D: Altura total da Árvore ---\n");
    printf("Altura total da arvore: %d\n", alturaNo(raiz));


//            ESTRUTURA DA ABB RESULTANTE
//            
//                 50
//               /   \                 
//             30      70
//            /  \    /  \             
//           20  40  60  80
//          / \   \   \                  
//         10 25  45  65

//   VERIFICAÇÃO MANUAL DE TRÊS NÓS:
//   - Nó 50 (Raiz): Altura = 3, Profundidade = 0, Grau = 2
//   - Nó 30: Altura = 2, Profundidade = 1, Grau = 2
//   - Nó 10 (Folha): Altura = 0, Profundidade = 3, Grau = 0


    // --------- PARTE C: Liberação de Memória --------- 
    liberarArvore(raiz);
    raiz = NULL;

    return 0; 
}