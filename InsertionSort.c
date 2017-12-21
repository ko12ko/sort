#include "Sort.h"

void insertingSort(int *data, int size) {
	for (int i = 1; i < size; i++) {
		int currentValue = data[i];
		int j;
		for (j = i; j > 0; j--) {
			if (currentValue < data[j - 1]) {
				data[j] = data[j - 1];
			}
			else {
				data[j] = currentValue;
				break;
			}
		}
		if (j == 0) {
			data[j] = currentValue;
		}
	}
}