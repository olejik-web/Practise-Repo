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
  if (*n <= 0 || *m <= 0 || *n + 1 != *m)
    error_flag = 1;
  return error_flag;
}

void output_matrix(double **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%.6lf", matrix[i][j]);
      if (j < m - 1)
        printf(" ");
    }
    if (i < n - 1)
      printf("\n");
  }
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

void transpose(double **matrix, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      double tmp = matrix[j][i];
      matrix[j][i] = matrix[i][j];
      matrix[i][j] = tmp;
    }
  }
}

void invert(double **matrix, double **result, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      double **det_matrix = malloc((size - 1) * sizeof(double *));
      for (int f = 0; f < size - 1; f++) {
        det_matrix[f] = malloc((size - 1) * sizeof(double));
      }
      int inx = 0;
      for (int a = 0; a < size; a++) {
        if (a == i)
          continue;
        int g = 0;
        for (int b = 0; b < size; b++) {
          if (b == j)
            continue;
          det_matrix[inx][g] = matrix[a][b];
          g++;
        }
        inx++;
      }
      double det_value = det(det_matrix, size - 1, size - 1, 1);
      for (int f = 0; f < size - 1; f++) {
        free(det_matrix[f]);
      }
      free(det_matrix);
      result[i][j] = det_value * pow(-1, i + j);
    }
  }
  double matrix_det = det(matrix, size, size, 1);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      result[i][j] = result[i][j] / matrix_det;
    }
  }
}

void get_roots(double* roots, double** matrix, int n, int m) {
    double matrix_det_value = det(matrix, n, n, 1);
    printf("%.6lf\n", matrix_det_value);
    for (int i=0; i<n; i++) {
        double **root_matrix = malloc(n * sizeof(double *));
        for (int j = 0; j < n; j++) {
            root_matrix[j] = malloc(n * sizeof(double));
        }
        for (int k=0; k<n; k++) {
            root_matrix[k][i] = matrix[k][m - 1];
        }
        for (int k=0; k<n; k++) {
            for (int h=0; h<n; h++) {
                if (h == i) continue;
                root_matrix[k][h] = matrix[k][h];
            }
        }
        double root_matrix_det = det(root_matrix, n, n, 1);
        output_matrix(root_matrix, n, n);
        printf("\n");
        printf("%.6lf\n", root_matrix_det);
        roots[i] = root_matrix_det / matrix_det_value;
    }
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
      if (det(matrix, n, m, 1) == 0) {
        printf("n/a");
      } else {
        double* roots = (double*)malloc(n * sizeof(double));
        get_roots(roots, matrix, n, m);
        for (int i=0; i<n; i++) {
            printf("%.6lf", roots[i]);
            if (i < n - 1) printf(" ");
        }
      }
      for (int i = 0; i < n; i++) {
        free(matrix[i]);
      }
      free(matrix);
    }
  }
  return 0;
}
