#ifndef __COMMON_H__
#define __COMMON_H__

typedef struct matrix matrix_t;

struct __attribute__((__packed__)) matrix
{
  int size;
  double **matrix;
};

#endif
