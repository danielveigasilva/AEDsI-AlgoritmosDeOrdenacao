#ifndef _HELPER_LIB_
#define _HELPER_LIB_

typedef struct Table
{
	char type;
	char title[30];
    struct Cell
    {
    	int intContent;
    	char charContent[30];
    } row[30];
} Table;

void InsertRandomVector(int * vector, int size);
int RandomSize(int max);
void PrintTable(Table table[], int row, int col);
void Int2Str(int num, char * str);
void printv(int Vector[], int n);

#endif
