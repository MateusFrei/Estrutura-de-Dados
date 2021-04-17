#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

int main()
{
    float raio, area, diametro, volume;
    esfera *esfera;

    printf("Entre com o diametro:");
    scanf("%f",&diametro);

    esfera = preenche(esfera, area, raio, volume, diametro);

    printf(" %f ", area(esfera));
    printf(" %f ", raio(esfera));
    printf(" %f ", volume(esfera *esfera, raio));
}
