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

void imprimirAncestral(No *raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) {
        return; // Caso base: chegou ao fim ou achou o próprio nó
    }

    if (valor < raiz->dado) {
        imprimirAncestral(raiz->esq, valor);
    } else {
        imprimirAncestral(raiz->dir, valor);
    }

    // O truque está aqui! Na volta da recursão, imprimimos o nó atual
    printf("%d ", raiz->dado);
}

void imprimirTodosDescendentes(No *no){
    if (no == NULL) return;
    
    if (no->esq != NULL) {
        printf("%d ", no->esq->dado);
        imprimirTodosDescendentes(no->esq);
    }
    if (no->dir != NULL) {
        printf("%d ", no->dir->dado);
        imprimirTodosDescendentes(no->dir);
    }
}

void imprimirDescendentes(No *raiz, int valor){
    if(raiz == NULL) return; 
    if(valor < raiz->dado){
        imprimirDescendentes(raiz->esq,valor);
    } else if(valor > raiz->dado){
        imprimirDescendentes(raiz->dir,valor); 
    } else{
        imprimirTodosDescendentes(raiz); 
    }
}

int tamanhoSubarvore(No *no) {
    if (no == NULL) return 0;
    return 1 + tamanhoSubarvore(no->esq) + tamanhoSubarvore(no->dir);
}

// Função principal 
int contarDescendentes(No *no) {
    if (no == NULL) return 0;    
    // O total de descendentes é o tamanho da subárvore menos o próprio nó
    return tamanhoSubarvore(no) - 1;
}


void relatorioNo(No *raiz,int valor){
// 1. Localiza o nó na árvore
    No* noAlvo = buscar(raiz, valor);
    
    if (noAlvo == NULL) {
        printf("Valor %d nao encontrado na arvore.\n", valor);
        return;
    }

    // 2. Imprime o cabeçalho formatado
    printf("+---------------------------------------+\n");
    printf("|  RELATORIO DO NO: %-19d |\n", valor);
    printf("+---------------------------------------+\n");

    // 3. Imprime Profundidade, Altura e Grau
    // Nota: Reaproveitamos as funções criadas no Ex 05
    printf("|  Profundidade  : %-20d |\n", profundidadeNo(raiz, valor, 0));
    printf("|  Altura        : %-20d |\n", alturaNo(noAlvo));
    printf("|  Grau          : %-20d |\n", grauNo(noAlvo));

    // 4. Imprime os Ancestrais
    printf("|  Ancestrais    : ");
    imprimirAncestral(raiz, valor);
    printf("%-20s |\n", ""); // Ajusta o espaçamento da borda direita

    // 5. Imprime os Descendentes
    printf("|  Descendentes  : ");
    imprimirDescendentes(raiz, valor);
    printf("%-20s |\n", ""); // Ajusta o espaçamento da borda direita

    // 6. Imprime a Quantidade de Descendentes
    printf("|  Qtd Descend.  : %-20d |\n", contarDescendentes(noAlvo));
    printf("+---------------------------------------+\n");
}


int main(){
    // No início da main:
    No* raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 45, 65};
    for(int i = 0; i < 11; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    relatorioNo(raiz, 50);
    relatorioNo(raiz, 30);
    relatorioNo(raiz, 10);
    relatorioNo(raiz, 70);

return 0; 
}