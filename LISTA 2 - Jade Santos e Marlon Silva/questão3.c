#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define tam 30000

void preencherVetor(int *v, int i){
    for(i = 0; i < tam; i++){
        v[i] = 1+rand()%30000; // gerar valores aleat�rios
    }
}

void imprimeVetor(int *v, int i){
    for(i = 0; i < tam; i++){
        printf("%d ", v[i]); //imprime o vetor, ap�s ter recebido a ordena��o
    }
    printf("\n");
}

void selectionShort(int *v, int i, int j, int min, int aux){
    for(i = 0; i < tam-1; i++){ //percorre todo o vetor at� tam-1 (a ultima posi��o n�o � necess�rio)
        min = i; // a vari�vel min recebe a posi��o q esta passando
        for(j = i+1; j < tam; j++){ //percorre todo o vetor at� i+1 (indo at� o final)
            if(v[j] < v[min]) //testa se o valor que esta passando � menor do que min
                min = j; // min recebe a posi��o do menor valor
        }
        if(v[i] != v[min]){ //Se a posi��o for diferente da que est� passando, ocorre a troca
            aux = v[i];
            v[i] = v[min];
            v[min] = aux;
        }
    }
}

void insertionShort(int *v, int i, int j, int aux){
    for(i = 0; i < tam; i++){ //pecorrer o vetor completamente
        aux = v[i]; //recebe a posi��o q o for esta pecorrendo
        j = i - 1; //assume o valor inicial (�ltima posi��o)
        while(j >= 0 && v[j] > aux){ //se o valor for maior que aux, ent�o move o valor para uma posi��o a frente da sua posi��o atual
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

    int v1[n1], v2[n2]; //criar subvetores tempor�rios
    v1[n1] = tam;
    v2[n2] = tam;

    for(i = 0; i < n1; i++){ //copia os dados para o subvetor (esquerdo) tempor�rio v1
        v1[i] = v[inicio + i];
    }
    for(j = 0; j < n2; j++){ //copia os dados para o subvetor (direito) tempor�rio v2
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
    i = inicio - 1; //�ndice i faz a varredura da direita para esquerda

    for(j = inicio; j < fim; j++){
        if(v[j] <= p){ //se valor atual menor ou igual ao piv�, ent�o
            i++; //incrementa 1, e faz a troca de dados entre as duas posi��es (v[i] e v[j]) no vetor
            temp = v[i]; //coloca o piv� na posi��o de ordena��o
            v[i] = v[j];
            v[j] = temp;
        }
    }
    temp = v[i+1]; //agora da esquerda para a direita e faz a troca de entra as posi��es (v[i] e v[fim])
    v[i+1] = v[fim]; //por fim, coloca o piv� na posi��o de ordena��o
    v[fim] = temp;
    return i+1; //retorna a posi��o do piv�
}

void quicksort(int *v, int inicio, int fim){
    if(inicio < fim){
        int meio = partition(v, inicio, fim);  //realiza a parti��o
        quicksort(v, inicio, meio-1); //ordena a parti��o esquerda
        quicksort(v, meio+1, fim); //ordena a parti��o direita
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
