RA: 2040482523023 - Noah Tavares Bastos 

//Exercício 1 Parte A - Troca com ponteiros (Operadores * e &)
#include <stdio.h>

    //implementar troca de valores de a e b usando aritmética de ponteiros
    //sem variável temporária e sem XOR. 
    //no Main, declare 2 variáveis, exiba seus endereços com %p e seus valores
    //ANTES e DEPOIS da troca. 

void trocar (int *a, int *b){
    //Utilizamos o operador * nesses casos
    //pois estamos lidando com os valores que estão salvos nos endereços que a e b apontam;
    *a = *a + *b; 
    *b = *a - *b; 
    *a = *a - *b; 
}

int main(){
    int num1 = 10; 
    int num2 = 50; 

    //exibir os endereços das variaveis 
    //como queremos exibir os endereços de memória de variáveis é preciso usar o operador &
    //se estivessemos lidando com um ponteiro; não seria necessario o & pois o mesmo sozinho já aponta para um endereço
    printf("O endereço das variaveis 1 e 2, respectivamente, é: %p e %p", &num1, &num2); 

    //exibir os valores das variaveis 
    printf("\nO valor da variavel 1 é: %d", num1); 
    printf("\nO valor da variavel 2 é: %d", num2); 

    //chamada da função trocar; 
    trocar(&num1, &num2); 

    //exibir os valores das variáveis após a troca
    printf("\n------------- Após a troca -----------"); 
    printf("\nO valor da variavel 1 é: %d", num1); 
    printf("\nO valor da variavel 2 é: %d\n", num2); 


    return 0; 
}