RA: 2040482523023 - Noah Tavares Bastos 

#include <stdio.h>

int contador = 0; 

void hanoi(int n, char origem, char destino, char auxiliar, int nivel){
    int i; 
    if (n>0){
        //mover n-1 discos de origem para auxiliar 
        hanoi(n-1,origem,auxiliar,destino,nivel+1);
        //mover o disco atual de origem para destino
        for (i=0;i<nivel*2;i++){
            printf(" "); 
        }
        printf("Mova o disco %d de %c para %c\n",n, origem, destino); 
        contador++; 
        //mover os discos de auxiliar para destino 
        hanoi(n-1,auxiliar,destino,origem,nivel+1); 
    }
}

int main(){
    int discos;
    char A = 'A';
    char B = 'B';
    char C = 'C';

    printf("Diga a quantidade de discos: ");
    scanf("%d", &discos); 

    hanoi(discos,A,C,B,0); 
    printf("Foram feitos %d movimentos no total para resolver o problema!\n", contador); 


return 0; 
}