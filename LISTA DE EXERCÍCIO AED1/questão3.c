#include <stdio.h>

int fbc (int i, int n, int an, int at){
	int p;

	if(i <= n){
		p = an + at;

		printf("%d ", p);

		i++;
		an = at;
		at = p;
		fbc(i, n, an, at);
	}else{
		return 0;
	}
}

int soma (int i, int an, int at, int s, int n){
	int p;

	if(i <= n){
		p = an + at;
		s = s + p;
		an = at;
		at = p;
		i++;

		soma(i, an, at, s, n);
	}else{
		printf("\nSoma: %d", s+1);
	}

}

int main(){

	int i=2, n, an=0, at=1, s=0;

	printf("Informe o valor: ");
	scanf("%d", &n);

	fbc(i, n, an, at);

	soma (i, an, at, s, n);

	return 0;
}

