#include <stdio.h>

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

int get_max(int a, int b) {
    int get_value = a;
    if (a < b) {
        get_value = b;
    }
    return get_value;
}

int main(void) {
    int x, y;
    x = 0;
    y = 0;
    if (!full_input(&x, &y)) printf("n/a");
    else printf("%d", get_max(x, y));
    return 0;
}