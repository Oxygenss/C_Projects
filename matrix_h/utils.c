#include "matrix.h"

int inf_or_nan(matrix_t* A) {
  int res = OK;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
        res = 1;
        i = A->rows;
        j = A->columns;
      }
    }
  }

  return res;
}

int point_is_null(matrix_t* A) { return A == NULL; }

void cut_minor_matrix(matrix_t* minor, matrix_t A, int row, int col) {
  for (int i = 0, m = 0; i < A.rows; i++) {
    for (int j = 0, n = 0; j < A.columns; j++) {
      if (i != row && j != col) {
        minor->matrix[m][n] = A.matrix[i][j];
        n++;

        if (n == minor->columns) {
          m++;
          n = 0;
        }
      }
    }
  }
}
