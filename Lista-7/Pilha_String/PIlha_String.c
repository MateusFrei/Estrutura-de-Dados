
//Questão - 5
void inverteFrase(char* frase, tipo_pilha* pilha)
{
	tipo_pilha* auxiliar;

	while()
}


//Questão - 6 
int verificaParenteses(tipo_pilha* pilha)
{
	tipo_no atual;
	atual = pilha->topo;

	int cont = 0, cont2 = 0;
	
	while(atual != NULL)
	{
		if(atual->num == '(')
		{
			cont++;
		}
		if(atual->num == ')')
		{
			cont2++;
		}
		atual = atual->proximo;
	}
	
	if(cont == cont2){
		return 1;
	}
	else{
		return 0;
	}
}


