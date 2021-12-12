/*3)Desenvolva um programa em C que gere uma tabuada de multiplicação de qualquer número
inteiro entre 1 a 10. O usuário deve informar de qual numero ele deseja ver a tabuada. Obs.: Utilize a estrutura de repetição for.**/

#include <stdio.h>

int main(){
    int n, r;

    printf("Insira um numero: ");
    scanf("%d", &n);

    for(int i = 1; i <= 10; i++){
        r = n * i;
        printf("\n%d x %d = %d\n", n, i, r);
    }
    return 0;
}
