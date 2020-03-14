#include "eig_power.h"

typedef struct matrix matrix_t;

struct matrix
{
  double **matrix;
};

//TODO: create a "N x N" sparse matrix
static matrix_t *create_matrix_k(int size)
{
  matrix_t *m = malloc(sizeof(matrix_t));
  m->matrix = malloc(size * sizeof(double*));
}
