/*7)Fa�a um programa que leia 10 n�meros e imprima a m�dia dos valores.**/

#include <stdio.h>

int main(){
    float media;
    int n, i, s=0;

    for(i = 0; i < 10; i++){
        printf("Informe o %d numero: ", i+1);
        scanf("%d", &n);
        s += n;
    }
    media = s/10;
    printf("\na media e: %.2f\n", media);
    return 0;
}
