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
    tipo_no *novo, *atual = lista->inicio;

    novo = (tipo_no*)malloc(sizeof(tipo_no));
    novo->dado = dado;
    novo->proximo = NULL;

    if (atual != NULL)
    {
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
        lista->quantidade_elementos++;
    }else
    {
        lista->inicio = novo;
        lista->quantidade_elementos++;
    }
}

//C

void remover_elemento(tipo_no* lista)
{
    tipo_no *anterior = NULL, *atual = lista->inicio;

    if (atual != NULL)
    {
        while (atual->proximo != NULL)
        {
            anterior = atual;
            atual = atual->proximo;
        }
        free(atual);
        if (anterior != NULL)
        {
            anterior->proximo = NULL;
        }
        else
        {
            lista->inicio = NULL;
        }
    }
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

void apagar_iguais(tipo_lista* lista, int elemento)
{
    tipo_no* atual = lista->inicio, *anterior = NULL, *auxiliar = NULL;

    while (atual != NULL)
    {
       if (atual->dado == elemento)
       {
            if (anterior == NULL)
            {
                lista->inicio = atual->proximo;
                lista->quantidade_elementos--;
                auxiliar = atual;
                
                anterior = atual;
                atual = atual->proximo;
                
                free(auxiliar);
            }

            if (atual->proximo == NULL)
            {
                anterior->proximo = NULL;
                lista->quantidade_elementos--;
                auxiliar = atual;
                
                anterior = atual;
                atual = atual->proximo;
                
                free(auxiliar);
            }

            else
            {
                anterior->proximo = atual->proximo;
                lista->quantidade_elementos--;
                auxiliar = atual;
                
                anterior = atual;
                atual = atual->proximo;
                
                free(auxiliar);
            }
       }
       else
       {
            anterior = atual;
            atual = atual->proximo;
       }
    }
}
