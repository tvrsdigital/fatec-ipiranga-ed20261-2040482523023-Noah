RA: 2040482523023 - Noah Tavares Bastos 

//Exercício 1B - aritmética de ponteiros em um vetor 
#include <stdio.h> 

//Dado o vetor v[] = {10,20,30,40,50}
//usando apenas aritmética de ponteiros (proibido utilizar o operador [])
//percorra o vetor, e imprima cada elemento e seu endereço
//calcule e imprima a soma dos elementos
//inverta o vetor in-place (sem criar outro vetor), usando dois ponteiros
//sendo um iniciando no início e outro no final. 

int main(){
    int v[] = {10,20,30,40,50}; 
    int *p = v; 
    int i; 

    //1. Percorrer o vetor e imprimir seus elementos e endereços 
    for (i=0; i<5; i++){

        //como p é um ponteiro p+i já está apontando pra um endereço de memória
        //por isso não há necessidade de usar o operador &
        //ele seria utilizado pra mostrar o endereço de v[i]; ficaria &v[i] dentro do printf
        printf("O item %d do vetor tem endereço: %p", i, p+i);

        //como p é um ponteiro, então para mostrar o valor que ele aponta
        //aí precisamos utilizar o operador * dentro do printf.
        printf("\nE valor %d\n", *(p+i));  
    }

    //2. Calcular e imprimir a soma dos elementos do vetor 
    int soma = 0; 
    for (i=0; i<5; i++){
        //como estamos fazendo a soma com ponteiros
        //é preciso utilizar o operador * 
        //para lidar com o valor o qual o ponteiro aponta e não seu endereço. 
        soma = soma + *(p+i);
    }
    printf("A soma dos elementos do vetor será: %d\n", soma); 

    
    //3. inveter o vetor in-place usando 2 ponteiros
    int *inicio = v; //ponteiro que aponta para o início do vetor 
    int *fim = v+4; //ponteiro que aponta para o final do vetor
    
    while (inicio < fim){
        //inverter os valores no vetor; 
        //Utilizamos o operador * pois estamos lidando com os valores salvos nos endereços apontados pelos ponteiros
        *inicio = *inicio + *fim; 
        *fim = *inicio - *fim; 
        *inicio = *inicio - *fim; 

        //atualizar os ponteiros para que eles passem pros próximos indices
        //como inicio e fim já são ponteiros
        //e queremos que eles pulem pro próximo endereço de memória (pra frente ou pra trás)
        //não é preciso utilizar o operador &;
        inicio++; 
        fim--; 
    }
    //exibir o vetor invertido 
    //Para objetivo de estudo, iremos mostrar que os endereços não se alteram
    //porém os valores sim!

    printf("-----------Após a inversão dos valores no vetor ------------\n"); 
     for (i=0; i<5; i++){
        //como p é um ponteiro p+i já está apontando pra um endereço de memória
        //por isso não há necessidade de usar o operador &
        //ele seria utilizado pra mostrar o endereço de v[i]; ficaria &v[i] dentro do printf
        printf("O item %d do vetor tem endereço: %p", i, p+i);

        //como p é um ponteiro, então para mostrar o valor que ele aponta
        //aí precisamos utilizar o operador * dentro do printf.
        printf("\nE valor %d\n", *(p+i));  
    }



return 0; 
}