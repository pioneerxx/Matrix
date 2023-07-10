#include "s21_matrix.h"

matrix_t minority(int i, int j, matrix_t *A) {
  matrix_t klava_koka;
  s21_create_matrix(A->rows - 1, A->columns - 1, &klava_koka);
  int k = 0;
  int m = 0;
  for (int l = 0; l < A->rows; l++) {
    for (int n = 0; n < A->columns; n++) {
      if (n != j && l != i) {
        klava_koka.matrix[k][m] = A->matrix[l][n];
        m++;
        if (m == A->columns - 1) {
          k++;
          m = 0;
        }
      }
    }
  }
  return klava_koka;
}

int check_matrix(matrix_t *A) {
  int res = OK;
  if (A->columns < 1 || A->rows < 1 || A->matrix == NULL || !A) {
    res = INCORRECT_MATRIX;
  }
  return res;
}

void clear_matrix(matrix_t *A) {
  A->matrix = NULL;
  A->columns = 0;
  A->rows = 0;
}

int check_size(matrix_t A, matrix_t B) {
  int res = 0;
  if (A.columns == B.columns && A.rows == B.rows) res = 1;
  return res;
}

void mult_matrix_cycle(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < B->rows; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
}

void create_cycle(matrix_t *result, int rows, int columns, int *res) {
  result->rows = rows;
  result->columns = columns;
  for (int i = 0; i < result->rows; i++) {
    result->matrix[i] = calloc((size_t)columns, sizeof(double));
    if (result->matrix[i] == NULL) {
      s21_remove_matrix(result);
      *res = INCORRECT_MATRIX;
      break;
    }
  }
}