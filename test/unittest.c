#include <string.h>
#include <stdbool.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include "../src/matrix_lib.h"

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
  int size = 2;
  matrix_t *matrix = create_empty_matrix(size);
  random_matrix(matrix);
  CU_ASSERT_EQUAL(inspect_matrix(matrix, 0, 0), 4.0);
  CU_ASSERT_EQUAL(inspect_matrix(matrix, 0, 1), -2.0);
  CU_ASSERT_EQUAL(inspect_matrix(matrix, 1, 0), -2.0);
  CU_ASSERT_EQUAL(inspect_matrix(matrix, 1, 1), 2.0);
  
  destroy_matrix(matrix);
}

void test_lu_factor()
{
  int size = 2;
  matrix_t *matrix = create_empty_matrix(size);
  random_matrix(matrix);
  lu_factor(matrix, 1);
  CU_ASSERT_EQUAL(inspect_matrix(matrix, 0, 0), 4.0);
  CU_ASSERT_EQUAL(inspect_matrix(matrix, 0, 1), -0.5);
  CU_ASSERT_EQUAL(inspect_matrix(matrix, 1, 0), -2.0);
  CU_ASSERT_EQUAL(inspect_matrix(matrix, 1, 1), 1.0);
  
  destroy_matrix(matrix);
}

void test_upper_matrix()
{
  int size = 4;
  matrix_t *matrix = create_empty_matrix(size);
  random_matrix(matrix);
  lu_factor(matrix, 1);
  matrix_t * upper_matrix = create_upper_matrix(matrix);
  CU_ASSERT_EQUAL(inspect_matrix(upper_matrix, 0, 0), 4.0);
  CU_ASSERT_EQUAL(inspect_matrix(upper_matrix, 0, 1), -0);
  CU_ASSERT_EQUAL(inspect_matrix(upper_matrix, 1, 1), 3.0);
  CU_ASSERT_EQUAL(inspect_matrix(upper_matrix, 2, 1), -2.0);
  
  destroy_matrix(matrix);
  destroy_matrix(upper_matrix);
}

void test_lower_matrix()
{
  int size = 4;
  matrix_t *matrix = create_empty_matrix(size);
  random_matrix(matrix);
  lu_factor(matrix, 1);
  matrix_t * lower_matrix = create_lower_matrix(matrix);
  CU_ASSERT_EQUAL(inspect_matrix(lower_matrix, 0, 0), 1.0);
  CU_ASSERT_EQUAL(inspect_matrix(lower_matrix, 0, 1), -0.5);
  CU_ASSERT_EQUAL(inspect_matrix(lower_matrix, 1, 1), 1.0);
  CU_ASSERT_EQUAL(inspect_matrix(lower_matrix, 1, 2), -2.0/3.0);
  CU_ASSERT_EQUAL(inspect_matrix(lower_matrix, 1, 3), 0);

  destroy_matrix(matrix);
  destroy_matrix(lower_matrix);
}

void test_determinant()
{
  int size = 4;
  matrix_t *matrix = create_empty_matrix(size);
  random_matrix(matrix);
  int det = determinant(matrix);
  CU_ASSERT_EQUAL(det, 16);
  destroy_matrix(matrix);

  size = 3;
  matrix = create_empty_matrix(size);
  random_matrix(matrix);
  det = determinant(matrix);
  CU_ASSERT_EQUAL(det, 8);
  destroy_matrix(matrix);
}

void test_if_invertible()
{
  int size = 4;
  matrix_t *matrix = create_empty_matrix(size);
  random_matrix(matrix);
  CU_ASSERT_TRUE(is_invertible(matrix));
  destroy_matrix(matrix);

  size = 3;
  matrix = create_empty_matrix(size);
  random_matrix(matrix);
  CU_ASSERT_TRUE(is_invertible(matrix));
  destroy_matrix(matrix);
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
      (NULL == CU_add_test(test_suite1, "Test create matrix", test_create_matrix)) ||
      (NULL == CU_add_test(test_suite1, "Test LU factorization", test_lu_factor)) ||
      (NULL == CU_add_test(test_suite1, "Test upper matrix", test_upper_matrix)) ||
      (NULL == CU_add_test(test_suite1, "Test lower matrix", test_lower_matrix)) ||
      (NULL == CU_add_test(test_suite1, "Test determinant", test_determinant)) ||
      (NULL == CU_add_test(test_suite1, "Test if invertible", test_if_invertible))
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
