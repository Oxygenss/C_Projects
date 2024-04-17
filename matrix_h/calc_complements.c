#include "matrix.h"

int calc_complements(matrix_t *A, matrix_t *result) {
  if (point_is_null(A) || point_is_null(result)) {
    return INCORRECT_MATRIX;
  } else if (A->columns != A->rows || inf_or_nan(A)) {
    return CALCULATION_ERROR;
  }

  create_matrix(A->rows, A->columns, result);

  matrix_t minor;
  if (A->rows > 1) {
    create_matrix(A->rows - 1, A->columns - 1, &minor);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        cut_minor_matrix(&minor, *A, i, j);
        determinant(&minor, &result->matrix[i][j]);
        if ((i + j) & 1) {
          result->matrix[i][j] *= -1;
        }
      }
    }
    remove_matrix(&minor);
  } else {
    result->matrix[0][0] = 1.;
  }

  return OK;
}