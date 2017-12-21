#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Sort.h"

int main() {
	
	int size = 6;
	int maxValue = 100;
	int *data;

	data = (int *)malloc(size * sizeof(int));
	srand((int)time(0));
	for (int i = 0; i < size; i++) {
		data[i] = rand() % maxValue;
	}
	//for (int i = 0; i < size; i++) {
	//	scanf_s("%d", &data[i]);
	//}

	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	quickSort(data, size);

	for (int i = 0; i < size; i++) {
		printf("%d ", data[i]);
	}
	printf("\n");

	return 0;
}

//#include "Heap.h"
//
//int main() {
//	Heap *heap;
//	heapInit(&heap, 100);
//
//	int size, choice, value;
//	scanf_s("%d", &size);
//	for (int i = 0; i < size; i++) {
//		scanf_s("%d", &choice);
//		if (choice == 1) {
//			scanf_s("%d", &value);
//			heapPush(heap, value);
//		}
//		else {
//			heapPop(heap);
//		}
//		system("cls");
//		heapShow(heap);
//	}
//
//	heapDestroy(heap);
//	return 0;
//}