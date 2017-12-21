#include "Sort.h"

static void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

static void quickSortSub(int *data, int left, int right) {
	if (left >= right) {
		return;
	}
	int datum = data[left];
	int i = left, j = right;
	while (i < j) {
		while (i < j && data[j] > datum) {
			j--;
		}
		if (i >= j) {
			break;
		}
		swap(&data[i], &data[j]);
		while (i < j && data[i] <= datum) {
			i++;
		}
		if (i >= j) {
			break;
		}
		swap(&data[i], &data[j]);
	}
	quickSortSub(data, left, i - 1);
	quickSortSub(data, i + 1, right);
}

void quickSort(int *data, int size) {
	quickSortSub(data, 0, size - 1);
}