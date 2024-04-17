#include "matrix.h"

int sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (point_is_null(A) || point_is_null(B) || point_is_null(result)) {
    return INCORRECT_MATRIX;
  } else if (A->columns != B->columns || A->rows != B->rows || inf_or_nan(A) ||
             inf_or_nan(B)) {
    return CALCULATION_ERROR;
  }

  create_matrix(A->rows, A->columns, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return OK;
}
