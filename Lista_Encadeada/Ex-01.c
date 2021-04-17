#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no
{
    int dado;
    struct no *proximo;
} tipo_no;

typedef struct Ex-01
{
    /* data */
};


int* incluir_dado(tipo_no* inicio)
{
    tipo_no* novo;
    int dado;

    printf("Opcao 1 SELECIONADA---\n Digite o valor a ser incrementado: ");
    scanf("%d", &dado);

    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = dado;
    novo->proximo = inicio;
    inicio = novo;

    return inicio;
}

void imprimir(tipo_no* inicio)
{
    tipo_no* atual;
    printf("------number3------");
    atual = inicio; 

    while (atual!=NULL)
    {
        printf("\n %d \n",atual->dado);
        atual=atual->proximo;
    }

}

int* remover(tipo_no* inicio)
{
    tipo_no* atual;
    printf("\nOpcao 2 SELECIONADA---  \n");

    if(inicio != NULL)
    {
        atual = inicio;
        inicio = atual->proximo;
        printf("O numero %d foi excluido!\n", *atual);
        free(atual);
    }

    return inicio;
}

void finalizar(tipo_no* inicio)
{
    tipo_no* atual;
    printf("-OPCAO 4 SELECIONADA--\n");

    while (inicio != NULL)
    {
        atual = inicio;
        inicio = inicio->proximo;
        free(atual);
    }
    printf("Programa Encerrado!\n");
}

int main()
{
    int opcao;
    tipo_no *inicio = NULL;

    while (opcao != 0)
    {
        printf("\n-1 -  Inclusao de elemento no inicio da lista \n");
        printf("-2 -  Exclusao de elemento do inicio da lista \n");
        printf("-3 -  Impressao dos elementos da lista \n");
        printf("-4 -  Finalizacao do Programa \n");
        scanf("%d",&opcao);
        switch (opcao)
        {
            case 1:
                inicio = incluir_dado(inicio);
                break;

            case 2:
                inicio = remover(inicio);
                break;
            case 3:
                imprimir(inicio);
                break;

            case 4:
                finalizar(inicio);
                return 0;
        }   
    }
    return 0;
}
