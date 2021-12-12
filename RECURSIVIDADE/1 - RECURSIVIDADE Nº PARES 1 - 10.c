/*Criar uma função que imprima somente os números pares em uma sequência de números de 1 à 10;**/

#include <stdio.h>

int ImprimirPares(int a, int b);

int main(){
    int a = 1, b = 10, numeroPares;
    printf("Numeros pares entre %d-%d:\n", a, b);
    ImprimirPares(a, b);
    return 0;
}

int ImprimirPares(int a, int b){
    a++;
    if(a<=b)
        if(a % 2)
            return ImprimirPares(a, b);
        else
            printf("%d ", a);
            return ImprimirPares(a, b);
}
