#include <stdio.h>
#include <math.h>

double check_c(int c, int *is_num, double value) {
    if (c < 0 || c > 9) {
        *is_num = 0; 
    }
    else {
        value = value * (double)10;
        value = value + (double)c;
    }
    return value;
}

int input_element(double *value, char border_sym, int *get_c, int *after_point_sym_cnt) {
    *get_c = 'q';
    int is_num = 1;
    int have_minus = 0;
    int inx = 0;
    while (*get_c != border_sym && *get_c != '\n') {
        *get_c = getchar();
        if (*get_c != border_sym && *get_c != '\n') {
            if (*get_c == '-' && inx == 0) {
                have_minus = 1;
            }
            else {
                *get_c = *get_c - '0';
                *value = check_c(*get_c, &is_num, *value);
            }
            inx++;
        }
    }
    if (have_minus) *value = *value * -1;
    if (inx == 0) is_num = 0;
    *after_point_sym_cnt = inx;
    return is_num;
}

double import_func(double x) {
    return 7e-3 * pow(x, 4) + ((22.8 * pow(x, 1 / 3) - 1e3) * x + 3) / 
        (x * x / 2) - x * pow(10 + x, 2 / x) - 1.01;
}

int main(void) {
    int c = 'q';
    double x;
    double bef_point = 0, after_point = 0;
    int after_point_sym_cnt = 0;
    if (!input_element(&bef_point, '.', &c, &after_point_sym_cnt)) printf("n/a");
    else {
        if (c == '\n') {
            x = bef_point;
            if (x > -1e-6 && x < 1e-6) printf("n/a");
            else printf("%.1f", round(import_func(x) * 10) / 10);
        }
        else if (!input_element(&after_point, '\n', &c, &after_point_sym_cnt)) {
            printf("n/a");
        }
        else {
            for (int i=0; i<after_point_sym_cnt; i++) {
                after_point = after_point / (double)10;
            }
            x = bef_point + after_point;
            if (x > -1e-6 && x < 1e-6) printf("n/a");
            else printf("%.1f", round(import_func(x) * 10) / 10);
        }
    }
    return 0;
}