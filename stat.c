#include <math.h>
#include <stdio.h>
#define NMAX 10000

int max(int a[], int n) {
    int value = a[0];
    for (int i = 0; i < n; i++) {
        value = max(value, a[i]);
    }
    return value;
}

int min(int a[], int n) {
    int value = a[0];
    for (int i = 0; i < n; i++) {
        value = min(value, a[i]);
    }
    return value;
}

double mean(int a[], int n, int pow_value) {
    double p = 1 / (double)n;
    double value = 0;
    for (int i = 0; i < n; i++) {
        value = value + p * pow(a[i], pow_value);
    }
    return value;
}

void squaring(int a[], int n) {
    for (int i = 0; i < n; i++) a[i] = a[i] * a[i];
}

double variance(int a[], int n) {
    double sqr_mean = mean(a, n, 1) * mean(a, n, 1);
    double spec_mean = mean(a, n, 2);
    double value = spec_mean - sqr_mean;
    return value;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %f %f", max_v, min_v, mean_v, variance_v);
}

int input(int data[], int *n) {
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
        printf("%d ", a[i]);
    }
}

int main() {
    int n, data[NMAX];
    if (!input(data, &n)) {
        printf("n/a");
    } else {
        output(data, n);
        printf("\n");
        output_result(max(data, n), min(data, n), mean(data, n, 1), variance(data, n));
    }
    return 0;
}
