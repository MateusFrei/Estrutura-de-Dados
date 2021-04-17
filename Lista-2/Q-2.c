#include <stdio.h>
#include <stdlib.h>

int* somatorio(int n, int* v)
{
	int *w;
	 
	w = (int*) malloc(sizeof(int));

    w[0] = v[0];
    for (int i = 0; i < n; i++)
    {
       if (i > 0)
       {
           w[i] = v[i] + w[i - 1];
       }
    }
	return w;
}

int main()
{
	int n = 3, v[3] = {5, 2, 1};
    int *w = somatorio(n, &v);

    for (int i = 0; i < 3; i++)
    {
        printf("The value is: [%d]\n",w[i]);
    }
    
	return 0;
}	
