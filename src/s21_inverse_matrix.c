#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  double determinant = 0;
  matrix_t calc_complements;
  matrix_t transpont;
  if (!result) {
    res = CALC_ERROR;
  } else if (check_matrix(A)) {
    res = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    res = CALC_ERROR;
  } else {
    clear_matrix(result);
    res = s21_determinant(A, &determinant);
    if (!determinant) {
      res = CALC_ERROR;
    } else if (!res) {
      res = s21_calc_complements(A, &calc_complements);
      if (!res) {
        res = s21_transpose(&calc_complements, &transpont);
        if (!res) {
          res = s21_mult_number(&transpont, 1 / determinant, result);
        } else {
          res = CALC_ERROR;
        }
        s21_remove_matrix(&calc_complements);
      } else {
        res = CALC_ERROR;
      }
      s21_remove_matrix(&transpont);
    }
  }
  return res;
}