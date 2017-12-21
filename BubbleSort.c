#include "Sort.h"

static void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSort(int *data, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				swap(&data[j], &data[j + 1]);
			}
		}
	}
}