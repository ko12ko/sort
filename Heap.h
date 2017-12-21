#ifndef HEAP_H
#define HEAP_H

typedef struct Heap {
	int *data;
	int size;
	int maxSize;
} Heap;

void heapInit(Heap **heap, int maxSize);
void heapDestroy(Heap *heap);
int heapPush(Heap *heap, int value);
int heapPop(Heap *heap);

void heapShow(Heap *heap);

#endif // !HEAP_H
