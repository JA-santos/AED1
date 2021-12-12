/*Crie funções para calcular a média dos valores contidos na sequência de números entre 1 à 10;**/

#include <stdio.h>

float mediaSequencia(int *vetor, int n, int tam);

int main(){
    int v[10]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Media: %.1f\n", mediaSequencia(v, 10, 10));
    return 0;
}

float mediaSequencia(int *vetor, int n, int tam){
    if(n <= 0)
        return 0;
    else
        return vetor[n-1]/(float) tam + mediaSequencia(vetor, n-1, tam);
}

