#include "matrix.h"

int mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (point_is_null(A) || point_is_null(B) || point_is_null(result)) {
    return INCORRECT_MATRIX;
  } else if (A->columns != B->rows || inf_or_nan(A) || inf_or_nan(B)) {
    return CALCULATION_ERROR;
  }

  create_matrix(A->rows, B->columns, result);

  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return OK;
}
