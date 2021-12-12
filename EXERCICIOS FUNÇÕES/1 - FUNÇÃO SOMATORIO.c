#include<stdio.h>

float somatorio(int n);

int main(){
    int n;
    printf("Informe um valor: ");
    scanf("%d", &n);

    printf ("Resultado: %f", somatorio(n));
    return 0;
}

float somatorio(int n){
    int j = -1, i;
    float s=0;

    for (i = 1; i <= n; i++)
        j = j + 2;
        s = s + (j/i);
    return s;
}
