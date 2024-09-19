/*
Программа, рассчитывающая сумму и произведение введенных чисел
*/

#include <stdio.h>

int sum(int a, int b);
int mul(int a, int b);

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d %d %d %d", x, y, sum(x, y), mul(x, y));
    return 0;
}

int sum(int a, int b){
    return a + b;
}

int mul(int a, int b){
    return a * b;
}
