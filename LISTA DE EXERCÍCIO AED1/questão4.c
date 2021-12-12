#include <stdio.h>

int i = 3, v, soma=0;

int fetuccine(int a1, int a2);

int main(){
    int n1, n2, soma = 0;
    printf("Informe dois numeros: \n");
    scanf("%d", &n1);
    scanf("%d", &n2);
    system("cls");
    printf("Termo 1: %d\nTermo 2: %d", n1, n2);
    printf("\n\nSoma: %d\n", fetuccine(n1, n2) + n1 + n2);
    return 0;
}

int fetuccine(int a1, int a2){
    if(i <= 10){
        if(i%2 == 0)
            v = a2 - a1;
        else
            v = a2 + a1;
        a1 = a2;
        a2 = v;
        soma += v;
        i++;
        printf("\nTermo %d: %d", i, v);
        fetuccine(a1, a2);
    }
    else{
        return soma;
    }
}
