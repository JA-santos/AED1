/*Fa�a um programa em C em que dados os n�meros n1 e n2, como par�metros
de entrada de uma fun��o a mesma deve encontrar os m�ltiplos de 3 e 5 que se encontram nesse
intervalo, recursivamente**/

#include<stdio.h>

int multiplos_tres_cinco(int a, int b){
    a++;
    if(a <= b){
        if(a % 3 && a % 5){
            return multiplos_tres_cinco(a, b);
        }else{
            printf("\t%d", a);
            return multiplos_tres_cinco(a, b);
        }
    }
}

int main(){
    int n1, n2;

    printf("Insira os numeros do intervalo:\n");
    scanf("%d", &n1);
    scanf("%d", &n2);

    printf("\nMultiplos de 3 e 5 do intervalo %d-%d:\n\n", n1, n2);

    if(n1 % 3 == 0 || n1 % 5 == 0){ //imprime o primeiro termo se for multiplo de 3 ou 5
        printf("\t%d ", n1);
        multiplos_tres_cinco(n1, n2);
    }else
        multiplos_tres_cinco(n1, n2);
    printf("\n");
}
