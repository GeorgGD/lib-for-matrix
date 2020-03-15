#include <stdio.h>
#include <stdlib.h>
#include "common.h"

matrix_t *create_empty_matrix(int size)
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

void random_matrix(matrix_t *matrix)
{
  int size = matrix->size;
  double **m = matrix->matrix;
  int start = size * size;
  for(int i = 0; i < size; ++i)
    {
      for(int j = 0; j < size; j++)
	{
	  m[i][j] = start;
	  start -= 1;
	}
    }
}

void create_upper_matrix(matrix_t *m)
{
  if(m == NULL)
    return;
  
}

void create_lower_matrix(matrix_t *m)
{
  if(m == NULL)
    return;
  
}

void destroy_matrix(matrix_t *m)
{
  if(m == NULL)
    return;
  int size = m->size;
  
  for(int i = 0; i < size; ++i)
    {
      free(m->matrix[i]);
    }
  free(m->matrix);
  free(m);
}

void lu_factor(matrix_t *matrix)
{
  if(matrix == NULL)
    return;
  
  double **m = matrix->matrix;
  int size = matrix->size;
  double diag;
  
  for(int i = 0; i < size; i++)
    {
      diag = m[i][i];
      for(int j = i +1; j < size; j++)
	{
	  m[j][i] = m[j][i] / diag;
	  for(int k = i + 1; k < size; k++)
	    {
	      m[j][k] = m[j][k] - m[j][i] * m[i][k]; 
	    }
	}
    }
}
