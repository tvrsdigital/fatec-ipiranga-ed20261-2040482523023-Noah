RA: 2040482523023 - Noah Tavares Bastos 

//Busca binária recursiva
//Implemente retorna o indice do elemento se encontrado
//ou -1 caso contrário
//O vetor deve estar ordenado na ordem crescente; 

#include <stdio.h> 

int buscaBinaria(int *vet,int inicio,int fim,int alvo, int *chamadas){  
    (*chamadas)++;
    //inicio do código de busca; 
    if (inicio > fim){
        return -1; 
    }
    int meio = inicio + (fim-inicio)/2; 
    if(vet[meio] == alvo){
        return meio; 
    }
    if (alvo < vet[meio]){
        return buscaBinaria(vet,inicio,meio-1,alvo,chamadas);
    } else{
        return buscaBinaria(vet,meio+1,fim,alvo,chamadas); 
        
    }

}

int main(){
    int dados[]={2,5,8,12,16,23,38,45,72,91};
    int cont; 
    
    //Teste 1: elemento 45 (presente)
    cont = 0; 
    int indice = buscaBinaria(dados,0,9,45,&cont); 
    printf("O alvo 45 foi achado no indice %d\n", indice); 
    printf("Foram feitas %d chamadas recursivas pra achar o alvo!\n",cont); 

    //Teste 2: elemento 54 (ausente)
    cont = 0; 
    indice = buscaBinaria(dados,0,9,54,&cont); 
    printf("O alvo 54 foi achado no indice %d\n", indice); 
    printf("Foram feitas %d chamadas recursivas pra achar o alvo!\n",cont); 

    //Teste 3: elemento 2 (primeiro elemento)
    cont = 0; 
    indice = buscaBinaria(dados,0,9,2,&cont); 
    printf("O alvo 2 foi achado no indice %d\n", indice); 
    printf("Foram feitas %d chamadas recursivas pra achar o alvo!\n",cont); 

    return 0; 
}

