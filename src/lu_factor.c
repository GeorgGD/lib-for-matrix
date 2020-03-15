#include <stdio.h>
#include <stdlib.h>
#include "common.h"

matrix_t *create_empty_matrix(int size)
{
  if(size == 0)
    return NULL;
  
  matrix_t *m = malloc(sizeof(matrix_t));
  m->matrix = calloc(size, sizeof(float*));

  for(int i = 0; i < size; ++i)
    {
      m->matrix[i] = calloc(size, sizeof(float));
    }
  m->size = size;
  return m;
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



