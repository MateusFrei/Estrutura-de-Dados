#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    
    apagar_lista(lista_2);
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

void imprimir(tipo_lista* lista)
{
    int *vetor, tam = 0;

    tam = quantidadeElementos(lista);
    vetor = obter_elementos(lista);

    for (int i = 0; i < tam; i++)
    {
        printf(" -- Elemento obtido: [%d] \n", vetor[i]);
    }
    printf("\n");
}


int main()
{
    tipo_lista *lista = NULL;
    tipo_lista *lista_2 = NULL;

   

    lista = criarListaVazia();
    lista_2 = criarListaVazia();
    
    if(verificar_vazia(lista) == 1)
    {
        printf("A lista_1 esta vazia\n");
    }
    
    if(verificar_vazia(lista_2) == 1)
    {
        printf("A lista_2 esta vazia\n");
    }

    incluir_dado(lista,1);
    incluir_dado(lista,2);
    incluir_dado(lista,1);
    incluir_dado(lista,3);

    incluir_dado(lista_2,2);
    incluir_dado(lista_2,4);
    incluir_dado(lista_2,6);
    incluir_dado(lista_2,8);
    
    imprimir(lista);
    imprimir(lista_2);

    printf("\n");

    printf("A lista_1 possue: [ %d ] elementos\n",quantidadeElementos(lista));
    printf("A lista_2 possue: [ %d ] elementos\n",quantidadeElementos(lista_2));
    printf("\n");

    remover_elemento(lista);
    printf("A exclusao do elemento resultou em: \n");
    imprimir(lista);
    printf("\n");
    
    remover_elemento(lista_2);
    printf("A exclusao do elemento resultou em: \n");
    imprimir(lista_2);
    printf("\n");

    printf("Elementos lista_1\n");
    concatenacao(lista,lista_2);
    imprimir(lista);
    printf("\n");

    apagar_iguais(lista,1);
    imprimir(lista);

    printf("Lista apagada");
    apagar_lista(lista);
      
    printf("Lista_2 apagada");
    apagar_lista(lista_2);


    return 0;
}
