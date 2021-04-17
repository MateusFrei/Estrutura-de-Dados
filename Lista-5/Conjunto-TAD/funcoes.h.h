typedef struct inteiro
{
	int *numero;
    int *tamanho;

}conjunto_inteiro;

conjunto_inteiro* cria_conjunto_vazio(conjunto_inteiro *);
conjunto_inteiro* insere_elemento(int valor, conjunto_inteiro *);
conjunto_inteiro* remove_elemento(int valor, conjunto_inteiro *);
conjunto_inteiro *uniao_inteiro(conjunto_inteiro *, conjunto_inteiro *);
conjunto_inteiro *interseccao_inteiro(conjunto_inteiro *, conjunto_inteiro *);
conjunto_inteiro *diferenca_inteiro(conjunto_inteiro *, conjunto_inteiro *);
conjunto_inteiro *pertence_inteiro(conjunto_inteiro *, int numero);
conjunto_inteiro *Menor_inteiro(conjunto_inteiro *);
conjunto_inteiro *maior_inteiro(conjunto_inteiro *);
conjunto_inteiro *conjunto_igual(conjunto_inteiro *, conjunto_inteiro *);
conjunto_inteiro *tamanho(conjunto_inteiro *);
int vazio(conjunto_inteiro *);
conjunto_inteiro* imprime(conjunto_inteiro *);
