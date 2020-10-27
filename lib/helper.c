#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "helper.h"

void InsertRandomVector(int * vector, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        vector[i] = rand() % 100; 
}

void PrintTable(Table table[], int row, int col)
{
    int space[col];

    for (int j = 0; j < col; j++)
    {
        space[j] = strlen(table[j].title);

		for (int i = 0; i < row; i++)
        {
            if (strlen(table[j].row[i].charContent) > space[j])
                space[j] = strlen(table[j].row[i].charContent);
        }
    }

	int lenTable = 0;
	for(int j = 0; j < col; j++)
		lenTable += (space[j] + 1);
	for(int j = 0; j < lenTable; j++)
		printf("_");
	printf("\n");

	for(int j = 0; j < col; j++)
	{
		int add_space = space[j] - strlen(table[j].title);
        printf("|%s", table[j].title);
        for (int k = 0; k < add_space; k++)
            printf(" ");
	}
	printf("|\n");

    for (int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            int add_space = space[j] - strlen(table[j].row[i].charContent);
            printf("|%s", table[j].row[i].charContent);
            for (int k = 0; k < add_space; k++)
                printf(" ");
        }
        printf("|\n");
    }
}

void Int2Str(int num, char * str)
{
    int n = num;
    int len = 0, rem = 0;
    
    if (num != 0)
    {
        while (n != 0)
        {
            len++;
            n /= 10;
        }

        for (int i = 0; i < len; i++)
        {
            rem = num % 10;
            num = num / 10;
            str[len - (i + 1)] = rem + '0';
        }
    }
    else
    {
        str[0] = '0';
        len ++;
    }
    str[len] = '\0';
}