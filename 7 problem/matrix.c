// #include <io.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define NMAX 100

void get_menu() {
	printf("1 - static\n");
	printf("2 - dynamic\n");
	printf("3 - dynamic\n");
	printf("4 - dynamic\n");
}

int get_matrix_method(int *n) {
	int error_flag = 0;
	if (scanf("%d", n) != 1) error_flag = 1;
	if (*n < 1 || *n > 4) error_flag = 1;
	return error_flag;
}

int get_matrix_dim(int* h, int* w) {
	int error_flag = 0;
	if (scanf("%d %d", h, w) != 2) error_flag = 1;
	if (*h <= 0 || *w <= 0 || *h > NMAX || *w > NMAX) error_flag = 1;
	return error_flag;
}

int input_2(int** data, int w, int h) {
	int error_flag = 0;
	int* ptr = (int*)(data + h);
	for (int i = 0; i < h; i++) {
		data[i] = ptr + w * i;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int num;
			if (scanf("%d", &num) != 1) {
				error_flag = 1;
			}
			data[i][j] = num;
		}
	}
	return error_flag;
}

int input_1(int data[NMAX][NMAX], int w, int h) {
	int error_flag = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int num;
			if (scanf("%d", &num) != 1) {
				error_flag = 1;
			}
			data[i][j] = num;
		}
	}
	return error_flag;
}

void output_dynamic_matrix(int **data, int w, int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d", data[i][j]);
			if (j < w - 1) printf(" ");
		}
		if (i < h - 1) printf("\n");
	}
}

void output_matrix(int data[NMAX][NMAX], int w, int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d", data[i][j]);
			if (j < w - 1) printf(" ");
		}
		if (i < h - 1) printf("\n");
	}
}

int main() {
	get_menu();
	int matrix_method;
	int w, h;
	if (get_matrix_method(&matrix_method) || get_matrix_dim(&h, &w)) {
		printf("n/a");
	}
	else {
		if (matrix_method == 1) {
			int data[NMAX][NMAX];
			if (input_1(data, w, h)) printf("n/a");
			else output_matrix(data, w, h);
		}
		if (matrix_method == 2) {
			int** data = malloc(h * w * sizeof(int) + h * sizeof(int*));
			if (input_2(data, w, h)) printf("n/a");
			else output_dynamic_matrix(data, w, h);
			free(data);
		}
	}
}