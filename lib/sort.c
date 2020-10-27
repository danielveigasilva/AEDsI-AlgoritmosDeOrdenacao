#include <stdio.h>
#include "sort.h"

void MergeSort(int *Vector, int leftInd, int rightInd)
{
  //  leftInd--+                   +--rightInd
  //           |                   |
  //Indice -> [0] [1] [2] [3] [4] [5]

  if (leftInd < rightInd) // Verifica se o indice Esquerdo é menor que o Direito
  {
    int middleInd = (leftInd+rightInd)/2; //Localiza o indice do Meio do vetor

    MergeSort(Vector, leftInd, middleInd); //Passa recursivamente os novos intervalos do vetor da esquerda
    //  leftInd--+       +--rightInd
    //           |       |
    //Indice -> [0] [1] [2] [3] [4] [5]

    MergeSort(Vector, middleInd+1, rightInd); //Passa recursivamente os novos intervalos do vetor da direta
    //              leftInd--+       +--rightInd
    //                       |       |
    //Indice -> [0] [1] [2] [3] [4] [5]

    Marge(Vector, leftInd, middleInd, rightInd);
  }
}

void Marge(int *Vector, int leftInd, int middleInd, int rightInd)
{
  int init1 = leftInd;
  int init2 = middleInd + 1;
  int size1 = middleInd - leftInd + 1;
  int size2 = rightInd - middleInd;
  int Vector1[size1];
  int Vector2[size2];

  for (int i = 0; i < size1 - 1; i++)
    Vector1[i] = Vector[init1 + i];
  for (int i = 0; i < size2 - 1; i++)
    Vector2[i] = Vector[init2 + i];
}
