#include "matrix.h"

int create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || point_is_null(result)) {
    return INCORRECT_MATRIX;
  }

  result->matrix = (double **)calloc(rows, sizeof(double *));

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
  }

  result->columns = columns;
  result->rows = rows;

  return OK;
}