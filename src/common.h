#ifndef __COMMON_H__
#define __COMMON_H__

/**
 * @file common.h
 * @author Georgios Davakos 
 * @date 21 mar 2020
 * @brief Shared data structures
 */

typedef struct matrix matrix_t;

struct __attribute__((__packed__)) matrix
{
  int size;
  double **matrix;
};

#endif
