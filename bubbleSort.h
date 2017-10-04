#ifndef DEF_H
#include "def.h"
#endif

/*
 * BUBBLESORT
 */

void bubbleSort(int array[], int max) {
	int i, j;
	for(i = 0; i < max - 1; i++) {
		for(j = 0; j < max - i - 1; j++) {
			if(array[j] > array[j+1]) {
				swap(&array[j], &array[i]);
			}
		}
	}
}
double useBubbleSort(int array[], int size, int max) {
	clock_t start;
	clock_t stop;
	CLOCK_START;
	bubbleSort(array, size);
	CLOCK_STOP;
	double time = TIME;
	printf("Bubble Sort took %f seconds and sorted %lli items from 0 to %li.\n\n", time, size, max);
	return time;
}

