#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} tipo_no;

int* incluir_no()
{
    
}

int main()
{
    int opcao, dado, pos;
    tipo_no *inicio = NULL, *novo = NULL, *atual = NULL, *auxiliar = NULL;

    srand(time(NULL));
    for (int pos = 1; pos < 5; pos++)
    {
        dado = rand()%100;
        novo = (tipo_no*) malloc(sizeof(tipo_no));
        novo->dado = dado;
        novo->proximo = inicio;
        inicio = novo;
    }

//impressão
    while (atual != NULL)
    {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    
}
