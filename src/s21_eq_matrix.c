#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int res = SUCCESS;
  if (A->columns != B->columns || A->rows != B->rows) {
    res = FAILURE;
  } else if (A->columns < 1 || A->rows < 1 || B->columns < 1 || B->rows < 1) {
    res = FAILURE;
  } else if (check_matrix(A) || check_matrix(B)) {
    res = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          res = FAILURE;
          break;
        }
      }
    }
  }
  return res;
}