#include <stdio.h>

#define NMAX 10

int input(int data[], int* n) {
    int error_flag = 1;
    *n = 10;
    for (int i = 0; i < *n; i++) {
        int num;
        if (scanf("%d", &num) != 1) {
            error_flag = 0;
        }
        else {
            data[i] = num;
        }
    }
    return error_flag;
}

void output(int a[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
}

void merge(int union_a[], int left_a[], int right_a[], 
    int *left_inx, int *right_inx, int *union_inx, int mid, int left, int right) {
    while (*left_inx < mid - left && *right_inx < right - mid) {
        while (*left_inx < mid - left && *right_inx < right - mid 
            && left_a[*left_inx] < right_a[*right_inx]) {
            union_a[*union_inx] = left_a[*left_inx];
            *left_inx = *left_inx + 1;
            *union_inx = *union_inx + 1;
        }
        while (*left_inx < mid - left && *right_inx < right - mid && left_a[*left_inx] == right_a[*right_inx]) {
            union_a[*union_inx] = left_a[*left_inx];
            *union_inx = *union_inx + 1;
            union_a[*union_inx] = left_a[*left_inx];
            *union_inx = *union_inx + 1;
            *left_inx = *left_inx + 1;
            *right_inx = *right_inx + 1;
        }
        while (*left_inx < mid - left && *right_inx < right - mid && left_a[*left_inx] > right_a[*right_inx]) {
            union_a[*union_inx] = right_a[*right_inx];
            *union_inx = *union_inx + 1;
            *right_inx = *right_inx + 1;
        }
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
    while (i < mid - l) {
        union_a[union_inx] = left_a[i];
        i++;
        union_inx++;
    }
    while (j < r - mid) {
        union_a[union_inx] = right_a[j];
        j++;
        union_inx++;
    }
    for (int i = 0; i < r - l; i++) {
        a[i] = union_a[i];
    }
}

void bubble_sort(int a[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
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
    int bubble_sort_data[NMAX];
    int merge_sort_data[NMAX];
    if (!input(data, &n)) {
        printf("n/a");
    } 
    else {
        output(data, n);
        printf("\n");
        for (int i = 0; i < n; i++) {
            bubble_sort_data[i] = data[i];
            merge_sort_data[i] = data[i];
        }
        bubble_sort(bubble_sort_data, n);
        output(bubble_sort_data, n);
        printf("\n");
        merge_sort(merge_sort_data, 0, n);
        output(merge_sort_data, n);
        printf("\n");
    }
}