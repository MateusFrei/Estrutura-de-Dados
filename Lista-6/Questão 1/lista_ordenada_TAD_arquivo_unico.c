#include<stdio.h>
#include<stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} tipo_no;

typedef struct reg_lista
{
    tipo_no *inicio;
    int quantidadeElementos;
} tipo_lista;

tipo_lista* criarListaVazia()
{
    tipo_lista*lista = (tipo_lista*) malloc(sizeof(tipo_lista));
    lista->inicio = NULL;
    lista->quantidadeElementos = 0;
    return lista;
}

int listaVazia(tipo_lista*lista)
{
    if (lista->quantidadeElementos == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int quantidadeElementosLista(tipo_lista*lista)
{
    return lista->quantidadeElementos;
}

tipo_lista*apagarLista(tipo_lista*lista)
{
    tipo_no *auxiliar;

    while (!listaVazia(lista))
    {
        auxiliar = lista->inicio;
        lista->inicio = lista->inicio->proximo;
        free(auxiliar);
    }
    free(lista);
    return NULL;
}

void inserirElementoOrdenado(tipo_lista*lista, int dado)
{
    tipo_no *novo, *atual = lista->inicio, *anterior = NULL;

    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = dado;

    if (lista->inicio == NULL)
    {
        novo->proximo = NULL;
        lista->inicio = novo;
    }
    else
    {
        while ((atual != NULL) && (atual->dado < dado))
        {
            anterior = atual;
            atual = atual->proximo;
        }
        if (anterior == NULL)
        {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
        }
        else
        {
            anterior->proximo = novo;
            novo->proximo = atual;
        }
    }
    lista->quantidadeElementos++;
}

int* obterElementosLista(tipo_lista*lista)
{
    tipo_no *atual = lista->inicio;
    int *elementosImpressos, posicao;

    elementosImpressos = (int*) malloc(lista->quantidadeElementos * sizeof(int));

    posicao = 0;
    while (atual != NULL)
    {
        elementosImpressos[posicao] = atual->dado;
        atual = atual->proximo;
        posicao++;
    }
    printf("\n");
    return elementosImpressos;
}

int excluirElementoOrdenado(tipo_lista*lista, int dado)
{
    tipo_no *auxiliar, *anterior = NULL, *atual = lista->inicio;

    while ((atual != NULL) && (atual->dado != dado))
    {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual->dado == dado)
    {
        if (anterior == NULL)
        {
            lista->inicio = atual->proximo;
        }
        else
        {
            anterior->proximo = atual->proximo;
        }
        auxiliar = atual;
        free(auxiliar);
        lista->quantidadeElementos--;
        return 1;
    }
    else
    {
        return 0;
    }
}

//--Quest??o - 01

float calcular_media(tipo_lista* lista)
{
    tipo_no *auxiliar = lista->inicio;
    int denominador = lista ->quantidadeElementos;
    float numerador = 0, media = 0;

    while (auxiliar != NULL)
    {
        numerador += auxiliar->dado;
        auxiliar  = auxiliar -> proximo;
    }
    
    media = numerador/denominador;
    
    return media;
}

int verificar_profundidade(tipo_lista* lista, int dado)
{
    tipo_no *auxiliar = lista->inicio;
    int profundidade = 0;

    while (auxiliar != NULL)
    {
        if(auxiliar->dado != dado)
        {
            profundidade++;
            auxiliar = auxiliar ->proximo;
        }
        else
        {
            profundidade++;
            return profundidade;
        }
    }
    return 0;
}

int comparar(tipo_lista* lista, tipo_lista* lista_2)
{
    tipo_no *atual_1 = lista->inicio;
    tipo_no *atual_2 = lista_2->inicio;

    if((lista -> inicio != NULL) && (lista_2 -> inicio))
    {
        if (lista->quantidadeElementos != lista_2->quantidadeElementos)
        {
            return 0;
        }

        while((atual_1 != NULL) && (atual_2 != NULL))
        {

            if(atual_1->dado != atual_2->dado)
            {
                return 0;
            }
            atual_1 = atual_1 -> proximo;
            atual_2 = atual_2 -> proximo;
        }

        return 1;

    }
}
//-----------------



//-----------------     Programa Principal     ----------------------------

void imprimirLista(tipo_lista*listaOrdenada)
{
    int *elementosLista, posicao;
    elementosLista = obterElementosLista(listaOrdenada);
    for (posicao = 0; posicao < quantidadeElementosLista(listaOrdenada); posicao++)
    {
        printf("%d ", elementosLista[posicao]);
    }
    printf("\n");
}

int main()
{
    tipo_lista* listaOrdenada = NULL;

    listaOrdenada = criarListaVazia();
    inserirElementoOrdenado(listaOrdenada, 20);
    inserirElementoOrdenado(listaOrdenada, 10);
    inserirElementoOrdenado(listaOrdenada, 15);
    inserirElementoOrdenado(listaOrdenada, 1);
    inserirElementoOrdenado(listaOrdenada, 5);
    imprimirLista(listaOrdenada);
    calcular_media(listaOrdenada);
    excluirElementoOrdenado(listaOrdenada, 5);
    imprimirLista(listaOrdenada);

    excluirElementoOrdenado(listaOrdenada, 1);
    imprimirLista(listaOrdenada);

    excluirElementoOrdenado(listaOrdenada, 20);
    imprimirLista(listaOrdenada);

    excluirElementoOrdenado(listaOrdenada, 15);

    excluirElementoOrdenado(listaOrdenada, 10);
    imprimirLista(listaOrdenada);

    inserirElementoOrdenado(listaOrdenada, 20);
    inserirElementoOrdenado(listaOrdenada, 10);
    inserirElementoOrdenado(listaOrdenada, 15);
    inserirElementoOrdenado(listaOrdenada, 1);
    inserirElementoOrdenado(listaOrdenada, 5);
    imprimirLista(listaOrdenada);
    printf("%d\n", quantidadeElementosLista(listaOrdenada));
    excluirElementoOrdenado(listaOrdenada, 10);
    printf("%d\n", quantidadeElementosLista(listaOrdenada));
    printf("%d\n", listaOrdenada->quantidadeElementos);
    listaOrdenada = apagarLista(listaOrdenada);
    if (!listaOrdenada)
    {
        printf("Lista apagada!");
    }
    else
    {
        printf("A lista ainda existe!");
    }
    
    return 0;
}
