/*3)Desenvolva um programa em C que gere uma tabuada de multiplica��o de qualquer n�mero
inteiro entre 1 a 10. O usu�rio deve informar de qual numero ele deseja ver a tabuada. Obs.: Utilize a estrutura de repeti��o for.**/

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
