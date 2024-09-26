#include <stdio.h>

#define NMAX 10

int input(int data[], int *n) {
  int error_flag = 1;
  *n = 10;
  for (int i = 0; i < *n; i++) {
    int num;
    if (scanf("%d", &num) != 1) {
      error_flag = 0;
    } else {
      data[i] = num;
    }
  }
  return error_flag;
}

void output(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i < n - 1)
      printf(" ");
  }
}

void bubble_sort(int a[], int n) {
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

int main() {
  int data[NMAX], n;
  if (!input(data, &n)) {
    printf("n/a");
  } else {
    bubble_sort(data, n);
    output(data, n);
  }
}