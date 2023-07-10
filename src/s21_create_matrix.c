#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = OK;
  if (!result) {
    res = INCORRECT_MATRIX;
  } else if (rows < 1 || columns < 1) {
    res = INCORRECT_MATRIX;
  } else {
    clear_matrix(result);
    result->matrix = calloc((size_t)rows, sizeof(double *));
    if (!result->matrix) {
      res = INCORRECT_MATRIX;
    } else {
      create_cycle(result, rows, columns, &res);
    }
  }
  return res;
}