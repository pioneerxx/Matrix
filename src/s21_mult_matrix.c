#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (!result) {
    res = CALC_ERROR;
  } else if (check_matrix(A) || check_matrix(B)) {
    res = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    res = CALC_ERROR;
  } else {
    clear_matrix(result);
    res = s21_create_matrix(A->rows, B->columns, result);
    if (!res) {
      mult_matrix_cycle(A, B, result);
    }
  }
  return res;
}
