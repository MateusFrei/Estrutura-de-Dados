#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *proximo;
}tipo_no;


tipo_no *enfileirar(tipo_no *inicio)
{
    int dado;
    tipo_no *novo, * atual = inicio;

    printf(" 2 - Option second selected: \n");
    scanf("%d",&dado);

    novo = (tipo_no*)malloc(sizeof(tipo_no));
    novo->dado = dado;
    novo->proximo = NULL;

    if (inicio != NULL)
    {
        while (atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }else{
        inicio = novo;
    }
    return inicio;
}   

tipo_no *exclude_inicio(tipo_no *inicio)
{
    printf(" 3 - Option thirdy selected: \n");
    tipo_no *auxiliar;
    while (auxiliar != NULL)
    {
        auxiliar = inicio; 
        inicio = inicio ->proximo;
        free(auxiliar);
    }
    return inicio;
}


tipo_no* exclude_all(tipo_no *inicio)
{
    printf(" 6 - Option six selected: \n");
    tipo_no *auxiliar;

    while(inicio != NULL)
    {
        auxiliar = inicio;
        inicio = inicio -> proximo;
        free(auxiliar);
    }
    return inicio;
}

void finish(tipo_no* inicio)
{
    printf(" 7 - Option seven selected: \n");
    tipo_no *auxiliar;

    while (inicio != NULL)
    {
        auxiliar = inicio;
        inicio = inicio -> proximo;
        free(auxiliar);
    }
    printf(" O programa foi encerrado. \n");
}

int

int main()
{
    tipo_no *inicio = NULL;
    int option;

    while(option != 7)
    {
        printf("\n 1- Incluir no inicio: \n");
        printf(" 2- Incluir no fim: \n");
        printf(" 3- Excluir no inicio: \n");
        printf(" 4- Excluir no fim: \n");
        printf(" 5- Exibir elementos: \n");
        printf(" 6- Excluir todos elementos: \n");
        printf(" 7- Encerrar programa. \n");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                inicio = include_data_inicio(inicio);
                break;

            case 2:
                inicio = include_data_end(inicio);
                break;

            case 3:
                inicio = exclude_inicio(inicio);
                break;

            case 4:
                inicio = exclude_fim(inicio);
                break;

            case 5:
                show_me(inicio);
                break;

            case 6:
               inicio = exclude_all(inicio);
                break;

            case 7:
                finish(inicio);
                break;
                return 0;
        }
    }
}