#include <stdio.h>
#include <string.h>
#include <helper.h>

int main()
{
	printf("---Algoritmos de Ordenação---\n\n");
	printf("Tamanho do Vetor: ");
	
	int num;
	scanf("%d", &num);
	
	int vetor[num];
	InsertRandomVector(vetor,num);

	Table table[num];

	for (int i = 0; i < num; i++)
		Int2Str(i, table[i].title);

	for (int i = 0; i < num; i++)
		Int2Str(vetor[i], table[i].row[0].charContent);

	PrintTable(table, 1, num);

	return 0;
}
