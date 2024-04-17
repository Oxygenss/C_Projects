#include "matrix.h"

int determinant(matrix_t *A, double *result) {
  if (point_is_null(A) || result == NULL) {
    return INCORRECT_MATRIX;
  } else if (A->columns != A->rows || inf_or_nan(A)) {
    return CALCULATION_ERROR;
  }
  int sign = 1;
  matrix_t B;
  create_matrix(A->rows, A->columns, &B);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      B.matrix[i][j] = A->matrix[i][j];
    }
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if ((i + j < i + i) && (i != j) && B.matrix[i][j] != 0) {
        if (B.matrix[j][j] == 0) {
          double *tmp = B.matrix[j];
          B.matrix[j] = B.matrix[j + 1];
          B.matrix[j + 1] = tmp;
          sign = -sign;
        }

        double tmp = B.matrix[i][j] / B.matrix[j][j];

        for (int l = j; l < A->columns; l++) {
          B.matrix[i][l] -= tmp * B.matrix[j][l];
        }
      }
    }
  }

  *result = 1;

  for (int i = 0; i < B.rows; i++) {
    *result *= B.matrix[i][i];
  }

  *result *= sign;

  remove_matrix(&B);

  return OK;
}