#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noDados{ //estruta resposavel pelos valores
    int id; //cada n� ou informa��o da lista � armazenada na variavel id
}NoDados;

typedef struct no{
    NoDados dados; //dados
    struct no* proximo; //refer�ncia para o pr�ximo n� da lista
}No;

typedef struct list{
    int tam; //tamanho da lista
    No* inicio; //"n� cabe�a" inicio da lista
}List;

List* criarLista(){//fun��o que retorna uma refer�ncia para a lista
    List* lista = (List*)malloc(sizeof(List)); //cria��o de ponteiro para lista e alocar no espa�o de mem�ria
    lista->tam = 0; //inicia o tamanho da lista com 0
    lista->inicio = NULL; //inicio da lista aponta para NULL, ou seja, lista vazia
    return lista;
}

bool verificaListaVazia(List* list){ //lista vazia ou n�o
   return (list->tam == 0); //se o tamanho da lista for = 0, ent�o lista vazia, caso ao contr�rio lista cheia
}

void inserir(List* list, NoDados dados){
    No* no = (No*)malloc(sizeof(No));
    no->dados = dados;
    no->proximo = list->inicio; //cria um pr�ximo n� na lista
    list->inicio = no; //� a primeira posi��o da lista
    list->tam++; //incrementa mais 1 n�
}

void imprimeLista(List* list){
    printf("---Lista atual---\n");
    if(verificaListaVazia(list)){ //se o retorno da fun��o for 0, ent�o lista vazia
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

    if(verificaListaVazia(list)){ //se o retorno da fun��o for 0, ent�o lista vazia
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
    if(verificaListaVazia(list)){ //se o retorno da fun��o for 0, ent�o lista vazia
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
    NoDados dados, *func; //ir� passar uma copia dessa variav�l para fun��o inserir
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
                        printf("Valor %d n�o encontrado!\n", v);
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
