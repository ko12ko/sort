#include "Sort.h"

static void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void selectionSort(int *data, int size) {
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (data[j] < data[minIndex]) {
				minIndex = j;
			}
		}
		swap(&data[i], &data[minIndex]);
	}
}