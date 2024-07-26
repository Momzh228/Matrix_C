#include "s21_matrix.h"

int s21_check_size(matrix_t* matrix_1, matrix_t* matrix_2) {
  int error = 0;
  if (matrix_1 != NULL && matrix_2 != NULL) {
    if ((matrix_1->rows != matrix_2->rows) ||
        (matrix_1->columns != matrix_2->columns))
      error = 1;
  } else
    error = 1;
  return error;
}

int s21_check_correct(matrix_t* matrix_1, matrix_t* matrix_2) {
  int error = 0;
  if (matrix_1 != NULL && matrix_2 != NULL) {
    if (matrix_1->rows < 1 || matrix_1->columns < 1 || matrix_2->rows < 1 ||
        matrix_2->columns < 1 || matrix_1->matrix == NULL ||
        matrix_2->matrix == NULL)
      error = 1;
  } else
    error = 1;
  return error;
}

void s21_minor(int rows, int columns, matrix_t* A, matrix_t* M) {
  int rows_m = 0;
  int columns_m = 0;
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      if (j != columns && i != rows) {
        M->matrix[rows_m][columns_m] = A->matrix[i][j];
        columns_m++;
        if (columns_m == A->columns - 1) {
          rows_m++;
          columns_m = 0;
        }
      }
    }
  }
}