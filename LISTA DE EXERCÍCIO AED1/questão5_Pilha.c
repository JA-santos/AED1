#include <stdio.h>
#include <stdlib.h>
#define T 10

struct Pilha {

	int topo; // posicao elemento topo
	int capa;
	float *pElem;

};

void criarpilha( struct Pilha *p ){//criar a pilha

   p->topo = -1;
   p->capa = T;
   p->pElem = (float*) malloc (T * sizeof(float));

}
int estavazia ( struct Pilha *p ){//verificar se está vazia

   if( p-> topo == -1 ){
   		return 1;   // true
   }else{
   		return 0;   // false
   }

}

int estacheia ( struct Pilha *p ){//verificar se está cheia

	if (p->topo == p->capa - 1){
		return 1;
	}else{
		return 0;
	}
}

void empilhar ( struct Pilha *p, int v){//empilhar valores

	p->topo++;
	p->pElem [p->topo] = v;

}

float desempilhar ( struct Pilha *p ){//desenpilhar valores

   float aux = p->pElem [p->topo];
   p->topo--;
   return aux;

}

float retornatopo ( struct Pilha *p ){//retornar o topo

   return p->pElem [p->topo];

}

int main(){
	struct Pilha minhapilha;
	int op, valor;

	//Criar pilha
	criarpilha (&minhapilha);

	do{
		printf("\n1- empilhar (push)\n");
		printf("2- desempilhar (POP)\n");
		printf("3- Mostrar o topo \n");
		printf("4- sair\n");
		printf("\nopcao? ");
		scanf("%d", &op);

		switch (op){
			case 1: //push
				if( estacheia( &minhapilha ) == 1 ){
					printf("\nPILHA CHEIA! \n");
				}else{
					printf("\nVALOR? ");
					scanf("%d", &valor);
					empilhar (&minhapilha, valor);
				}
				break;
			case 2: //pop
				if ( estavazia(&minhapilha) == 1 ){
					printf( "\nPILHA VAZIA! \n" );
				}else{
					valor = desempilhar (&minhapilha);
					printf ( "\n%.1f DESEMPILHADO!\n", valor );
				}
				break;
			case 3: // mostrar o topo
				if ( estavazia (&minhapilha) == 1 ){
					printf( "\nPILHA VAZIA!\n" );
				}else{
					valor = retornatopo (&minhapilha);
					printf ( "\nTOPO: %.1f\n", valor );
				}
				break;
			case 4:
				printf("Pilha Encerrada!!!");
				break;
			default:
				printf( "\nOPCAO INVALIDA! \n" );
		}
	}while(op != 4);

	return 0;
}
