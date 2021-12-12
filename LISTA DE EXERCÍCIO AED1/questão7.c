#include <stdio.h>
#include <stdlib.h>
#define t 3

void ordenar( int *a, int  *b, int *c){

	if(*a<*b && *b<*c){
		printf("Ordenado: %d %d %d\n", *a, *b, *c);
	}else if(*a<*c && *c<*b){
		printf("Ordenado: %d %d %d\n", *a, *c, *b);
	}else if(*b<*a && *a<*c){
		printf("Ordenado: %d %d %d\n", *b, *a, *c);
	}else if(*b<*c && *c<*a){
		printf("Ordenado: %d %d %d\n", *b, *c, *a);
	}else if(*c<*a && *a<*b){
		printf("Ordenado: %d %d %d\n", *c, *a, *b);
	}else if(*c<*b && *b<*a){
		printf("Ordenado: %d %d %d\n", *c, *b, *a);
	}
}

int main(){

    int a, b, c;

    printf("Informe o valor de A: ");
    scanf("%d", &a);
    printf("Informe o valor de B: ");
    scanf("%d", &b);
    printf("Informe o valor de C: ");
    scanf("%d", &c);

	ordenar(&a, &b, &c);

    system("pause" );
    return 0;
}
