#include <stdio.h>
#define NMAX 10000

int input(int *n, int data[]);
void output(int a[], int n);
void squaring(int a[], int n);

int main() {
    int n, data[NMAX];
    if (!input(&n, data)) {
        printf("n/a");
    } else {
        squaring(data, n);
        output(data, n);
    }

    return 0;
}

int input(int *n, int data[]) {
    int error_flag = 1;
    if (scanf("%d", n) != 1) {
        error_flag = 0;
    } else if (*n < 0) {
        error_flag = 0;
    } else {
        for (int i = 0; i < *n; i++) {
            int num;
            if (scanf("%d", &num) != 1) {
                error_flag = 0;
            } else {
                data[i] = num;
            }
        }
    }
    return error_flag;
}

void output(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
}

void squaring(int a[], int n) {
    for (int i = 0; i < n; i++) a[i] = a[i] * a[i];
}
