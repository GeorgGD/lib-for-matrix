#include <stdio.h>
#include <stdlib.h>
#include "common.h"

//TODO: create upper matrix
//TODO: create lower matrix
//TODO: Optimizations
//Deadline: 20/03/16 !!!!!!

matrix_t *create_empty_matrix(int size)
{
  if(size == 0)
    return NULL;
  
  matrix_t *m = malloc(sizeof(matrix_t));
  m->matrix = malloc(size * sizeof(double*));

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

matrix_t *create_upper_matrix(matrix_t *m)
{
  if(m == NULL)
    return NULL;
  int size = m->size;
  matrix_t *upper_matrix = create_empty_matrix(size);
  double ** lu_matrix = m->matrix;

  for(int i = 0; i < size; ++i)
    {
      upper_matrix->matrix[i][i] = lu_matrix[i][i];
      for(int j = i; j < size; ++j)
	{
	  upper_matrix->matrix[i][j] = lu_matrix[i][j];
	}
    }
  return upper_matrix;
}

matrix_t *create_lower_matrix(matrix_t *m)
{
  if(m == NULL)
    return NULL;
  int size = m->size;
  matrix_t *lower_matrix = create_empty_matrix(size);
  double ** lu_matrix = m->matrix;

  for(int i = 0; i < size; ++i)
    {
      lower_matrix->matrix[i][i] = 1;
      for(int j = i; j < size; ++j)
	{
	  lower_matrix->matrix[j][i] = lu_matrix[j][i];
	}
    }
  return lower_matrix;
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
