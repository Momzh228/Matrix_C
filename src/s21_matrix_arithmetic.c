#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (A != NULL && B != NULL) {
    if (s21_check_size(A, B)) error = 2;
    if (s21_check_correct(A, B)) error = 1;
    if (!error) {
      error = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  } else
    error = 1;
  return error;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  if (s21_check_size(A, B)) error = 2;
  if (s21_check_correct(A, B)) error = 1;
  if (A != NULL && B != NULL && !error) {
    error = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  if (A == NULL || B == NULL) error = 1;
  return error;
}
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = 0;
  if (!(A != NULL && A->matrix != NULL && A->rows > 0 && A->columns > 0))
    error = 1;
  if (!error) {
    error = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return error;
}
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error;
  error = s21_check_correct(A, B);
  if (!error)
    if (A->columns != B->rows) error = 2;
  if (!error) {
    error = s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < B->columns; ++j) {
        for (int g = 0; g < B->rows; g++) {
          result->matrix[i][j] += A->matrix[i][g] * B->matrix[g][j];
        }
      }
    }
  }
  return error;
}