#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int id;
    struct no *proximo;
}No;

typedef struct pilha{
    No *topo;
    int tam;
}Pilha;

void criarPilha(Pilha *pilha){ //função para iniciar a pilha
    pilha->topo = NULL;
    pilha->tam = 0;
}

bool verificaPilhaVazia(Pilha *pilha){ //lista vazia ou não
   return (pilha->tam == 0); //se o tamanho da lista for = 0, então pilha vazia, caso ao contrário pilha cheia
}

void empilhar(Pilha *pilha, int n){ //empilha os valores
    No *novo = (No*)malloc(sizeof(No));
    novo->id = n;
    if(pilha->tam == NULL)
        novo->proximo = NULL;
    else
        novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->tam++;
}

void imprimePilha(Pilha *pilha, int n, int i){
    printf("---Pilha atual---\n");
    if(verificaPilhaVazia(pilha)){ //se o retorno da função for 0, pilha vazia
        printf("\tVazia!\n");
    }

    No *no = pilha->topo; //aponta para o topo da pilha
    i = pilha->tam;
    while(i != NULL){
        printf("\t%d\n", no->id); //imprime os numeros salvos na variável "id"
        no = no->proximo;
        i--;
    }
}

void pesquisa(Pilha *pilha, int v){
    if(verificaPilhaVazia(pilha)){
        printf("Pilha vazia!\n");
    }
    No *aux, *no = NULL;
    aux = pilha->topo;

    while(aux && aux->id != v)
        aux = aux->proximo;
    if(aux)
        no = aux;

    if(no){
        printf("Valor %d encontrado!!\n", v);
    } else{
        printf("Valor %d nao encontrado!!\n", v);
    }
}

void desempilhar(Pilha *pilha, int v){
    No *no = pilha->topo;
    if(pilha->topo != NULL){
        if(no->id == v){
            no = pilha->topo;
            pilha->topo = no->proximo;
            pilha->tam--;
        }
    }
}

void removerQualquerPosicao(Pilha *pilha, Pilha *pilha2, int n){
    NO *aux = pilha->topo;  // aponta para o topo
    int s;
    if(aux != NULL){ // verifica se a pilha está vazia
    	printf("\nPilha Vazia!!!");
    	return ;
	}else{
		while(pilha->topo != NULL){ // faz a verificação se a pilha é vazia
			s = desempilhar(pilha);
			if(n == s){ // verifica se o valor informado está na pillha, para ser removido
				printf("%d\n", n); // mostra o valor removido
			}else{
				empilhar(pilha2, s);
			}
		}
		while(pilha2->topo != NULL){ // retorna os valores da pilha 2 para a pilha 1
			s = desempilhar(pilha2);
			empilhar(pilha, s);
		}
	}
}

int main(){
    Pilha pilha;
    Pilha pilha2;
    criarPilha(&pilha);
    int n, i, op;

    do{
        imprimePilha(&pilha, n, i);
        printf("\t\nPilha dinamica encadeada\n1 - Inserir\n2 - Remover\n3 - Pesquisar\n4 - Sair\n\nInforme uma opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1: printf("Inserir um valor: ");
                    scanf("%d", &n);
                    empilhar(&pilha, n);
                    system("cls");
                    break;

            case 2: printf("Informe o elemento a ser removido: ");
                    scanf("%d", &n);
                    removerQualquerPosicao(&pilha, &pilha2, n);
                    break;

            case 3: printf("Informe o elemento a ser buscado: ");
                    scanf("%d", &n);
                    pesquisa(&pilha, n);
                    break;

            case 4:
                    break;

            default: printf("\nOpcao Invalida!!\n");
        }
    }while(op!=4);
    return 0;
}
