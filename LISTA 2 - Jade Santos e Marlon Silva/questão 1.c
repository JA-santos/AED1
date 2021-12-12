#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 1000000

int preencherVetor(int *v, int i){
    for(i = 0; i < TAM; i++){
        v[i] = 1+rand()%1000; //gera valores aleatórios
        printf("%d\t", v[i]);
    }
}

int pesquisaSequencial(int *v, int i, int n){
    for(i = 0; i < TAM; i++){
        if(v[i]==n){
            return v[i];
        }
    }
    return -1;
}

int ordenar_vetor(int *v, int i, int j, int m, int aux){
    for(i = 0; i < TAM -1 ; i++){
        m = i;
        for(j = (i+1); j < TAM; j++){
            if(v[j] < v[m]){
                m = j;
            }
        }
        if(m != i){
            aux = v[i];
            v[i] = v[m];
            v[m] = aux;
        }
    }
}

int pesquisaBinaria(int *v, int i, int n){
    int f = TAM-1;
    while(i <= f){ //condição de parada
       int m = (i+f)/2; //calcula o meio do vetor
        if(v[m]==n){ //valor encontrado
            return v[m];
        }
        else if(v[m] < n){ //valor se encontra no vetor à direita
            i = m + 1;
        }else{ /*valor encontrado no vetor à esquerda v[m]>n*/
            f = m - 1;
        }
    }
    return -1;
}

int main(){
    int *v, n, i, s, b, j, m, aux;
    v = (int*)malloc(sizeof(int)*TAM);
    double tempDuracao, tempDuracao1;

    i = 1;
    preencherVetor(v, i);

    while(i <= 3){
        printf("\nVetor criado (vet%d)", i);
        printf("\nValor a ser pesquisado: ");
        scanf("%d", &n);

        clock_t tic = clock();
        s = pesquisaSequencial(v, i, n);
        clock_t toc = clock();

        ordenar_vetor(v, i, j, m, aux);
        clock_t inicio = clock();
        b = pesquisaBinaria(v, i, n);
        clock_t fim = clock();

        tempDuracao = (double)(toc-tic)/CLOCKS_PER_SEC; //tempo de duração da pesquisaSequencial
        tempDuracao1 = (double)(fim-inicio)/CLOCKS_PER_SEC; //tempo de duração da pesquisaBinaria

        if(s == -1 && b == -1){
            printf("Valor nao encontrado!\n");
        } else{
            printf("Pesquisa Sequencial: (vet%d, %d)\t\t\tPesquisa Binaria: (vet%d, %d)", i, s, i, b);
            printf("\nTempo: %f segundos\t\t\t\tTempo: %f segundos\n", tempDuracao, tempDuracao1);
        }
        i++;
    }
    free(v);
    return 0;
}
