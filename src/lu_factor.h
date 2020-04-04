#ifndef __EIG_POWER_H__
#define __EIG_POWER_H__

/**
 * @file lu_factor.h
 * @author Georgios Davakos
 * @date 21 mar 2020
 * @brief A program that performs the LU-factorization
 */

typedef struct matrix matrix_t;

struct __attribute__((__packed__)) matrix
{
  int size;
  double **matrix;
};


/**
 * @brief creates an empty square matrix
 * @param size - the size of the matrix
 * @return pointer to empty square matrix
 */
matrix_t *create_empty_matrix(int size);

/**
 * @brief gives the matrix new and random values
 * @param matrix - a matrix
 */
void random_matrix(matrix_t *matrix);

/**
 * @brief deallocates a matrix
 * @param m - a matrix
 */
void destroy_matrix(matrix_t *m);

/**
 * @brief LU-factorization of a given matrix
 * @param matrix - a matrix
 * @param num_threads - the number of threads
 */
void lu_factor(matrix_t *matrix, int num_threads);

/**
 * @brief the upper triangle of a given matrix
 * @param m - matrix
 * @return the upper triangle of a given matrix
 */
matrix_t *create_upper_matrix(matrix_t *m);

/**
 * @brief the lower triangle of a given matrix
 * @param m - matrix
 * @return the lower triangle of a given matrix
 */
matrix_t *create_lower_matrix(matrix_t *m);

int determinant(matrix_t *matrix);

bool is_matrix_invertible(matrix_t *matrix);

#endif
