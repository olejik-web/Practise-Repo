#include <stdio.h>

#define NMAX 10

int input(int buffer[], int *length) {
  int error_flag = 1;
  if (scanf("%d", length) != 1) {
    error_flag = 0;
  } else if (*length < 0) {
    error_flag = 0;
  } else if (*length > NMAX) {
    error_flag = 0;
  } else {
    for (int i = 0; i < *length; i++) {
      int num;
      if (scanf("%d", &num) != 1) {
        error_flag = 0;
      } else {
        buffer[i] = num;
      }
    }
  }
  return error_flag;
}

void output(int buffer[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d", buffer[i]);
    if (i < length - 1)
      printf(" ");
  }
}

void make_cycle_shift(int buffer[], int length, int shift_value) {
  int tmp[NMAX];
  shift_value = shift_value * -1;
  if (shift_value >= 0) {
    shift_value = shift_value % length;
  } else {
    shift_value = shift_value + length * (-shift_value / length);
  }
  for (int i = 0; i < length; i++) {
    int new_inx = (i + shift_value);
    if (new_inx >= length)
      new_inx = new_inx % length;
    else if (new_inx < 0)
      new_inx = new_inx + length;
    tmp[new_inx] = buffer[i];
  }
  for (int i = 0; i < length; i++) {
    buffer[i] = tmp[i];
  }
}

int main() {
  int data[NMAX];
  int n;
  if (!input(data, &n)) {
    printf("n/a");
  } else if (n > 0) {
    int c;
    if (scanf("%d", &c) != 1) {
      printf("n/a");
    } else {
      make_cycle_shift(data, n, c);
      output(data, n);
    }
  }
}