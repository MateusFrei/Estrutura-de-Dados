
#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"
#define TAM 100

typedef struct inteiro
{
	int *numero;
    int *tamanho;

}conjunto_inteiro;

//A
conjunto_inteiro* cria_conjunto_vazio(conjunto_inteiro *conjunto)
{

	conjunto_inteiro *conjunto = (conjunto_inteiro *) malloc(sizeof(conjunto));

    for(int i = 0; i < TAM; ++i)
    {
        conjunto->numero[i] = 0;
        conjunto->tamanho = 0;
    }

    return conjunto;
}

//B
conjunto_inteiro* insere_elemento(int valor, conjunto_inteiro *conjunto)
{
    printf("Insira um valr no vetor: ");
    scanf("%d",&valor);

    for(int i = 0; i < TAM; ++i)
    {
        if(valor == i)
        {
            conjunto->numero[i] = 1;
            conjunto->tamanho++;
        }
    }
    return conjunto;
}

//C
conjunto_inteiro* remove_elemento(int valor, conjunto_inteiro *conjunto)
{
    printf("Insira um valr no vetor: ");
    scanf("%d",&valor);

    conjunto_inteiro *auxiliar = NULL;

    for(int i = 0; i < TAM; ++i)
    {
        if(i == valor)
        {
            conjunto->numero[i] = 0;
            conjunto->tamanho--;
        }
    }
    return conjunto;
}
//D
conjunto_inteiro *uniao_inteiro(conjunto_inteiro *conjunto_1, conjunto_inteiro *conjunto_2)
{

	for (int i = 0; i < TAM; ++i)
	{
		conjunto_1->numero[i];

        for (int j = 0; j < TAM; ++j)
        {
            if (conjunto_1->numero[i] != conjunto_2->numero[j])
            {
                conjunto_1->numero[j] = conjunto_2->numero[j];
            }
        }
   
    }
    return conjunto_1;
}

//E
conjunto_inteiro *interseccao_inteiro(conjunto_inteiro *conjunto_1, conjunto_inteiro *conjunto_2)
{

	conjunto_inteiro *interseccao = (conjunto_inteiro *) malloc(sizeof(conjunto_inteiro));

	for (int i = 0; i < TAM; ++i)
	{
		for (int j = 0; j < TAM; ++j)
		{
			if (conjunto_1->numero[i] == conjunto_2->numero[j])
			{
				interseccao->numero[i] = conjunto_1->numero[i];
			}
		}
	}
    return interseccao;
}

//F
conjunto_inteiro *diferenca_inteiro(conjunto_inteiro *conjunto_1, conjunto_inteiro *conjunto_2)
{

	conjunto_inteiro *diferenca = (conjunto_inteiro *) malloc(sizeof(conjunto_inteiro));

	for (int i = 0; i < TAM; ++i)
	{
		for (int j = 0; j < TAM; ++j)
		{
			if (conjunto_1->numero[i] != conjunto_2->numero[j])
			{
				diferenca->numero[i] = conjunto_1->numero[i];
			}
		}
	}
    return diferenca;
}

//G
conjunto_inteiro *pertence_inteiro(conjunto_inteiro *conjunto, int numero)
{

	for (int i = 0; i < TAM; ++i)
	{
		if (conjunto->numero[i] == numero)
		{
			return 0;
		}
	}

	return 1;
}

//H
conjunto_inteiro *Menor_inteiro(conjunto_inteiro *conjunto)
{
	int menor;

	for (int i = 0; i < TAM; ++i)
	{
		if (conjunto->numero[i] > menor)
		{
			menor = conjunto->numero[i];
		}

		if (i == 0)
		{
			menor = conjunto->numero[i];
		}
	}
}

//I
conjunto_inteiro *maior_inteiro(conjunto_inteiro *conjunto)
{

	int maior = 0;

	for (int i = 0; i < TAM; ++i)
	{
		if (conjunto->numero[i] > maior)
		{
			maior = conjunto->numero[i];
		}
	}

}

//J
conjunto_inteiro *conjunto_igual(conjunto_inteiro *conjunto_1, conjunto_inteiro *conjunto_2)
{

	int igual;

	for (int i = 0; i < TAM; ++i)
	{
		if (conjunto_1->numero[i] != conjunto_2->numero[i])
		{
			return 1;
		}
	}
	return 0;
}


//K
conjunto_inteiro *tamanho(conjunto_inteiro *conjunto_1)
{


	for (int i = 0; i < TAM; ++i)
	{
		if (conjunto_1->numero[i] == 1)
		{
			conjunto_1->tamanho = 1;
		}
	}

	return conjunto_1;
}

//L
int vazio(conjunto_inteiro *conjunto_1)
{

	int empity;

	for (int i = 0; i < TAM; ++i)
	{
		if (conjunto_1->numero[i] == 0)
		{
			empity = 0;
		}else{
			empity++;
		}
	}

	if (empity == 1)
	{
		return 0;
	}else{
		return 1;
	}
	
}

//M
conjunto_inteiro* imprime(conjunto_inteiro *conjunto_1)
{
    conjunto_inteiro *impressao = (conjunto_inteiro *) malloc(sizeof(conjunto_inteiro));

    for (int i = 0; i < TAM; ++i)
    {
        if (conjunto_1->numero[i] == 1)
        {
            impressao->numero[i] = 1;
            impressao->tamanho = 1;

        }
        
    }
    return impressao;
}

