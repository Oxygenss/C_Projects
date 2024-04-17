#include "matrix.h"

int inverse_matrix(matrix_t *A, matrix_t *result) {
  if (point_is_null(A) || point_is_null(result)) {
    return INCORRECT_MATRIX;
  } else if (inf_or_nan(A) || A->rows != A->columns) {
    return CALCULATION_ERROR;
  }
  int res = OK;
  double det = 0.;
  determinant(A, &det);

  if (det) {
    det = 1 / det;
    matrix_t complements, transposes;
    calc_complements(A, &complements);
    transpose(&complements, &transposes);

    mult_number(&transposes, det, result);

    remove_matrix(&complements);
    remove_matrix(&transposes);
  } else {
    res = CALCULATION_ERROR;
  }

  return res;
}