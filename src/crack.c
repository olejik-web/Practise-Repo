#include <stdio.h>

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
    while (*get_c != border_sym && *get_c != '\n' && *get_c != ' ') {
        *get_c = getchar();
        if (*get_c != border_sym && *get_c != '\n' && *get_c != ' ') {
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

int get_num(double *x) {
    int c = 'q';
    double bef_point = 0, after_point = 0;
    int after_point_sym_cnt = 0;
    int flag = 1;
    if (!input_element(&bef_point, '.', &c, &after_point_sym_cnt)) flag = 0;
    else {
        if (c == '\n' || c == ' ') {
            *x = bef_point;
        }
        else if (!input_element(&after_point, '\n', &c, &after_point_sym_cnt)) {
            flag = 0;
        }
        else {
            for (int i=0; i<after_point_sym_cnt; i++) {
                after_point = after_point / (double)10;
            }
            *x = bef_point + after_point;
        }
    }
    return flag;
}

int main() {
    double x, y;
    if (!get_num(&x)) {
        printf("n/a");
    }
    else if(!get_num(&y)) {
        printf("n/a");
    }
    else {
        if (x * x + y * y < 25) {
            printf("GOTCHA");
        }
        else {
            printf("MISS");
        }
    }
}