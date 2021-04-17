#include <stdio.h>
#include <stdlib.h>

void change(int *ptr_1, int *ptr_2)
{
    int aux;
    
    aux = *ptr_1;
    *ptr_1 = *ptr_2;
    *ptr_2 = aux;
}

int main()
{
    int num_1 = 10, num_2 = 6, *ptr_1, *ptr_2;
     /*
    printf("Type the firts num_1: ");
    scanf("%d",&num_1);


    printf("Type the firts num_2: ");
    scanf("%d",&num_2);
*/
    ptr_1 = &num_1;
    ptr_2 = &num_2;
    
    change(ptr_1, ptr_2);
    
    printf("\n-----THE CHANGE----\n");
    printf("Num_1 [%d] and ",num_1);
    printf("Num_2 [%d] ",num_2);
    return 0;
}