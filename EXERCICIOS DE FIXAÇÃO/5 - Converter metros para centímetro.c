/*5)Faça um programa em C que converta de metros para centímetros. A quantidade de metros deve ser fornecida pelo usuário.**/

#include <stdio.h>

int main(){
    int metro, cm;

    printf("\tCONVERTER METROS EM CENTIMETROS\n\nInforme o valor do metro: ");
    scanf("%d", &metro);

    cm = metro * 100;

    printf("\n\t%d metro equivale a %d cm\n", metro, cm);
    return 0;
}
