/*1) Crie um programa em C que leia o peso de uma pessoa, só a parte inteira, calcule e imprima:
a) O peso da pessoa em gramas.
b) O algoritmo também deve abordar a possibilidade de a pessoa engordar X %, apresentando o novo peso em gramas. O usuário deve informar o valor de X.**/

#include <stdio.h>

int pesoGrama(int p);
int ganhoPeso(int y, int p);

int main(){
   int peso, x;

   printf("Informe seu peso (apenas a parte inteira): ");
   scanf("%d", &peso);
   printf("Informe a porcetagem de ganho de peso: ");
   scanf("%d", &x);

   system("cls");

   printf("Peso em gramas: %d\n", pesoGrama(peso));
   printf("Novo peso: %d\n", ganhoPeso(pesoGrama(peso), x));

   return 0;
}

int pesoGrama(int p){
    int pesoG;
        pesoG = p * 1000;
    return pesoG;
}

int ganhoPeso(int p, int y){
    int novoP;
        novoP = p + ((p * y)/100);
    return novoP;
}
