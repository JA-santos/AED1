#include<stdio.h>

void troca();

int main(){
    troca();
    return 0;
}

void troca(){
    int a, b, c;

    printf("Informe um numero: ");
    scanf("%d", &a);
    printf("Informe um numero: ");
    scanf("%d", &b);
    printf("Informe um numero: ");
    scanf("%d", &c);

    if (c > a)
        if (a > b)
            printf("\nA ordem crescente: %d %d %d\n", b, a, c);
        else if (b < c)
            printf("\nA ordem crescente: %d %d %d\n", a, b, c);
    if (a > b)
        if (b > c)
            printf("\nA ordem crescente: %d %d %d\n", c, b, a);
        else if (c < a)
            printf("\nA ordem crescente: %d %d %d\n", b, c, a);
    if (a < b)
        if (c < a)
            printf("\nA ordem crescente: %d %d %d\n", c, a, b);
        else if (c < b)
            printf("\nA ordem crescente: %d %d %d\n", a, c, b);
}
