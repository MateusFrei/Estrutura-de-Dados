#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_fila
{
    int dado[5];
    int quantidade_elementos;
    int inicio;
    int fim;

}tipo_fila;

//A
tipo_fila* criar_fila()
{
    tipo_fila* fila = (tipo_fila*) malloc(sizeof(tipo_fila));
    if (fila == NULL)
    {
        return 0;
    }
    
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade_elementos = 0;
    return fila;
}

//B
void enfileirar(tipo_fila *fila, int dado)
{
    
    if (fila->fim == 0)
    {
        fila->dado[fila->fim] = dado;
        fila->fim++;
        fila->quantidade_elementos++;
    }
    else
    {

        fila->dado[fila->fim] = dado;
        fila->fim++;
        fila->quantidade_elementos++;
    }
        
}   

//C
int desenfileirar(tipo_fila *fila)
{
    int auxiliar;


    auxiliar = fila->dado[fila->inicio];
    fila->dado[fila->inicio] = -1;
    fila->quantidade_elementos--;

    fila->inicio++;

    return auxiliar;
}



//D
int verificar_vazia(tipo_fila* fila)
{
    if (fila->quantidade_elementos == 0)
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
    int nada;
    while(fila->quantidade_elementos != 0)
    {
        nada = desenfileirar(fila);
    }

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
    printf(" O dado desenfileirado foi: [%d] ", desenfileirar(fila));
    printf("\n");
    printf(" O dado desenfileirado foi: [%d] ", desenfileirar(fila));
    printf("\n");
    printf(" A quantidade de elementos foi de: [%d] ", quantidadeElementos(fila));
    printf("\n");

    apagar_lista(fila);
    printf("Tchal Brigado!");
    
    return 0;
}