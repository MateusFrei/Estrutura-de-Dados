#include <stdlib.h>


typedef struct no
{
    int dado;
    struct no *proximo;
} tipo_no;

typedef struct lista_inicio
{
    tipo_no* inicio;
    int quantidade_elementos;
} tipo_lista;

//A

tipo_lista* criarListaVazia()
{
    tipo_lista* lista = (tipo_lista*) malloc(sizeof(tipo_lista));
    lista->inicio = NULL;
    lista->quantidade_elementos = 0;
    return lista;
}

//B

void incluir_dado(tipo_lista* lista, int dado)
{
    tipo_no* novo;

    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = dado;
    novo->proximo = lista ->inicio;
    lista ->inicio = novo;

    lista ->quantidade_elementos++;
}

//C

void remover_elemento(tipo_lista* lista)
{
    tipo_no* atual;

    if (lista->inicio != NULL)
    {
        atual = lista->inicio;
        lista->inicio = atual->proximo;
        lista ->quantidade_elementos--;
        free(atual);
    }
    printf("\n");
}

//D

int verificar_vazia(tipo_lista* lista)
{
    if (lista->inicio == NULL)
    {
        return 1;
    }
    return 0;
    
}

//E

int quantidadeElementos(tipo_lista* lista)
{
    return lista->quantidade_elementos;
}


//F

void apagar_lista(tipo_lista* lista)
{
    tipo_no* atual;

    while (lista->inicio != NULL)
    {
        atual = lista->inicio;
        lista->inicio = atual->proximo;
        lista ->quantidade_elementos--;
        free(atual);
    }
    printf("\n");
}

//G

int* obter_elementos(tipo_lista* lista)
{
    tipo_no* atual = lista->inicio;
    int posicao, *vetor_elementos;

    vetor_elementos = (int*) malloc(sizeof(lista->quantidade_elementos));
    posicao = 0;

    while (atual != NULL)
    {
        vetor_elementos[posicao] = atual->dado;
        posicao++;
        atual = atual->proximo;

    }
    return vetor_elementos;
}

//H

void concatenacao(tipo_lista* lista, tipo_lista* lista_2)
{
    tipo_no*atual = lista_2->inicio;

    while (atual != NULL)
    {
        incluir_dado(lista, atual->dado);
        atual = atual->proximo;
    }
    
    lista->quantidade_elementos = lista->quantidade_elementos + lista_2->quantidade_elementos;

    apagar_lista(lista_2);
}
