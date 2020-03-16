#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "lu_factor.h"

static void print_matrix(matrix_t *m)
{
  if(m == NULL)
    return;
  int size = m->size;
  for(int i = 0; i < size; ++i)
    {
      for(int j = 0; j < size; ++j)
	{
	  printf("%f ", m->matrix[i][j]);
	}
      printf("\n");
    }
}

int main(int argc, char **argv)
{
  if(argc != 3)
    {
      puts("Please only provide the size of the matrix you want to use");
      return 1;
    }
  else
    {
      const int size = atoi(argv[1]);
      const int print = atoi(argv[2]);

      if(print == 1)
	{
	  matrix_t *matrix = create_empty_matrix(size);
	  random_matrix(matrix);
	  printf("\nThe matrix we are going to LU factorize:\n");
	  print_matrix(matrix);
	  lu_factor(matrix);
	  matrix_t *upper_matrix = create_upper_matrix(matrix);
	  matrix_t *lower_matrix = create_lower_matrix(matrix);
	  printf("\nThe upper matrix: \n");
	  print_matrix(upper_matrix);
	  printf("\nThe lower matrix: \n");
	  print_matrix(lower_matrix);

	  destroy_matrix(matrix);
	  destroy_matrix(upper_matrix);
	  destroy_matrix(lower_matrix);
	}
      else
	{
	  
	}
    }
  
  return 0;
}
