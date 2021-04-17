#include <stdio.h>
#include "pilha_dinamica_Header.h"

//Questão - 4
int comparaPilha(tipo_pilha* pilha1, tipo_pilha* pilha2)
{	
	int tam_1;
	int tam_2;

    tam_1 = quantidadeElementos(pilha1);
    tam_2 = quantidadeElementos(pilha2);

	int vetor_1[tam_1], vetor_2[tam_2];

	if (tam_1 != tam_2)
	{
		return 0;
	}

	for (int i = 0; i < tam_1; i++)
	{
		vetor_1[i] = desempilhar(pilha1);
		vetor_2[i] = desempilhar(pilha2);
	}
	

	for (int i = 0; i < tam_1; i++)
	{
		if (vetor_1[i] != vetor_2[i])
		{
			return 0;
		}
	}
	
	return 1;
	
}

int main()
{
    tipo_pilha *pilha, *pilha_2;

    pilha = criaPilha();
    pilha_2 = criaPilha();

    empilhar(pilha, 1);
    empilhar(pilha, 2);
    empilhar(pilha, 3);
    empilhar(pilha, 4);

    empilhar(pilha_2, 1);
    empilhar(pilha_2, 2);
    empilhar(pilha_2, 3);
    empilhar(pilha_2, 4);

    if (comparaPilha(pilha, pilha_2) == 0)
    {
        printf(" As Pilhas sao diferentes. ");
    }
    else
    {
        printf(" As pilhas sao iguais. ");
    }
    

}