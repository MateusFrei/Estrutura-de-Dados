#include <stdlib.h>

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
