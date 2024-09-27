#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/

void bubble_sort(int *a, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (a[i] < a[j]) {
        int c = a[i];
        a[i] = a[j];
        a[j] = c;
      }
    }
  }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
  int *sort_array = (int *)malloc(n * m * sizeof(int));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      *(sort_array + i * m + j) = matrix[i][j];
    }
  }
  bubble_sort(sort_array, n * m);
  for (int i = 0; i < n; i++) {
    result_matrix[i] = malloc(m * sizeof(int));
  }
  int inx = 0;
  for (int j = 0; j < m; j++) {
    if (j % 2 == 0) {
      for (int i = 0; i < n; i++) {
        result_matrix[i][j] = sort_array[inx];
        inx++;
      }
    } else {
      for (int i = n - 1; i > -1; i--) {
        result_matrix[i][j] = sort_array[inx];
        inx++;
      }
    }
  }
  free(sort_array);
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
  int *sort_array = (int *)malloc(n * m * sizeof(int));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      *(sort_array + i * m + j) = matrix[i][j];
    }
  }
  bubble_sort(sort_array, n * m);
  for (int i = 0; i < n; i++) {
    result_matrix[i] = malloc(m * sizeof(int));
  }
  int inx = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < m; j++) {
        result_matrix[i][j] = sort_array[inx];
        inx++;
      }
    } else {
      for (int j = m - 1; j > -1; j--) {
        result_matrix[i][j] = sort_array[inx];
        inx++;
      }
    }
  }
  free(sort_array);
}

int input_dim(int *n, int *m) {
  int error_flag = 0;
  if (scanf("%d %d", n, m) != 2) {
    error_flag = 1;
  }
  if (*n <= 0 || *m <= 0)
    error_flag = 1;
  return error_flag;
}

int input_matrix(int **matrix, const int *n, const int *m) {
  int error_flag = 0;
  for (int i = 0; i < *n; i++) {
    matrix[i] = malloc(*m * sizeof(int));
  }
  for (int i = 0; i < *n; i++) {
    for (int j = 0; j < *m; j++) {
      int num;
      if (scanf("%d", &num) != 1) {
        error_flag = 1;
      }
      matrix[i][j] = num;
    }
  }
  return error_flag;
}

void output_matrix(int **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d", matrix[i][j]);
      if (j < m - 1)
        printf(" ");
    }
    if (i < n - 1)
      printf("\n");
  }
}

int main() {
  int n, m;

  if (input_dim(&n, &m)) {
    printf("n/a");
  } else {
    int **matrix = malloc(n * sizeof(int *));
    if (input_matrix(matrix, &n, &m)) {
      printf("n/a");
    } else {
      int **result = malloc(n * sizeof(int *));
      sort_vertical(matrix, n, m, result);
      output_matrix(result, n, m);
      printf("\n\n");
      int **result2 = malloc(n * sizeof(int *));
      ;
      sort_horizontal(matrix, n, m, result2);
      output_matrix(result2, n, m);
      for (int i = 0; i < n; i++) {
        free(matrix[i]);
        free(result[i]);
        free(result2[i]);
      }
      free(matrix);
      free(result);
      free(result2);
    }
  }
  return 0;
}
