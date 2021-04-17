#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    conjunto_inteiro *conjunto;
    int valor;

    //A

    conjunto = cria_conjunto_vazio(conjunto);
    //B

    insere_elemento(valor, conjunto);
    //C

    remove_elemento(valor, conjunto);
    //D

    uniao_inteiro(conjunto, conjunto);
    //E

    interseccao_inteiro(conjunto, conjunto);
    //F

    diferenca_inteiro(conjunto, conjunto);
    //G

    pertence_inteiro(conjunto, valor);
    //H

    Menor_inteiro(conjunto);
    //I

    maior_inteiro(conjunto);
    //J

    conjunto_igual(conjunto, conjunto);
    //K

    tamanho(conjunto);
    //L

    if (vazio(conjunto) == 0)
    {
        printf("Lista contem elementos. ");
    }else{
        printf("Nao contem elementos.");
    }
    //M

    imprime(conjunto);

}
