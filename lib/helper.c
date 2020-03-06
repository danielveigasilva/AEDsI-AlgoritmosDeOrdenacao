#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "helper.h"

int * RandomVector(int size)
{
    int vector[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        vector[i] = rand() % 100; 
    return (int *) vector;
}

int main()
{
    int d;
    scanf("%d", d);
    int * teste = RandomVector(d);
    for (int i = 0; i < d; i++)
        printf("%d ", teste[i]);

    printf("\nFIM\n");
    scanf("%d", d);
    return 0;
}