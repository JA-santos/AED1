/*6)Calcular a quantidade de dinheiro gasta por um alcolatra. Dados:
● O número de anos que ele bebeu;
● A quantidade de latinhas bebidas por dia e;
● O preço de uma latinha.**/

#include <stdio.h>

int main(){
    int tempoBebida = 0, qtdLatinha = 0;
    float precoLatinha, gastoDia, gastoTotal;

    printf("Ha quantos anos voce bebe?: ");
    scanf("%d", &tempoBebida);
    printf("Quantas latinhas bebe por dia?: ");
    scanf("%d", &qtdLatinha);
    printf("Valor da latinha: ");
    scanf("%f", &precoLatinha);

    gastoDia = qtdLatinha*precoLatinha;
    gastoTotal = (tempoBebida*365)*gastoDia;

    printf("\nTotal de %.2f reais gastos com bebida\n", gastoTotal);

    return 0;
}
