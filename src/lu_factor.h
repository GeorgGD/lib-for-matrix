#ifndef __EIG_POWER_H__
#define __EIG_POWER_H__

#include "common.h"

matrix_t *create_empty_matrix(int size);

void random_matrix(matrix_t *matrix);

void destroy_matrix(matrix_t *m);

void lu_factor(matrix_t *matrix);

matrix_t *create_upper_matrix(matrix_t *m);

#endif
