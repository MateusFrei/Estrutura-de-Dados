#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

typedef struct esfera
{
	float area,raio,volume, diametro;
}esfera;



esfera *preenche(float diametro){
 
	esfera = (esfera *) malloc(sizeof(esfera));
	esfera -> raio = raio;
	esfera -> diametro = diametro;

	return esfera;
}

float area(esfera *esfera){
	float area;
    
    area = 3.14 * esfera->diametro*esfera->diametro;

	return area;
}
float raio(esfera *esfera){
	float raio;

    raio = esfera->diametro*2;
	
    return raio;
}

float volume(esfera *volume, float raio)
{
    volume = 4/3 * 3.14 * raio*raio*raio;

    return volume;
}
