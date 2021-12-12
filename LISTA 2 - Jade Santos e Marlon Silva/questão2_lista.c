#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noDados{ //estruta resposavel pelos valores
    int id; //cada nó ou informação da lista é armazenada na variavel id
}NoDados;

typedef struct no{
    NoDados dados; //dados
    struct no* proximo; //referência para o próximo nó da lista
}No;

typedef struct list{
    int tam; //tamanho da lista
    No* inicio; //"nó cabeça" inicio da lista
}List;

List* criarLista(){//função que retorna uma referência para a lista
    List* lista = (List*)malloc(sizeof(List)); //criação de ponteiro para lista e alocar no espaço de memória
    lista->tam = 0; //inicia o tamanho da lista com 0
    lista->inicio = NULL; //inicio da lista aponta para NULL, ou seja, lista vazia
    return lista;
}

bool verificaListaVazia(List* list){ //lista vazia ou não
   return (list->tam == 0); //se o tamanho da lista for = 0, então lista vazia, caso ao contrário lista cheia
}

void inserir(List* list, NoDados dados){
    No* no = (No*)malloc(sizeof(No));
    no->dados = dados;
    no->proximo = list->inicio; //cria um próximo nó na lista
    list->inicio = no; //é a primeira posição da lista
    list->tam++; //incrementa mais 1 nó
}

void imprimeLista(List* list){
    printf("---Lista atual---\n");
    if(verificaListaVazia(list)){ //se o retorno da função for 0, então lista vazia
        printf("Lista vazia!\n");
    }

    No* p = list->inicio; //aponta para o inicio da lista
    while(p != NULL){
        printf("%d ", p->dados.id); //imprime os numeros salvos
        p = p->proximo;
    }
    printf("\n\n");
}

No* remover(List* list, int v){
    No *anterior, *atual;

    if(verificaListaVazia(list)){ //se o retorno da função for 0, então lista vazia
        printf("Lista vazia!\n");
    }else{
        anterior = list->inicio;
        atual = list->inicio;

        while(atual != NULL){
            if(atual->dados.id == v){
                if(atual == list->inicio){
                    list->inicio = list->inicio->proximo;
                    free(atual);
                    break;
                } else if(atual == list->inicio->proximo){
                        list->inicio->proximo = anterior;
                }
                    anterior->proximo = atual->proximo;
                    free(atual);
                    break;
                }
                else{
                    anterior = atual;
                    atual = atual->proximo;
                }
        }
    }
}

void buscar(List *list, int v){
    No *aux, *no = NULL;
    if(verificaListaVazia(list)){ //se o retorno da função for 0, então lista vazia
        printf("Lista vazia!\n");
    }

    aux = list;
    while(aux && aux->dados.id != v)
        aux = aux->proximo;
    if(aux)
        no = aux;

    if(no){
        printf("Valor %d encontrado!!\n", v);
    } else{
        printf("Valor %d nao encontrado!!\n", v);
    }
}

int main(){
    List* l = criarLista(); //cria lista
    NoDados dados, *func; //irá passar uma copia dessa variavél para função inserir
    int op, v;

    do{
        imprimeLista(l);
        printf("\tLista dinamica encadeada\n1 - Inserir\n2 - Remover\n3 - Pesquisar\n4 - Sair\n\nInforme uma opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1: printf("Inserir um valor: ");
                    scanf("%d", &dados.id);
                    inserir(l, dados);
                    system("cls");
                    break;

            case 2: printf("Informe o elemento a ser removido: ");
                    scanf("%d", &v);
                    func = remover(l, v);
                    if(func){
                        printf("Elemento %d removido!\nLista: ", v);
                    }else{
                        printf("Valor %d não encontrado!\n", v);
                    }
                    break;

            case 3: printf("Informe o elemento a ser buscado: ");
                    scanf("%d", &v);
                    buscar(l, v);
                    break;

            case 4:
                    break;

            default:
                    printf("valor invalido!!\n\n");
        }
    }while(op!=4);
    return 0;
}
