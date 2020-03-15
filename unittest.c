#include <string.h>
#include <stdbool.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include "common.h"
#include "eig_power.h"

int init_suite(void)
{
  return 0;
}

int clean_suite(void)
{
  return 0;
}

double inspect_matrix(matrix_t *matrix, int index_x, int index_y)
{
  double value = matrix->matrix[index_y][index_x];
  return value;
}

void test_create_matrix()
{
  int size = 4;
  matrix_t *matrix = create_matrix(size);
  create_matrix_k(matrix);
  CU_ASSERT_EQUAL(inspect_matrix(matrix, 1, 1), 2.0);
  CU_ASSERT_EQUAL(inspect_matrix(matrix, 1, 2), -1.0);
  CU_ASSERT_EQUAL(inspect_matrix(matrix, 1, 0), -1.0);
  CU_ASSERT_EQUAL(inspect_matrix(matrix, 3, 3), 1.0);

}

int main()
{
  CU_pSuite test_suite1 = NULL;
  
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  test_suite1 = CU_add_suite("Test Suite 1", init_suite, clean_suite);
  if (NULL == test_suite1)
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  if (
      (NULL == CU_add_test(test_suite1, "Test create matrix", test_create_matrix))
      )
    {
      CU_cleanup_registry();
      return CU_get_error();
    }
     
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
