#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>

void heapInit(Heap **heap, int maxSize) {
	*heap = malloc(sizeof(Heap));
	(*heap)->size = 0;
	(*heap)->maxSize = maxSize;
	(*heap)->data = malloc(maxSize * sizeof(int));
}

void heapDestroy(Heap *heap) {
	free(heap->data);
	free(heap);
}

static void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

static void heapPushChange(Heap *heap, int index) {
	if (index == 0) {
		return;
	}
	int parentIndex = (index - 1) / 2;
	if (heap->data[index] < heap->data[parentIndex]) {
		swap(&heap->data[index], &heap->data[parentIndex]);
		heapPushChange(heap, parentIndex);
	}
}

int heapPush(Heap *heap, int value) {
	if (heap->size == heap->maxSize) {
		return 1;
	}
	heap->data[heap->size++] = value;
	heapPushChange(heap, heap->size - 1);
	return 0;
}

static void heapPopChange(Heap *heap, int index) {
	int leftChildIndex = index * 2 + 1;
	int rightChildIndex = index * 2 + 2;
	if (rightChildIndex < heap->size) {
		if (heap->data[leftChildIndex] < heap->data[index] && heap->data[leftChildIndex] < heap->data[rightChildIndex]) {
			swap(&heap->data[leftChildIndex], &heap->data[index]);
			heapPopChange(heap, leftChildIndex);
		}
		else if (heap->data[rightChildIndex] < heap->data[index] && heap->data[rightChildIndex] < heap->data[leftChildIndex]) {
			swap(&heap->data[rightChildIndex], &heap->data[index]);
			heapPopChange(heap, rightChildIndex);
		}
	}
	else if (leftChildIndex < heap->size) {
		if (heap->data[leftChildIndex] < heap->data[index]) {
			swap(&heap->data[leftChildIndex], &heap->data[index]);
		}
	}
}

int heapPop(Heap *heap) {
	if (heap->size == 0) {
		return -1;
	}
	int value = heap->data[0];
	heap->data[0] = heap->data[heap->size - 1];
	heap->size--;
	heapPopChange(heap, 0);
	return value;
}

static void heapShowSub(Heap *heap, int index, int depth) {
	int leftChildIndex = index * 2 + 1;
	if (leftChildIndex < heap->size) {
		heapShowSub(heap, leftChildIndex, depth + 1);
	}

	for (int i = 0; i < depth; i++) {
		printf(" ");
	}
	printf("%d\n", heap->data[index]);

	int rightChildIndex = index * 2 + 2;
	if (rightChildIndex < heap->size) {
		heapShowSub(heap, rightChildIndex, depth + 1);
	}
}

void heapShow(Heap *heap) {
	if (heap->size == 0) {
		return;
	}
	heapShowSub(heap, 0, 0);
}