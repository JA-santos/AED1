#include <stdio.h>

float Somatorio(int n){
	int i;
	float soma=0, x=1, y=1;

	for(i=0;i<n;i++){
		printf("%.f / %.f \t", x, y);

		soma = soma + (x/y);

		x++;
		y = y + 2;

	}
	return soma;
}

int main(){
	int n;
	float soma;

	printf("Informe um numero: ");
	scanf("%d", &n);

	soma = (Somatorio(n));

	printf("\nSoma: %f", soma);

	return 0;
}

