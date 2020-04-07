#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>
#include "matrix_lib.h"

static int nthreads = 1;

void destroy_matrix(matrix_t *m)
{
  if(m == NULL)
    return;
  const int size = m->size;
  
  for(int i = 0; i < size; ++i)
    {
      free(m->matrix[i]);
    }
  free(m->matrix);
  free(m);
}

matrix_t *create_empty_matrix(const int size)
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
  const int size = matrix->size -1;
  double **m = matrix->matrix;
  int j = 0;
  for(int i = 0; i < size; ++i)
    {
      m[i][i] = 4;
      m[i][j+1] = -2;
      m[i+1][j] = -2;
	j++;
    }
  m[size][size] = 2;
}

matrix_t *create_upper_matrix(matrix_t *m)
{
  if(m == NULL)
    return NULL;
  const int size = m->size;
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
  const int size = m->size;
  matrix_t *lower_matrix = create_empty_matrix(size);
  double ** lu_matrix = m->matrix;

  for(int i = 0; i < size; ++i)
    {
      lower_matrix->matrix[i][i] = 1;
      for(int j = i + 1; j < size; ++j)
	{
	  lower_matrix->matrix[j][i] = lu_matrix[j][i];
	}
    }
  return lower_matrix;
}

static void inner_loop(int size, int i, double diag, double **m)
{
#pragma omp parallel for num_threads(nthreads)
  for(int j = i +1; j < size; j++)
    {
      m[j][i] = m[j][i] / diag;
      for(int k = i + 1; k < size; k++)
	{
	  m[j][k] = m[j][k] - m[j][i] * m[i][k]; 
	}
    }
}

void lu_factor(matrix_t *matrix, const int num_threads)
{
  if(matrix == NULL)
    return;

  nthreads = num_threads;
  double **m = matrix->matrix;
  const int size = matrix->size;
  double diag;
  
  for(int i = 0; i < size; i++)
    {
      diag = m[i][i];
      inner_loop(size, i, diag, m);
    }
}


/************************************** DETERMINENT FUNCS *********************************/

static int determinant_aux(matrix_t *m)
{
  int det = 1;
  size_t size = m->size;
  double **matrix = m->matrix;
  for(int i = 0; i < size; ++i)
    {
      det *= matrix[i][i];
    }
  
  return det;
}

int determinant(matrix_t *matrix)
{
  if(matrix == NULL)
    return 0;

  lu_factor(matrix, nthreads);
  int det = determinant_aux(matrix);
  return det;
}

bool is_invertible(matrix_t *matrix)
{
  if(matrix == NULL)
    return false;

  int det = determinant(matrix);
  if(det != 0)
    return true;
  return false;
}
