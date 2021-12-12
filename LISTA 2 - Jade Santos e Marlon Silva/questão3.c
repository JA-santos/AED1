#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 30000

void preencherVetor(int *v, int i){
    for(i = 0; i < tam; i++){
        v[i] = 1+rand()%30000; // gerar valores aleatórios
    }
}

void imprimeVetor(int *v, int i){
    for(i = 0; i < tam; i++){
        printf("%d ", v[i]); //imprime o vetor, após ter recebido a ordenação
    }
    printf("\n");
}

void selectionShort(int *v, int i, int j, int min, int aux){
    for(i = 0; i < tam-1; i++){ //percorre todo o vetor até tam-1 (a ultima posição não é necessário)
        min = i; // a variável min recebe a posição q esta passando
        for(j = i+1; j < tam; j++){ //percorre todo o vetor até i+1 (indo até o final)
            if(v[j] < v[min]) //testa se o valor que esta passando é menor do que min
                min = j; // min recebe a posição do menor valor
        }
        if(v[i] != v[min]){ //Se a posição for diferente da que está passando, ocorre a troca
            aux = v[i];
            v[i] = v[min];
            v[min] = aux;
        }
    }
}

void insertionShort(int *v, int i, int j, int aux){
    for(i = 0; i < tam; i++){ //pecorrer o vetor completamente
        aux = v[i]; //recebe a posição q o for esta pecorrendo
        j = i - 1; //assume o valor inicial (última posição)
        while(j >= 0 && v[j] > aux){ //se o valor for maior que aux, então move o valor para uma posição a frente da sua posição atual
            v[j+1] = v[j];  // enquanto vet[j] > aux empurra vet[j] para frente
            j--;
        }
        v[j+1] = aux; //insere o elemento na parte ordenada
    }
}

void intercala(int *v, int inicio, int meio, int fim){
    int n1, n2, i, j, k;
    n1 = meio - inicio + 1; //tamanho do subvetor esquerdo
    n2 = fim - meio; //tamanho do subvetor direito

    int v1[n1], v2[n2]; //criar subvetores temporários
    v1[n1] = tam;
    v2[n2] = tam;

    for(i = 0; i < n1; i++){ //copia os dados para o subvetor (esquerdo) temporário v1
        v1[i] = v[inicio + i];
    }
    for(j = 0; j < n2; j++){ //copia os dados para o subvetor (direito) temporário v2
        v2[j] = v[meio+1+j];
    }

    i = 0; //indice do subvetor v1 (esquerdo)
    j = 0; //indice do subvetor v2 (direito)

    //intercala os vetores
    for(k = inicio; k < fim+1; k++){
        if(v1[i] <= v2[j]){
            v[k] = v1[i];
            i++;
        }
        else{
            v[k] = v2[j];
            j++;
        }
    }
}

void mergesort(int *v, int inicio, int fim){
    if(inicio < fim){
       int meio = (inicio + fim)/2; //calcula o meio
        mergesort(v, inicio, meio); //ordena subvetor esquerdo
        mergesort(v, meio + 1, fim); //ordena o subvetor direito
        intercala(v, inicio, meio, fim); //junta os subvetores esquerdo e direito
    }
}

int partition(int *v, int inicio, int fim){
    int p, i, j, temp;

    p = v[fim];
    i = inicio - 1; //índice i faz a varredura da direita para esquerda

    for(j = inicio; j < fim; j++){
        if(v[j] <= p){ //se valor atual menor ou igual ao pivô, então
            i++; //incrementa 1, e faz a troca de dados entre as duas posições (v[i] e v[j]) no vetor
            temp = v[i]; //coloca o pivô na posição de ordenação
            v[i] = v[j];
            v[j] = temp;
        }
    }
    temp = v[i+1]; //agora da esquerda para a direita e faz a troca de entra as posições (v[i] e v[fim])
    v[i+1] = v[fim]; //por fim, coloca o pivô na posição de ordenação
    v[fim] = temp;
    return i+1; //retorna a posição do pivô
}

void quicksort(int *v, int inicio, int fim){
    if(inicio < fim){
        int meio = partition(v, inicio, fim);  //realiza a partição
        quicksort(v, inicio, meio-1); //ordena a partição esquerda
        quicksort(v, meio+1, fim); //ordena a partição direita
    }

}

int main(){
    int *v, i, j, k, min, aux;
    double tempD1, tempD2, tempD3, tempD4;
    v = (int*)malloc(sizeof(int)*tam);
    i = 1;

    while(i <= 3){
        printf("\nVetor aleatorio criado (vet%d): ", i);
        preencherVetor(v, i);
        imprimeVetor(v, i);

        clock_t a = clock();
        selectionShort(v, i, j, min, aux);
        clock_t b = clock();

        printf("Selecao: ");
        imprimeVetor(v, i);
        tempD1 = (double)(b-a)/CLOCKS_PER_SEC;
        printf("Tempo: %f segundos\n\n", tempD1);

        clock_t c = clock();
        insertionShort(v, i, j, aux);
        clock_t d = clock();

        printf("Insercao: ");
        imprimeVetor(v, i);
        tempD2 = (double)(d-c)/CLOCKS_PER_SEC;
        printf("Tempo: %f segundos\n\n", tempD2);

        clock_t e = clock();
        mergesort(v, 0, tam-1);
        clock_t f = clock();

        printf("Mergesort: ");
        imprimeVetor(v, i);
        tempD3 = (double)(f-e)/CLOCKS_PER_SEC;
        printf("Tempo: %f segundos\n\n", tempD3);

        clock_t g = clock();
        quicksort(v, 0, tam-1);
        clock_t h = clock();

        printf("Quicksort: ");
        imprimeVetor(v, i);
        tempD4 = (double)(h-g)/CLOCKS_PER_SEC;
        printf("Tempo: %f segundos\n\n", tempD4);

        i++;
    }
    free(v);
    return 0;
}
