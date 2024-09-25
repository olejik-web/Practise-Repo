#include <stdio.h>
#include <math.h>

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

void merge(int union_a[], int left_a[], int right_a[], int *left_inx,
           int *right_inx, int *union_inx, int mid, int left, int right) {
  while (*left_inx < mid - left && *right_inx < right - mid) {
    while (*left_inx < mid - left && *right_inx < right - mid &&
           left_a[*left_inx] < right_a[*right_inx]) {
      union_a[*union_inx] = left_a[*left_inx];
      *left_inx = *left_inx + 1;
      *union_inx = *union_inx + 1;
    }
    while (*left_inx < mid - left && *right_inx < right - mid &&
           left_a[*left_inx] == right_a[*right_inx]) {
      union_a[*union_inx] = left_a[*left_inx];
      *union_inx = *union_inx + 1;
      union_a[*union_inx] = left_a[*left_inx];
      *union_inx = *union_inx + 1;
      *left_inx = *left_inx + 1;
      *right_inx = *right_inx + 1;
    }
    while (*left_inx < mid - left && *right_inx < right - mid &&
           left_a[*left_inx] > right_a[*right_inx]) {
      union_a[*union_inx] = right_a[*right_inx];
      *union_inx = *union_inx + 1;
      *right_inx = *right_inx + 1;
    }
  }
  while (*left_inx < mid - left) {
    union_a[*union_inx] = left_a[*left_inx];
    *left_inx = *left_inx + 1;
    *union_inx = *union_inx + 1;
  }
}

void merge_sort(int a[], int l, int r) {
  if (r - l < 2) {
    return;
  }
  int mid = (l + r) / 2;
  int left_a[NMAX];
  int right_a[NMAX];
  for (int i = 0; i < mid - l; i++) {
    left_a[i] = a[i];
  }
  for (int i = 0; i < r - mid; i++) {
    right_a[i] = a[(r - l) / 2 + i];
  }
  merge_sort(left_a, l, mid);
  merge_sort(right_a, mid, r);
  int i = 0;
  int j = 0;
  int union_a[NMAX];
  int union_inx = 0;
  merge(union_a, left_a, right_a, &i, &j, &union_inx, mid, l, r);
  while (j < r - mid) {
    union_a[union_inx] = right_a[j];
    j++;
    union_inx++;
  }
  for (int i = 0; i < r - l; i++) {
    a[i] = union_a[i];
  }
}

void quick_replace(int first[], int second[], int l, int r, int* first_cnt, int* second_cnt) {
    int mid = (l + r) / 2;
    int i = 0;
    int j = 1;
    /* printf("%d %d %d\n", l, r, mid);
    for (int i=0; i<mid - l; i++) printf("%d ", first[i]);
    printf("\n");
    for (int i=0; i<r - mid; i++) printf("%d ", second[i]);
    printf("\n");*/
    int left[NMAX];
    int right[NMAX];
    int left_cnt = 0;
    int right_cnt = 0;
    while (i < mid - l && j < r - mid) {
        while (i < mid - l && first[i] <= second[0]) {
            left[left_cnt] = first[i];
            i++;
            // printf("qqq %d %d\n", i, j);
            left_cnt++;
        }
        while (j < r - mid && i < mid - l && first[i] > second[0] && first[i] >= second[j]) {
            right[right_cnt] = second[j];
            j++;
            right_cnt++;
            // printf("*****");
            /* for (int h=0; h<right_cnt; h++) {
                printf("%d ", right[h]);
            }*/
            // printf("\n");
        }
        while (j < r - mid && i < mid - l && first[i] > second[0] && first[i] < second[j]) {
            right[right_cnt] = first[i];
            i++;
            right_cnt++;
            // printf("q %d %d\n", i, j);
        }
    }
    while (i < mid - l) {
        right[right_cnt] = first[i];
        i++;
        right_cnt++;
    }
    while (j < r - mid) {
        right[right_cnt] = second[j];
        j++;
        right_cnt++;
    }
    *first_cnt = left_cnt;
    *second_cnt = right_cnt + 1;
    // printf("%d %d\n", left_cnt, right_cnt);
    for (int i=0; i<NMAX; i++) first[i] = 0;
    for (int i=0; i<*first_cnt; i++) first[i] = left[i];
    for (int i=1; i<*second_cnt; i++) second[i] = right[i - 1];
    /* for (int i=0; i<left_cnt; i++) printf("%d ", first[i]);
    printf("\n");
    for (int i=0; i<right_cnt + 1; i++) printf("%d ", second[i]);
    printf("\n");*/
}

void quick_sort(int a[], int l, int r) {
    if (r - l < 2) {
        return;
    }
    if (r - l < 3) {
        int value1 = fmin(a[0], a[1]);
        int value2 = fmax(a[0], a[1]);
        a[0] = value1;
        a[1] = value2;
        // printf("%d %d\n", a[0], a[1]);
        return;
    }
    int first[NMAX];
    int second[NMAX];
    int first_cnt = 0;
    int second_cnt = 0;
    int mid = (l + r) / 2;
    for (int i=0; i<mid - l; i++) first[i] = a[i];
    for (int i=0; i<r - mid; i++) second[i] = a[i + mid - l];
    /* for (int i=0; i<mid - l; i++) {
        printf("%d ", first[i]);
    }
    printf("\n");
    for (int i=0; i<r - mid; i++) {
        printf("%d ", second[i]);
    }
    printf("\n");*/
    quick_sort(first, l, mid);
    quick_sort(second, mid, r);
    quick_replace(first, second, l, r, &first_cnt, &second_cnt);
    for (int i=0; i<first_cnt; i++) {
        a[i] = first[i];
    }
    for (int i=0; i<second_cnt; i++) {
        a[i + first_cnt] = second[i];
    }
    /* printf("----> ");
    for (int i=0; i<r - l; i++) printf("%d ", a[i]);
    printf("\n");*/
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
  int merge_sort_data[NMAX];
  int quick_sort_data[NMAX];
  if (!input(data, &n)) {
    printf("n/a");
  } else {
    for (int i = 0; i < n; i++) {
      merge_sort_data[i] = data[i];
      quick_sort_data[i] = data[i];
    }
    merge_sort(merge_sort_data, 0, n);
    output(merge_sort_data, n);
    printf("\n");
    quick_sort(quick_sort_data, 0, n);
    output(quick_sort_data, n);
  }
}