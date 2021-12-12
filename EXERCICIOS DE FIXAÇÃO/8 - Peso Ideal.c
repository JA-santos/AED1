/*7)Tendo como dados de entrada a altura e o sexo de uma pessoa, construa um programa em C que calcule seu peso ideal, utilizando as seguintes fórmulas:
● Para homens: (72.7*h) – 58
● Para mulheres: (62.1*h) - 44.7 (h = altura)
Peça o peso da pessoa e informe se ela está dentro, acima ou abaixo do peso.**/

#include <stdio.h>

int main()
{
    float a, p_ideal, p;
    char s;

    printf("Sexo (M ou F): ");
    scanf("%s", &s);
    printf("Altura: ");
    scanf("%f", &a);

    if(s == 'F' || s == 'f'){
        p_ideal = (62.1 * a) - 44.7;
    } else{
        if(s == 'M' || s == 'm'){
            p_ideal = (72.7 * a) - 58;
        }
    }

    printf("\nSeu peso ideal e: %.3f\n", p_ideal);
    printf("\nPeso: ");
    scanf("%f", &p);

    if (p == p_ideal){
        printf("\nDentro do peso ideal\n");
    } else{
        if (p < p_ideal){
            printf("\nAbaixo do peso ideal\n");
        } else{
            printf("\nAcima do peso\n");
        }
    }
    return 0;
}
