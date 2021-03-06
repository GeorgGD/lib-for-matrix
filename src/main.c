#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix_lib.h"

//TODO: Finish the else part to run performance tests
static void print_matrix(matrix_t *m)
{
  if(m == NULL)
    return;
  int size = m->size;
  for(int i = 0; i < size; ++i)
    {
      for(int j = 0; j < size; ++j)
	{
	  printf("%.4f ", m->matrix[i][j]);
	}
      printf("\n");
    }
}

int main(int argc, char **argv)
{
  if(argc != 4)
    {
      puts("Please only provide the size of the matrix you want to use");
      return 1;
    }
  else
    {
      const int size = atoi(argv[1]);
      const int print = atoi(argv[2]);
      const int num_threads = atoi(argv[3]);
      if(print == 1)
	{
	  matrix_t *matrix = create_empty_matrix(size);
	  random_matrix(matrix);
	  printf("\nThe matrix we are going to LU factorize:\n");
	  print_matrix(matrix);
	  lu_factor(matrix, num_threads);
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
	  matrix_t *matrix = create_empty_matrix(size);
	  random_matrix(matrix);
	  lu_factor(matrix, num_threads);
	  matrix_t *upper_matrix = create_upper_matrix(matrix);
	  matrix_t *lower_matrix = create_lower_matrix(matrix);
	  destroy_matrix(matrix);
	  destroy_matrix(upper_matrix);
	  destroy_matrix(lower_matrix);
	}
    }
  
  return 0;
}
