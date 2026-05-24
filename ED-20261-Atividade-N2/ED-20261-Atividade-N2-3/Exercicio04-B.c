RA: 2040482523023 - Noah Tavares Bastos 

//Potenciação rápida
//Calcula base^exp de forma recursiva eficiente.
//Complexidade: 0 (log exp); 
#include <stdio.h>

long long potenciaRapida(long long base,int exp, int *chamadas){
    (*chamadas)++; 
    //caso base 
    if (exp == 0){
        return 1; 
    }
    if (exp % 2 == 0){
    //se exp for par 
    long long metade = potenciaRapida(base,exp/2,chamadas); 
    return metade * metade; 
    } else{ //se exp for impar 
        long long resultado = potenciaRapida(base,exp-1,chamadas);
        return base * resultado; 
    
    }
}

long long potenciaIngenua (long long base,int exp, int *chamadas){
    (*chamadas)++;
    if (exp == 0){
        return 1; 
    } else{
        return base * potenciaIngenua(base,exp-1,chamadas); 
    }

}

int main(){
    int cont; 

    //teste 1: 2^10 
    printf("------- Fazendo a Potenciação Rápida -------\n"); 
    cont = 0; 
    long long resultado = potenciaRapida(2,10,&cont);
    printf("O resultado de 2^10 é: %lld\n", resultado); 
    printf("E foram preciso %d chamadas\n", cont); 
    printf("------- Fazendo a Potenciação Ingenua -------\n");
    cont = 0; 
    long long resultado2 = potenciaIngenua(2,10,&cont); 
    printf("O resultado de 2^10 é: %lld\n", resultado2); 
    printf("E foram preciso %d chamadas\n", cont);


    //teste 1: 3^7 
    printf("------- Fazendo a Potenciação Rápida -------\n"); 
    cont = 0; 
    resultado = potenciaRapida(3,7,&cont);
    printf("O resultado de 3^7 é: %lld\n", resultado); 
    printf("E foram preciso %d chamadas\n", cont); 
    printf("------- Fazendo a Potenciação Ingenua -------\n");
    cont = 0; 
    resultado2 = potenciaIngenua(3,7,&cont); 
    printf("O resultado de 3^7 é: %lld\n", resultado2); 
    printf("E foram preciso %d chamadas\n", cont);


    //teste 1: 5^0 
    printf("------- Fazendo a Potenciação Rápida -------\n"); 
    cont = 0; 
    resultado = potenciaRapida(5,0,&cont);
    printf("O resultado de 5^0 é: %lld\n", resultado); 
    printf("E foram preciso %d chamadas\n", cont); 
    printf("------- Fazendo a Potenciação Ingenua -------\n");
    cont = 0; 
    resultado2 = potenciaIngenua(5,0,&cont); 
    printf("O resultado de 5^0 é: %lld\n", resultado2); 
    printf("E foram preciso %d chamadas\n", cont);


    //teste 1: 7^12 
    printf("------- Fazendo a Potenciação Rápida -------\n"); 
    cont = 0; 
    resultado = potenciaRapida(7,12,&cont);
    printf("O resultado de 7^12 é: %lld\n", resultado); 
    printf("E foram preciso %d chamadas\n", cont); 
    printf("------- Fazendo a Potenciação Ingenua -------\n");
    cont = 0; 
    resultado2 = potenciaIngenua(7,12,&cont); 
    printf("O resultado de 7^12 é: %lld\n", resultado2); 
    printf("E foram preciso %d chamadas\n", cont);

    //Como pode-se ver, a função Ingenua precisa de muito mais chamadas para resolver o mesmo problema
    //isto ocorre pois na Ingenua, sempre terá chamadas proporcionais ao tamanho do expoente.
    //Já a função rápida, divide por 2 o expoente em casos pares, isto é,a quantidade de chamadas pra resolver cai de forma logaritmica! 
    //Nos casos impares, apesar de não dividir pela metade, ainda assim a função rápida precisa de menos chamadas
    //como mostrado no caso teste 3^7

    return 0; 
}