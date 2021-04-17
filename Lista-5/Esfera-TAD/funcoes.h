typedef struct esfera
{
	float area,raio,volume;
}esfera;

esfera *preenche(esfera *, float , float , float, float);

float area(esfera *);

float raio(esfera *, esfera *);

float volume(esfera *, float);


