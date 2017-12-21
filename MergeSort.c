#include "Sort.h"
#include <stdlib.h>

void mergeSort(int *data, int size) {
	if (size == 1) {
		return;
	}

	mergeSort(data, size / 2);
	mergeSort(data + size / 2, (size + 1) / 2);

	int *buffer = malloc(size * sizeof(int));
	int i = 0, j = size / 2, k = 0;
	while (i < size / 2 && j < size) {
		if (data[i] < data[j]) {
			buffer[k++] = data[i++];
		}
		else {
			buffer[k++] = data[j++];
		}
	}
	for (; i < size / 2; i++) {
		buffer[k++] = data[i];
	}
	for (; j < size; j++) {
		buffer[k++] = data[j];
	}
	for (k = 0; k < size; k++) {
		data[k] = buffer[k];
	}
	free(buffer);
}