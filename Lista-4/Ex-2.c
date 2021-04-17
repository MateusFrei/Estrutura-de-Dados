#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char nome[20];
    struct no *proximo;
}tipo_no;

tipo_no *include_nome(tipo_no *inicio)
{
    char nome[20];
    tipo_no *novo = NULL, *anterior = NULL, *atual = inicio;
    printf(" 1 - Option one selected, digite um nome: ");
    fflush(stdin);
    scanf("%[^\n]s",nome);

    novo = (tipo_no*)malloc(sizeof(tipo_no));
    strcpy(novo->nome, nome);

    if(inicio != NULL)
    {
        while (atual != NULL)
        {
           if(strcmp(novo->nome, atual->nome) < 0)
            {
                if (anterior != NULL)
                {
                    anterior->proximo = novo;
                    novo ->proximo = atual;
                    return inicio;
                }

                novo->proximo = inicio;
                inicio = novo;
                return inicio;
            }
           if (atual->proximo == NULL)
           {
               atual->proximo = novo;
               novo ->proximo = NULL;
               return inicio;
           }
            anterior = atual;
            atual = atual->proximo;
        }
    }
    else
    {
        novo -> proximo = inicio;
        inicio = novo;
    }
    return inicio;
}

tipo_no *exclude_nome(tipo_no *inicio)
{
    char nome[20];
    int comp;
    tipo_no *atual = inicio, *anterior = NULL;

    printf(" 2 - Option two selected: \n");

    printf("type the name to delete: ");
    fflush(stdin);
    scanf("%[^\n]s",nome);

    if (inicio != NULL)
    {
        while (atual != NULL)
        {   
            if(strcmp(nome, atual->nome) == 0)
            {
                if (anterior == NULL)
                {
                    inicio = atual->proximo;    
                    free(atual);
                    return inicio;
                }

                if (atual ->proximo == NULL)
                {
                    anterior->proximo = NULL;
                    free(atual);
                    return inicio;
                }
                else
                {
                    anterior->proximo = atual->proximo;
                    free(atual);
                    return inicio;
                }
                
            }
            anterior = atual;
            atual = atual->proximo;             
        }
    }
    else
    {
        anterior->proximo = atual->proximo;
    }

    return inicio;
}

void buscar_nome(tipo_no *inicio)
{   
    char nome[20];
    int comp,pos=0;
    tipo_no *atual=inicio;

    printf(" 3 - Option three selected : \n \n Type a name to find: ");
    fflush(stdin);

    scanf("%[^\n]s",nome);

    if (inicio != NULL)
    {
        while (atual != NULL)
        {
            comp = strcmp(nome, atual->nome);
            pos++;
            if (comp == 0 )
            {
                printf(" \n  Nome localizado, na posicao: %d ", pos);
                printf("\n %s \n",atual->nome);
            }
            atual = atual->proximo;
        }
    }
    else
    {
        printf("\n Lista vazia. ");
    }
    
    
}

tipo_no* exclude_all(tipo_no *inicio)
{
    printf(" 4 - Option four selected: \n");
    tipo_no *auxiliar;

    if (inicio != NULL)
    {
        while (inicio != NULL)
        {
            auxiliar = inicio; 
            inicio = auxiliar ->proximo;
            free(auxiliar);
        }
    }
    
    return inicio;
}

void finish(tipo_no* inicio)
{
    printf(" 5 - Option five selected: \n");
    tipo_no *auxiliar = inicio;

    if (inicio != NULL)
    {    
        while (inicio != NULL)
        {
            auxiliar = inicio;
            inicio = auxiliar -> proximo;
            free(auxiliar);
        }
    }
    
    printf(" O programa foi encerrado. \n");
}

int main()
{
    int option;
    tipo_no *inicio = NULL;

    while(option != 5)
    {
        printf("\n 1- Incluir nome: \n");
        printf(" 2- Excluir nome: \n");
        printf(" 3- Buscar por nome: \n");
        printf(" 4- Limpar a lista: \n");
        printf(" 5- Encerrar programa. \n");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                inicio = include_nome(inicio);
                break;

            case 2:
                inicio = exclude_nome(inicio);
                break;

            case 3:
                buscar_nome(inicio);
                break;

            case 4:
                inicio = exclude_all(inicio);
                break;

            case 5:
                finish(inicio); 
                break;
                return 0;
        }
    }
    return 0;
}
