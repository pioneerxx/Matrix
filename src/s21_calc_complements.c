#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  matrix_t minor;
  double temp = 0;
  if (!result) {
    res = CALC_ERROR;
  } else if (check_matrix(A)) {
    res = INCORRECT_MATRIX;
  } else if (A->rows == 1 || A->columns == 1) {
    res = CALC_ERROR;
  } else if (A->rows != A->columns) {
    res = CALC_ERROR;
  } else {
    clear_matrix(result);
    res = s21_create_matrix(A->rows, A->columns, result);
    if (res == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          minor = minority(i, j, A);
          s21_determinant(&minor, &temp);
          result->matrix[i][j] = pow(-1, j + i + 2) * temp;
          s21_remove_matrix(&minor);
        }
      }
    } else {
      res = INCORRECT_MATRIX;
    }
  }
  return res;
}