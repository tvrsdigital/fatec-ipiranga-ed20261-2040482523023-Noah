RA: 2040482523023 - Noah Tavares Bastos 

#include <stdio.h>

//Implementação de um mini sistema de estatísticas que opera sobre um vetor de numeros reais 
//manipulando-o atravé de ponteiros passados a funções; 
//implemente as funções: calcularMedia, encontrarExtremos, 
//... normalizar (divide elementos pelo valor maximo) e imprimirVetor 

//No main declare 
//float notas[] = {7.5,3.2,9.8,6.0,5.5,8.1}
//chame imprimirVetor depois normalizar
//exiba a média, o maior e o menor valor
//demonstre que a função normalizar alterou o vetor original

float calcularMedia (float *vet, int n){
    int i; 
    float soma = 0.0; 
    for(i=0; i<n; i++){
        soma += *vet;
        vet++; 
    }
    return soma/n; 
}

void encontrarExtremos (float *vet, int n, float *maior, float *menor){
    //começamos igualando tanto maior quanto menor ao 1 valor do vet
    //como estamos lidando com valores e não endereços; é preciso usar operador *
    *maior = *vet;
    *menor = *vet; 
    int i; 

    vet++; //fazer o *vet apontar para o segundo item do vetor
    for(i=1;i<n;i++){
        if (*vet > *maior){
            *maior = *vet; 
        }
        if (*vet < *menor){
            *menor = *vet; 
        }
    //isso faz com que o *vet passe para o próximo elemento do vetor
    vet++; 
    }

}

void normalizar(float *vet, int n){
    //começamos declarando variaveis locais pra maximo e minimo
    float maximo, minimo; 
    //chamamos a função encontrarExtremos, pra achar o valor maximo
    encontrarExtremos(vet, n, &maximo, &minimo);
    //agora maximo tem o maior valor do vetor; 
    int i; 
    //laço de repetição para percorrer o vetor 
    for (i=0;i<n;i++){
        //dividimos o valor do vetor pelo valor máximo;
        //como estamos lidando com valores, é preciso utilizar o operador * 
        *vet = *vet/maximo; 
        //garantimos que o vetor vai passar para o próximo índice
        vet++; 
    }
}

void imprimirVetor(float *vet, int n, const char *titulo){
    printf("%s\n", titulo); 
    int i; 
    for(i=0;i<n;i++){
        printf("%.2f\n", *vet);
        vet++; 
    }
}

int main(){
    float notas[]={7.5f,3.2f,9.8f,6.0f,5.5f,8.1f};
    float max, min; 

    printf("-----------Imprimindo o vetor-----------\n"); 
    imprimirVetor(notas,6,"-------NOTAS---------");
    printf("A média será: %.2f\n", calcularMedia(notas,6)); 
    encontrarExtremos(notas,6,&max,&min); 
    printf("A maior nota foi: %.1f\n", max);
    printf("A menor nota foi: %.1f\n", min); 
    printf("Agora realizamos a normalização\n"); 
    normalizar(notas,6);
    imprimirVetor(notas,6,"-------NOTAS APOS NORMALIZAR--------"); 

    return 0;
}

