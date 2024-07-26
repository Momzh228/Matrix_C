# Матрицы на языке C

## Описание

Этот проект представляет собой библиотеку для работы с матрицами на языке C. Библиотека включает функции для создания, удаления, сравнения, арифметических операций и различных математических операций над матрицами. 

## Структура

Структура матрицы определяется следующим образом:

```c
typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
``````
#### Создание матриц 
```c
int s21_create_matrix(int rows, int columns, matrix_t *result);
```

### Очистка матрицы
```c
void s21_remove_matrix(matrix_t *A);
```
### Сравнение матриц
```c
int s21_eq_matrix(matrix_t *A, matrix_t *B);
```
### Сложение матриц
```c
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```
### Вычитание матриц
```c
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```
### Умножение матрицы на число
```c
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
```
### Умножение матриц
```c
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
```
### Транспонирование матрицы
```c
int s21_transpose(matrix_t *A, matrix_t *result);
```
### Вычисление матрицы алгебраических дополнений
```c
int s21_calc_complements(matrix_t *A, matrix_t *result);
```
### Определитель матрицы
```c
int s21_determinant(matrix_t *A, double *result);
```
### Обратная матрица
```c
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
```

# Структура проекта

## Папки и файлы

- **`src`** — папка с исходным кодом библиотеки.
- **`tests`** — папка с unit-тестами.
- **`Makefile`** — файл для сборки проекта.

## Структура Makefile

- **`all`** — сборка всех целей.
- **`clean`** — очистка файлов сборки.
- **`test`** — запуск unit-тестов.
- **`s21_matrix.a`** — сборка статической библиотеки.
- **`gcov_report`** — генерация отчёта покрытия кода тестами в формате HTML.
