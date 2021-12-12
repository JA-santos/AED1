#include <stdio.h>
#define TAM 5

int i;

void min_max(int *vetor, int *min, int *max){
    *min = *max = vetor[0];

    for(i = 0; i < TAM; i++){
        if(vetor[i] < *min)
            *min = vetor[i];
    }
    for(i = 0; i < TAM; i++){
        if(vetor[i] > *max)
            *max = vetor[i];
    }
}

int main(){
    int v[TAM], max, min;
    for(i = 0; i < TAM; i++){
        scanf("%d", &v[i]);
    }

    min_max(v, &max, &min);

    printf("max = %d\nmin = %d\n", max, min);

    return 0;
}
