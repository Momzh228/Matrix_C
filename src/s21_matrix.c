#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (rows > 0 && columns > 0) {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      result->rows = rows;
      result->columns = columns;
      for (int i = 0; i < rows; i++) {
        if (!(result->matrix[i] = (double *)calloc(columns, sizeof(double)))) {
          for (int j = 0; j < i; j++) free(result->matrix[j]);
          free(result->matrix);
          error = 2;
        }
      }
    } else
      error = 1;
  } else
    error = 1;
  return error;
}
void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) {
    for (int i = 0; i < A->rows; ++i) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
  }
  A->columns = 0;
  A->rows = 0;
}
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;
  if (A && B && !s21_check_size(A, B) && A->rows > 0 && A->columns > 0) {
    for (int i = 0; i < A->rows && error; ++i) {
      for (int j = 0; j < A->columns && error; ++j) {
        if (fabs((A->matrix[i][j] - B->matrix[i][j])) > 1e-7) {
          error = FAILURE;
        }
      }
    }
  } else
    error = FAILURE;
  return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error;
  if (A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0) {
    error = s21_create_matrix(A->columns, A->rows, result);
    if (error == 0) {
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  } else
    error = 1;
  return error;
}
