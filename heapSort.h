#ifndef DEF_H
#include "def.h"
#endif

/*
 * HEAPSORT
 */

//Structure for HeapSort
struct MaxHeap {
	int size;
	int* array;
};

void maxHeapify(struct MaxHeap* maxHeap, int index) {
	int largest = index;
	int left = (index << 1) + 1;
	int right = (index + 1) << 1;

	if((left < maxHeap->size) && (maxHeap->array[left] > maxHeap->array[largest])) {
		largest = left;
	}
	if((right < maxHeap->size) && (maxHeap->array[right] > maxHeap->array[largest])) {
		largest = right;
	}
	if(largest != index) {
		swap(&maxHeap->array[largest], &maxHeap->array[index]);
		maxHeapify(maxHeap, largest);
	}
}
struct MaxHeap* createAndBuildHeap(int *array, int size) {
	int i;
	struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
	heapMem += sizeof(struct MaxHeap);
	maxHeap->size = size;
	maxHeap->array = array;

	for(i = (maxHeap->size - 2) / 2; i >= 0; --i) {
		maxHeapify(maxHeap, i);
	}
	return maxHeap;
}
void heapSort(int* array, int size) {
	struct MaxHeap* maxHeap = createAndBuildHeap(array, size);

	while(maxHeap->size > 1) {
		swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
		--maxHeap->size;
		maxHeapify(maxHeap, 0);
	}
	free(maxHeap);
}
double useHeapSort(int array[], int size, int max) {
	clock_t start;
	clock_t stop;
	CLOCK_START;
	heapSort(array, size);
	CLOCK_STOP;
	double time = TIME;
	printf("Heap Sort took %f seconds and sorted %lli items from 0 to %li.\n\n", time, size, max);
	return time;
}

