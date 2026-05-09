#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    int altura;  
    struct No *esq;
    struct No *dir; 
} No;

int calcularAltura(struct No* n){
    if (n == NULL) return -1; 
    int alt_esq = calcularAltura(n->esq);
    int alt_dir = calcularAltura(n->dir); 
    return 1 + (alt_esq>alt_dir ? alt_esq : alt_dir); 

}

int obterFB(struct No* n){
    if (n == NULL) return 0; 
    else{
        return calcularAltura(n->esq) - calcularAltura(n->dir); 
    }
}

int main(){
    
    //criando os nós 
    No* n20 = (No*)malloc(sizeof(No)); 
    n20->valor = 20; 
    n20->esq = n20->dir = NULL; 

    No* n10 = (No*)malloc(sizeof(No));
    n10->valor = 10; 
    n10->esq = n10->dir = NULL; 

    n20->esq = n10; 

    No* n5 = (No*)malloc(sizeof(No));
    n5->valor = 5; 
    n5->esq = n5->dir = NULL; 

    n10->esq = n5; 

    No* n2 = (No*)malloc(sizeof(No));
    n2->valor = 2;
    n2->esq = n2->dir = NULL; 

    n5->esq = n2; 

    printf("O FB da árvore será: %d\n", obterFB(n20)); 
    
    free(n2);
    free(n5);
    free(n10);
    free(n20); 
    return 0; 
}
