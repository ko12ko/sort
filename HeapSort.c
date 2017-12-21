#include "Sort.h"
#include "Heap.h"

void heapSort(int *data, int size) {
	Heap *heap;
	heapInit(&heap, size);

	for (int i = 0; i < size; i++) {
		heapPush(heap, data[i]);
	}

	for (int i = 0; i < size; i++) {
		data[i] = heapPop(heap);
	}

	heapDestroy(heap);
}

