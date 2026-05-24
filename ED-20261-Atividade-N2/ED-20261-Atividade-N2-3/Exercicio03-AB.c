RA: 2040482523023 - Noah Tavares Bastos 

#include <stdio.h>

int contador = 0; 

void hanoi(int n, char origem, char destino, char auxiliar){
    if (n>0){
        //mover n-1 discos de origem para auxiliar 
        hanoi(n-1,origem,auxiliar,destino);
        //mover o disco atual de origem para destino
        printf("Mova o disco %d de %c para %c\n",n, origem, destino); 
        contador++; 
        //mover os discos de auxiliar para destino 
        hanoi(n-1,auxiliar,destino,origem); 
    }
}

int main(){
    int discos;
    char A = 'A';
    char B = 'B';
    char C = 'C';

    printf("Diga a quantidade de discos: ");
    scanf("%d", &discos); 

    hanoi(discos,A,C,B); 
    printf("Foram feitos %d movimentos no total para resolver o problema!\n", contador); 

    //Preenchendo a tabela no código 
    // --- n ----- movimentos(contado) ------ (2^n)-1(esperado)
    //---- 1 ---------- 01 ----------------------- 01 -------
    //---- 2 ---------- 03 ----------------------- 03 -------
    //---- 3 ---------- 07 ----------------------- 07 -------
    //---- 4 ---------- 15 ----------------------- 15 -------
    //---- 5 ---------- 31 ----------------------- 31 -------
    //---- 6 ---------- 63 ----------------------- 63 -------

return 0; 
}