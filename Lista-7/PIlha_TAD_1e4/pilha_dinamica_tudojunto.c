#include <stdlib.h>

typedef struct elemento
{
	int dado;
	struct elemento *proximo;

}tipo_no;

typedef struct pilha
{
	tipo_no* topo;
	int quantidade_elementos;

}tipo_pilha;


//A
tipo_pilha* criaPilha()
{
    tipo_pilha* pilha = (tipo_pilha*) malloc(sizeof(tipo_pilha));
    pilha->topo = NULL;
    pilha->quantidade_elementos = 0;
    return pilha;
}


//B
void empilhar(tipo_pilha* pilha, int dado)
{
	tipo_no* novo;

    novo = (tipo_no*) malloc(sizeof(tipo_no));
    novo->dado = dado;
    novo->proximo = pilha ->topo;
    pilha->topo = novo;

    pilha->quantidade_elementos++;
}


//C
int desempilhar(tipo_pilha* pilha)
{
    tipo_no* atual;
	int dado;

    if (pilha->topo != NULL)
    {
        atual = pilha->topo;
        pilha->topo = atual->proximo;
		dado = atual->dado;
        pilha ->quantidade_elementos--;
        free(atual);
		
		return dado;
    }

}


//D
int verificar_vazia(tipo_pilha* pilha)
{
	if (pilha->topo == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}

	if (pilha->quantidade_elementos == 0)
	{
		return 1;
	}else
	{
		return 0;
	}
    
}


//E
int quantidadeElementos(tipo_pilha* pilha)
{
    return pilha->quantidade_elementos;
}


//F
void esvaziarPilha(tipo_pilha* pilha)
{
    tipo_no* atual;

    while (pilha->topo != NULL)
    {
        atual = pilha->topo;
        pilha->topo = atual->proximo;
        pilha ->quantidade_elementos--;
        free(atual);
    }
    
	if(pilha->topo == NULL)
	{
		pilha = NULL;
	}

}




int main()
{
	tipo_pilha *pilha = NULL;
    tipo_pilha *pilha_2 = NULL;


//A
    pilha = criaPilha();
    pilha_2 = criaPilha();

//B
	empilhar(pilha, 1);
	empilhar(pilha, 2);	
	empilhar(pilha, 3);
	empilhar(pilha, 7);
	empilhar(pilha_2, 6);
	empilhar(pilha_2, 4);	
	empilhar(pilha_2, 6);
	empilhar(pilha_2, 9);
//C
	desempilhar(pilha);
	printf("\n");
   	desempilhar(pilha_2);
	printf("\n");
//D
	if (verificar_vazia(pilha) == 1)
	{
		printf(" A Lista-1 esta vazia.\n");
	}
	if (verificar_vazia(pilha_2) == 1)
	{
		printf(" A Lista-2 esta vazia.\n");
	}
//E
	printf("A quantidade de elementos da lista-1: [%d]", quantidadeElementos(pilha));
	printf("A quantidade de elementos da lista-1: [%d]", quantidadeElementos(pilha_2));
	printf("\n");
//F
	esvaziarPilha(pilha);
	esvaziarPilha(pilha_2);
    return 0;
}
