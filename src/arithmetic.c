#include <stdio.h>

int get_sum(int a, int b) {
    return a + b;
}

int get_subtract(int a, int b) {
    return a - b;
}

int get_multiply(int a, int b) {
    return a * b;
}

int get_ratio(int a, int b) {
    return a / b;
}

int check_c(int c, int *is_num, int value) {
    if (c < 0 || c > 9) {
        *is_num = 0; 
    }
    else {
        value = value * (double)10;
        value = value + (double)c;
    }
    return value;
}

int input_element(int **value) {
    int c='q';
    int is_num = 1;
    int have_minus = 0;
    int inx = 0;
    while (c != ' ' && c != '\n') {
        c = getchar();
        if (c != ' ' && c != '\n') {
            if (c == '-' && inx == 0) {
                have_minus = 1;
            }
            else {
                c = c - '0';
                **value = check_c(c, &is_num, **value);
            }
            inx++;
        }
    }
    if (have_minus) **value = **value * -1;
    return is_num;
}

int full_input(int *x, int *y) {
    int flag = 1;
    if (!input_element(&x)) flag = 0;
    if (!input_element(&y)) flag = 0;
    return flag;
}

int main(void)
{
    int x, y;
    x = 0;
    y = 0;
    if (!full_input(&x, &y)) printf("n/a");
    else {
        printf("%d ", get_sum(x, y));
        printf("%d ", get_subtract(x, y));
        printf("%d ", get_multiply(x, y));
        if (y != 0) printf("%d ", get_ratio(x, y));
        else printf("n/a");
    }
    return 0;
}