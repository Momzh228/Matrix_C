#include "s21_matrix.h"
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;
  matrix_t M = {0};
  if (A == NULL || result == NULL || A->rows < 1 || A->columns < 1)
    error = 1;
  else if ((A->columns != A->rows) || A->rows == 1)
    error = 2;
  if (!error) {
    error = s21_create_matrix(A->rows - 1, A->columns - 1, &M);
  }
  if (!error) {
    error = s21_create_matrix(A->rows, A->columns, result);
    if (!error) {
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          double d = 0;
          s21_minor(i, j, A, &M);
          s21_determinant(&M, &d);
          result->matrix[i][j] = d * pow(-1, i + j);
        }
      }
    }
    s21_remove_matrix(&M);
  }
  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  int error = 0;
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1)
    error = 1;
  else if (A->rows != A->columns)
    error = 2;
  if (!error) {
    if (A->rows == 1) *result = A->matrix[0][0];
    if (A->rows == 2) {
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    }
    if (A->rows > 2) {
      for (int i = 0; i < A->rows; i++) {
        matrix_t M = {0};
        error = s21_create_matrix(A->rows - 1, A->columns - 1, &M);
        s21_minor(0, i, A, &M);
        double temp = 0;
        s21_determinant(&M, &temp);
        *result += pow(-1.0, i) * temp * A->matrix[0][i];
        s21_remove_matrix(&M);
      }
    }
  }
  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  double d = 0;
  if (A == NULL || A->matrix == NULL) error = 1;
  if (!error) {
    error = s21_determinant(A, &d);
    if (d == 0) error = 2;
  }
  if (!error) {
    if (A->rows == 1) {
      error = s21_create_matrix(1, 1, result);
      if (!error) result->matrix[0][0] = 1.0 / A->matrix[0][0];
    } else {
      matrix_t G = {0};
      s21_calc_complements(A, &G);
      matrix_t G_trans = {0};
      s21_transpose(&G, &G_trans);
      s21_mult_number(&G_trans, 1 / d, result);
      s21_remove_matrix(&G_trans);
      s21_remove_matrix(&G);
    }
  }
  return error;
}