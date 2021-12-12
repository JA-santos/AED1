#include<stdio.h>

void numeroPrimo(int num);

int main(){
    int n;
    printf("Informe um numero: ");
    scanf("%d", &n);
    numeroPrimo(n);
}

void numeroPrimo(int num){
    printf("\nNumeros primos: \n\n");
    for(int i = 1; i <= num; i++){
       int cont = 0;
        for(int j = 1; j <= i; j++)
            if(i % j == 0)
                cont++;
        if(cont == 2)
            printf("\t%d ", i);
    }
}
