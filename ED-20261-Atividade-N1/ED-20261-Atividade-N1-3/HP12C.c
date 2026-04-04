/*----------------------------------------------------------------------------------*/
/*                                FATEC-Ipiranga                                    */        
/*                            ADS - Estrutura de Dados                              */
/*                             Id da Atividade: N1-3                                */
/*                            Objetivo: Simular calculadora HP12C                   */
/*                                                                                  */
/*                                  Autor: Noah Tavares Bastos                      */
/*                                                                   Data:04/04/2026*/
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 100

typedef struct{
    float X, Y, Z, T;
} HP12C; 

//inicializa os registradores com zero. 
void Inicializar(HP12C *calc){
    calc->X = calc->Y = calc->Z = calc->T = 0.0;
}

//exibe o estado atual da pilha 
void Exibir_Pilha(HP12C calc){
    printf("----- PILHA HP12C -----");
    printf("\nT: %f", calc.T);
    printf("\nZ: %f", calc.Z);
    printf("\nY: %f", calc.Y);
    printf("\nX: %f", calc.X);
    printf("\n---------------------\n");
}

void inserir_numero(HP12C *calc, float num){
    calc->T = calc->Z;
    calc->Z = calc->Y;
    calc->Y = calc->X;
    calc->X = num; 
}

void operacao(HP12C *calc, char op){
    float resultado; 
    switch(op){
        case '+': resultado = calc->Y + calc->X; break; 
        case '-': resultado = calc->Y - calc->X; break; 
        case '*': resultado = calc->Y * calc->X; break; 
        case '/':
            if(calc->X !=0) resultado = calc->Y / calc->X; 
            else{ printf("Erro: divisão por zero!\n"); return; }
        break; 
    }
    calc->X = resultado; //o resultado vai para o display (X)
    calc->Y = calc->Z; //valor de Z vai para Y
    calc->Z = calc->T; //valor de T vai para Z
}

int main(){
    HP12C calc; 
    Inicializar(&calc); 
    char rpn[MAX];

    printf("Digite a expressão em RPN: ");
    fgets(rpn, MAX, stdin); 

    char *ptr = strtok(rpn, " \n");

    while (ptr != NULL){
        if ((ptr[0] == '+' || ptr[0] == '-' || ptr[0] == '*' || ptr[0] == '/') && strlen(ptr) == 1){
            operacao(&calc, ptr[0]); 
        } else if (ptr[0] >= '0' && ptr[0] <= '9' || (ptr[0] == '-' && ptr[1] >= '0' && ptr[1] <= '9')) {
            float num = atof(ptr); //converte para float 
            inserir_numero(&calc, num);
        }
        Exibir_Pilha(calc); 
        ptr=strtok(NULL, " \n"); 
    }
    printf("\n O resultado da expressão algébrica é: %0.1f\n", calc.X); 

    return 0;
}