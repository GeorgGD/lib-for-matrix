#include <stdio.h>
#include <stdlib.h>
#include "common.h"

void create_matrix_k(matrix_t *m)
{
  if(m == NULL)
    return;
  
  int size = m->size;
  int end = size-1;
  int n = 0;
  for(int i = 0; i < end; ++i)
    {
      m->matrix[i][n] = 2;
      m->matrix[i][n+1] = -1;
      m->matrix[i+1][n] = -1;
      n++;
    }
  m->matrix[end][end] = 1;
}

matrix_t *create_matrix(int size)
{
  if(size == 0)
    return NULL;
  
  matrix_t *m = malloc(sizeof(matrix_t));
  m->matrix = calloc(size, sizeof(double*));

  for(int i = 0; i < size; ++i)
    {
      m->matrix[i] = calloc(size, sizeof(double));
    }
  m->size = size;
  return m;
}




