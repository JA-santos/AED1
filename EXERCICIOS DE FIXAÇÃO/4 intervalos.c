/*4)Faça um programa em C que leia uma quantidade indeterminada de números inteiros positivos e conte quantos deles estão nos
seguintes intervalos: [1-25], [26-50], [51-75] e [76-100]. A entrada de dados deverá terminar quando for lido o valor 0.
Obs.: Utilize a estrutura de repetição while.**/

#include <stdio.h>

int main(){
    int i = 1, qtd1 = 0, qtd2 = 0, qtd3 = 0, qtd4 = 0;

    while(i != 0){
        printf("\nInforme um numero: ");
        scanf("%d", &i);

        if(i >= 1 && i <= 25){
            qtd1++;
        }else if (i >= 26 && i <= 50){
            qtd2++;
        }else if (i >= 51 && i <= 75){
            qtd3++;
        }else if (i >= 76 && i <= 100){
            qtd4++;
        }
    }
    printf("\nQtd. de numero no intervalo [1-25]: %d", qtd1);
    printf("\nQtd. de numero no intervalo [26-50]: %d", qtd2);
    printf("\nQtd. de numero no intervalo [51-75]: %d", qtd3);
    printf("\nQtd. de numero no intervalo [76-100]: %d\n", qtd4);
    return 0;
}
