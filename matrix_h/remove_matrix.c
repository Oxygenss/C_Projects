#include "matrix.h"

void remove_matrix(matrix_t *A) {
  if (A != NULL && A->columns > 0 && A->rows > 0) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
  }
  A->columns = 0;
  A->rows = 0;
}
