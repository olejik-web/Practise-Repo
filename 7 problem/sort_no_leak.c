/* #include <io.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int input(int *data, int n) {
  int error_flag = 1;
  for (int i = 0; i < n; i++) {
    int num;
    if (scanf("%d", &num) != 1) {
      error_flag = 0;
    } else {
      data[i] = num;
    }
  }
  return error_flag;
}

void output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i < n - 1)
      printf(" ");
  }
}

void bubble_sort(int *a, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] < a[j]) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }
}

int check_nums_cnt(int *n) {
  int flag = 1;
  if (scanf("%d", n) != 1) {
    flag = 0;
  } else if (*n <= 0) {
    flag = 0;
  }
  return flag;
}

int main() {
  int n;
  if (!check_nums_cnt(&n)) {
    printf("n/a");
  } else {
    int *data = (int *)calloc(n, sizeof(int));
    if (!input(data, n)) {
      printf("n/a");
    } else {
      bubble_sort(data, n);
      output(data, n);
    }
    free(data);
  }
  return 0;
}*/