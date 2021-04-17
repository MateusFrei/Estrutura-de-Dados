#include <stdlib.h>

//A
tipo_fila* criar_fila()
{
    tipo_fila* fila = (tipo_fila*) malloc(sizeof(tipo_fila));
    if (fila == NULL)
    {
        return 0;
    }
    
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

//B
int enfileirar(tipo_fila *fila, int dado)
{
    tipo_no *novo, *atual = fila ->inicio;

    novo = (tipo_no*)malloc(sizeof(tipo_no));
    if (novo == NULL)
    {
        return 0;
    }
    
    novo->dado = dado;
    novo->proximo = NULL;

    if (atual != NULL)
    {
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
        fila->quantidade_elementos++;
    }
    else
    {
        fila->inicio = novo;
        fila->quantidade_elementos++;
    }
        
}  

//C
void desenfileirar(tipo_fila *fila)
{
    tipo_no *auxiliar;
    int dado;

    while (auxiliar != NULL)
    {
        auxiliar = fila->inicio; 
        fila->inicio = auxiliar->proximo;
        dado = auxiliar->dado;
        free(auxiliar);
        return dado;
    }
    
}

//D
int verificar_vazia(tipo_fila* fila)
{
    if (fila->inicio == NULL)
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
void apagar_lista(tipo_fila *fila)
{
    tipo_no *auxiliar;

    while(fila->inicio != NULL)
    {
        auxiliar = fila->inicio;
        fila->inicio = auxiliar->proximo;
        free(auxiliar);
    }
    
    fila->quantidade_elementos = 0;
}
