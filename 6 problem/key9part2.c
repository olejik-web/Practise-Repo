#include <stdio.h>
#include <math.h>

#define INPUT_LEN 100
#define REAL_LEN 110

/* void make_cycle_shift(int buffer[], int length, int shift_value) {
    int tmp[REAL_LEN];
    if (shift_value >= 0) {
        shift_value = shift_value % length;
    }
    else {
        shift_value = shift_value + length * (-shift_value / length);
    }
    for (int i = 0; i < length; i++) {
        int new_inx = (i + shift_value);
        if (new_inx >= length) new_inx = new_inx % length;
        else if (new_inx < 0) new_inx = new_inx + length;
        tmp[new_inx] = buffer[i];
    }
    for (int i = 0; i < length; i++) {
        buffer[i] = tmp[i];
    }
}

void init_num(int num[]) {
    for (int i = 0; i < REAL_LEN; i++) {
        num[i] = 0;
    }
}

void output_num(int num[], int digit_cnt) {
    int inx = digit_cnt - 1;
    for (int i = 0; i < digit_cnt - 1; i++) {
        if (num[i] != 0) {
            inx = i;
            break;
        }
    }
    for (int i = inx; i < digit_cnt; i++) {
        printf("%d ", num[i]);
    }
}

void sum(int buff1[], int len1, int buff2[], int len2, int result[], int* result_length) {
    if (len1 - len2 > 0) make_cycle_shift(buff2, REAL_LEN, len1 - len2);
    if (len2 - len1 > 0) make_cycle_shift(buff1, REAL_LEN, len2 - len1);
    int d = 0;
    *result_length = (int)fmax(len2, len1);
    for (int i = (int)fmax(len2, len1) - 1; i > -1; i--) {
        int h = buff1[i] + buff2[i] + d;
        result[i] = h % 10;
        d = h / 10;
    }
    if (d > 0) {
        make_cycle_shift(result, REAL_LEN, 1);
        result[0] = d;
        *result_length = *result_length + 1;
    }
}

int more(int num1[], int len1, int num2[], int len2) {
    int what_is = 3;
    for (int i = 0; i < (int)fmax(len1, len2); i++) {
        if (what_is < 3) break;
        int value1 = num1[i];
        int value2 = num2[i];
        if (num1[i] < num2[i]) {
            what_is = 2;
        }
        if (num1[i] > num2[i]) {
            what_is = 1;
        }
    }
    return what_is;
}

int sub(int buff1[], int len1, int buff2[], int len2, int result[], int* result_length) {
    int what_is = more(buff1, len1, buff2, len2);
    int decis[REAL_LEN];
    init_num(decis);
    if (what_is == 1) {
        for (int i = fmax(len1, len2) - 1; i > -1; i--) {
            if (buff1[i] + decis[i] < buff2[i]) {
                int inx = i - 1;
                while (inx > -1 && buff1[inx] < buff2[inx]) {
                    inx--;
                }
                buff1[inx] = buff1[inx] - 1;
                for (int j = inx + 1; j < i; j++) {
                    decis[j] = 9;
                }
                decis[i] = 10;
            }
            result[i] = buff1[i] + decis[i] - buff2[i];
        }
    }
    else *result_length = 1;
    *result_length = (int)fmax(len1, len2);
    return what_is;
}

int input_num(int num[], int *digit_cnt) {
    int digit = 0;
    char c = 'q';
    int error_flag = 0;
    while (c != '\n' && *digit_cnt < INPUT_LEN) {
        if (scanf("%d%c", &num[*digit_cnt], &c) != 2) {
            error_flag = 1;
        }
        if (num[*digit_cnt] < 0 || num[*digit_cnt] > 9) {
            error_flag = 1;
        }
        *digit_cnt = *digit_cnt + 1;
    }
    return error_flag;
}

int main()
{
    int num1[REAL_LEN];
    int num1_digit_cnt = 0;
    init_num(num1);
    int num2[REAL_LEN];
    int num2_digit_cnt = 0;
    init_num(num2);
    int num1_is_error = input_num(num1, &num1_digit_cnt);
    int num2_is_error = input_num(num2, &num2_digit_cnt);
    if (num1_is_error || num2_is_error) {
        printf("n/a");
    }
    else {
        int sum_num[REAL_LEN];
        int sum_num_digit_cnt = 0;
        init_num(sum_num);
        sum(num1, num1_digit_cnt, num2, num2_digit_cnt, sum_num, &sum_num_digit_cnt);
        output_num(sum_num, sum_num_digit_cnt);
        printf("\n");
        int sub_num[REAL_LEN];
        int sub_num_digit_cnt = 0;
        init_num(sub_num);
        if (sub(num1, num1_digit_cnt, num2, num2_digit_cnt, sub_num, &sub_num_digit_cnt) == 2) {
            printf("n/a");
        }
        else {
            output_num(sub_num, sub_num_digit_cnt);
        }
    }
}
*/
