#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nO{
    int id; //armazena dados da fila
    struct NO *prox; //ponteiro para o próximo no
}NO;

typedef struct fila{
    NO *inicio; //ponteiro de inicio para o no da fila
    NO *fim; //ponteiro de fim para no
}Fila;

void inicializaFila(Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
}

bool verificaFilaVazia(Fila *f){ //fila vazia ou não
   return (f->inicio == 0);
}

void enfileirar(int n, Fila *f){
    NO *p = (NO*)malloc(sizeof(NO));
    if(p == NULL){
        printf("Erro alocacao.\n");
    }else{
        p->id = n;
        p->prox = NULL;
        if(f->inicio == NULL){
            f->inicio = p;
        } else{
            f->fim->prox = p;
        }
        f->fim = p;
    }
}

void imprimeFila(Fila *f){
    printf("---Fila atual---\n");
    if(verificaFilaVazia(f)){ //se o retorno da função for 0, fila vazia
        printf("Vazia!\n");
    }

    NO *p = f->inicio;
    if(p != NULL){
        while(p != NULL){
            printf("%d ", p->id);
            p = p->prox;
        }
    }
    printf("\n");
}

void desenfileira(Fila *f){
    if(verificaFilaVazia(f)){ //se o retorno da função for 0, fila vazia
        printf("\tFila Vazia!\n\n");
    }
    NO *p = f->inicio;
    if(p != NULL){
        f->inicio = p->prox;
        p->prox = NULL;
        p = p->id;
        free(p);
        if(f->inicio == NULL){
            f->fim = NULL;
        }
    }
}

Fila* removerQP(Fila *f, Fila *f2, int d){
    NO *aux;
    aux = (NO*)malloc(sizeof(NO));
    aux = f->inicio; // vai percorrer a pilha
    int s;  // salvar o elemento que for retirado da pilha
    if(aux != NULL){
    	while(f->inicio != NULL){
    		s = desenfileira(f);
    		if(d == s){

			}else{
				enfileirar(f2, s);
			}
		}
		while(f2->inicio != NULL){
			desenfileira(f2);
			enfileirar(f, s);
		}
	}
}

void pesquisar(Fila *f, int d){
    if(verificaFilaVazia(f)){ //se o retorno da função for 0, pilha vazia
        printf("Vazia!\n");
    }

    NO *aux, *no = NULL;
    aux = f->inicio;
    while(aux && aux->id != d)
        aux = aux->prox;
    if(aux)
        no = aux;

    if(no){
        printf("Valor %d encontrado!!\n\n", d);
    } else{
        printf("Valor %d nao encontrado!!\n\n", d);
    }
}

int main(){
    Fila *f;
    Fila *f2;
    int op, n;
    inicializaFila(&f);

    do{
        imprimeFila(&f);
        printf("\t\nFila dinamica encadeada\n1 - Inserir\n2 - Remover\n3 - Pesquisar\n4 - Sair\n\nInforme uma opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1: printf("Inserir um valor: ");
                    scanf("%d", &n);
                    enfileirar(n, &f);
                    system("cls");
                    break;

            case 2: printf("Informe o valor a ser removido: ");
                    scanf("%d", &n);
                    removerQP(&f, &f2, n);
                    break;

            case 3: printf("Informe o valor a ser pesquisado: ");
                    scanf("%d", &n);
                    pesquisar(&f, n);
                    break;

            case 4:
                    break;

            default: printf("Opcao invalida!\n");
        }
    }while(op != 4);

    return 0;
}
