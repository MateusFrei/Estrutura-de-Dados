#include <string.h>
#include <stdio.h>
#include "PIlha_String_Header.h"

//Questao -5
void inverter_string(tipo_pilha* pilha, char* dado, int tam)
{

    tipo_pilha *a;
    int size;

    for (int i = 0; i < tam; i++)
    {
    
        if(empilhar(pilha, dado) == 0)
        {
            printf(" Letra nao pode ser alocada.");
        }
    }
    
    size = quantidadeElementos(pilha);

    for (int i = 0; i < size; i++)
    {
        printf("%c",desempilhar(pilha));
    }

}

int main()
{
    int tam;
    char* dado[20];
    tipo_pilha* pilha = NULL;

    pilha = criaPilha();
    if (pilha == NULL)
    {
        printf("Pilha nao pode ser alocada.");
    }
    

    printf("\n  Digite uma frase: ");
    scanf(" %[^\n]s", dado);

    tam = strlen(frase);

    inverter_string(pilha, dado, tam);

    return 0;
}