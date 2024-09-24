#include <stdio.h>

#define NMAX 10

/* int have_evans(int buffer[], int length) {
	int value = 0;
	for (int i = 0; i < length; i++) {
		if (buffer[i] % 2 == 0) {
			value = 1;
		}
	}
	return value;
}

int input(int buffer[], int* length) {
  int error_flag = 1;
  if (scanf("%d", length) != 1) {
    error_flag = 0;
  } else if (*length < 0) {
    error_flag = 0;
  } 
  else if (*length > 10) {
	  error_flag = 0;
  }
  else {
    for (int i = 0; i < *length; i++) {
      int num;
      if (scanf("%d", &num) != 1) {
        error_flag = 0;
      } else {
        buffer[i] = num;
      }
    }
  }
  return error_flag;
}

void output(int buffer[], int length) {
  for (int i = 0; i < length; i++) {
    printf("%d", buffer[i]);
	if (i < length - 1) printf(" ");
  }
}

void find_numbers(int buffer[], int buffer_length, int* numbers_length, int numbers[], int sum)
{
	for (int i = 0; i < buffer_length; i++) {
		if (buffer[i] != 0 && sum % buffer[i] == 0) {
			numbers[*numbers_length] = buffer[i];
			*numbers_length = *numbers_length + 1;
		}
	}
}

int main()
{

	int data[NMAX], length;
	if (!input(data, &length)) {
		printf("n/a");
	}
	else if(!have_evans(data, length)) {
		printf("n/a");
	}
	else {
		int sum = sum_numbers(data, length);
		int numbers[NMAX];
		int cnt = 0;
		find_numbers(data, length, &cnt, numbers, sum);
		printf("%d\n", sum);
		output(numbers, cnt);
	}
}

int sum_numbers(int *buffer, int length)
{
	int sum = 0;
	
	for (int i = 0; i < length; i++)
	{
		if (buffer[i] % 2 == 0)
		{
			sum = sum + buffer[i];
		}
	}
	return sum;
}*/
