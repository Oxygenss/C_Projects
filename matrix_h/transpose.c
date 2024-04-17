#include "matrix.h"

int transpose(matrix_t *A, matrix_t *result) {
  if (point_is_null(A) || point_is_null(result)) {
    return INCORRECT_MATRIX;
  }

  create_matrix(A->columns, A->rows, result);

  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }

  return OK;
}
