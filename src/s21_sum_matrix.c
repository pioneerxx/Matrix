#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (!result) {
    res = CALC_ERROR;
  } else if (check_matrix(A) || check_matrix(B)) {
    res = INCORRECT_MATRIX;
  } else if (!check_size(*A, *B)) {
    res = CALC_ERROR;
  } else {
    clear_matrix(result);
    res = s21_create_matrix(A->rows, A->columns, result);
    if (res == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + (B->matrix[i][j]);
        }
      }
    }
  }
  return res;
}
