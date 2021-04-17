#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
}tipo_no;

typedef struct tipo_fila
{
    tipo_no *inicio;
    int quantidade_elementos;
    tipo_no *fim;

}tipo_fila;

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
int quantidadeElementos(tipo_fila* fila)
{
    return fila->quantidade_elementos;
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


int main()
{
    tipo_fila *fila = NULL;

    fila = criar_fila();

    if (verificar_vazia(fila) == 1)
    {
        printf("Lista esta vazia. ");
    }
    
    enfileirar(fila, 5);
    enfileirar(fila, 6);
    enfileirar(fila, 8);
    
    printf(" O dado desenfileirado foi: [%d] ", desenfileirar(fila));
    printf("\n");

    printf(" A quantidade de elementos foi de: [%d] ", quantidadeElementos(fila));
    printf("\n");

    apagar_lista(fila);
    
    return 0;
}