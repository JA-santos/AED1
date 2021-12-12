#include<stdio.h>
#define TAM 5

int x, y;

void vetrepetido(int *vetor, int *quant){
    *quant = 1;
    for(x = 1; x < TAM; x++){
        if(vetor[x]==vetor[x-1]){
                *quant = *quant + 1;
        }else{
            printf("O numero %d aparece %d vezes!\n", vetor[x-1], *quant);
            *quant = 1;
        }
    }
    printf("O numero %d aparece %d vezes!\n", vetor[x-1], *quant);
}

int main(){
    int v[TAM], cont;
    printf("Informe 5 numeros:\n");
    for(int i = 0; i < TAM; i++){
        scanf("%d", &v[i]);
    }
    printf("\n");
    vetrepetido(v,&cont);
    return 0;
}

