#include <stdio.h>
#define T 10

int cont=1;

void inicializarLista(int *lista){
	int i;

	for(i=0;i<T;i++){
		lista[i]=0;
		printf("%d ", lista[i]);
	}
}

int inserirLista(int *lista, int num, int pos){
	int aux=0;
	if(pos > T || pos < 0){
			printf("\nPosicao Invalida!!!");
			return 0;
	}

	if(cont>T){
		printf("\nLista Cheia!!!");
	}else if(lista[pos]==0){
		lista[pos] = num;
	}else{
		aux = lista[pos];
		lista[pos] = num;
		lista[pos+1] = aux;
	}
	cont++;
	return 1;
}

int removerLista(int *lista, int num){
	int i;
	for(i=0;i<T;i++){
		if(lista[i] == num){
			lista[i] = 0;

			printf("\nRemovido com sucesso!!!");

			cont--;

			return i;
		}
	}
	printf("\nValor não encontrado");
	return 0;
}

void imprimirLista(int *lista){
	int i;
	printf("\nPosicao: 0 1 2 3 4 5 6 7 8 9\n");
	printf("Vetor:   ");
	for (i=0;i<T;i++){
		printf("%d ", lista[i]);
	}
	printf("\n");
}

int main(){
	int lista[T], num, pos, rem, op=0;

	inicializarLista(lista);

	do{
		printf("\n");
		printf("\nLista");
		printf("\n1 - Inserir");
		printf("\n2 - Imprimir");
		printf("\n3 - Remover");
		printf("\n4 - Sair");
		printf("\nInforme uma opcao: ");
		scanf("%d", &op);
        system("cls");
		switch(op){
			case 1:
				printf("Informe o numero: ");
				scanf("%d", &num);
				printf("Informe a posicao (0 - 9): ");
				scanf("%d", &pos);
				inserirLista(lista, num, pos);
				break;
			case 2:
				imprimirLista(lista);
				break;
			case 3:
				printf("Informe o numero a ser removido: ");
				scanf("%d", &rem);
				removerLista(lista, rem);
				cont--;
				break;
			case 4:
				printf("Lista Fechada");
				break;
			default:
				printf("Opcao Invalida");
		}
	}while(op!=4);

	return 0;
}

