#include "matrix.h"

int eq_matrix(matrix_t *A, matrix_t *B) {
  if (A->columns != B->columns || A->rows != B->rows || point_is_null(A) ||
      point_is_null(B)) {
    return FAILURE;
  }
  int status = SUCCESS;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 0.0000001) {
        status = FAILURE;
        i = A->rows;
        j = A->columns;
      }
    }
  }

  return status;
}
