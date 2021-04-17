#include <stdio.h>
#include <stdlib.h>

int** ordernar(int n, int* v)
{
	int **w,*aux;
	 
	w = (int**) malloc(n * sizeof(int*));

	for (int i = 0; i < n; ++i) {
        w[i] = &v[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (*w[i] > *w[j])
            {
                aux = w[j];
                w[j] = w[i];
                w[i] = aux;
            }
            
        }
        
    }
	return w;
}

int main()
{
	int n = 3;
	int v[3] = {8, 7,5};
    int **w;
	
    printf("Values:\n");
	for (int i = 0; i < n; i++)
    {
        printf("%d ",v[i]);
        printf("- His address: [%p]\n",&v[i]);
    }
	
    printf("\n\n");
    printf("Address: \n");

    w = ordernar(n, &v);
    for (int i = 0; i < n; i++)
    {
        printf("%p -",w[i]);
        printf(" %d \n",*w[i]);
    }

    free(w);
    w = NULL;               

	return 0;
}	
