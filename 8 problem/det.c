#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n, int m, int j) {
  if (n < 2)
    return matrix[0][0];
  if (n < 3) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  }
  double det_value = 0;
  for (int a = 0; a < n; a++) {
    double new_n = n - 1;
    double new_m = m - 1;
    double **new_matrix = malloc(new_n * sizeof(double *));
    for (int i = 0; i < new_n; i++) {
      new_matrix[i] = malloc(new_m * sizeof(double));
    }
    int inx = 0;
    for (int q = 0; q < n; q++) {
      if (q == a)
        continue;
      for (int h = 1; h < m; h++) {
        new_matrix[inx][h - 1] = matrix[q][h];
      }
      inx++;
    }
    double g = det(new_matrix, new_n, new_m, j + 1) * pow(-1, 2 * j + a);
    det_value = det_value + matrix[a][0] * g;
    for (int i = 0; i < new_n; i++) {
      free(new_matrix[i]);
    }
    free(new_matrix);
  }
  return det_value;
}

int input_dim(int *n, int *m) {
  int error_flag = 0;
  if (scanf("%d %d", n, m) != 2) {
    error_flag = 1;
  }
  if (*n <= 0 || *m <= 0 || *n != *m)
    error_flag = 1;
  return error_flag;
}

int input_matrix(double **matrix, const int *n, const int *m) {
  int error_flag = 0;
  for (int i = 0; i < *n; i++) {
    matrix[i] = malloc(*m * sizeof(double));
  }
  for (int i = 0; i < *n; i++) {
    for (int j = 0; j < *m; j++) {
      double num;
      if (scanf("%lf", &num) != 1) {
        error_flag = 1;
      }
      matrix[i][j] = num;
    }
  }
  return error_flag;
}

int main() {
  int n, m;

  if (input_dim(&n, &m)) {
    printf("n/a");
  } else {
    double **matrix = malloc(n * sizeof(double *));
    if (input_matrix(matrix, &n, &m)) {
      printf("n/a");
    } else {
      printf("%.6lf", det(matrix, n, m, 1));
      for (int i = 0; i < n; i++) {
        free(matrix[i]);
      }
      free(matrix);
    }
  }
  return 0;
}
