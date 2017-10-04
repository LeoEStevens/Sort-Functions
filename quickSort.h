#ifndef DEF_H
#include "def.h"
#endif
/*
 * QUICKSORT
 */
void quickSort(int array[], int low, int high) {
	if( low < high ) {
		int part = partition(array, low, high);
		quickSort(array, low, part - 1);
		quickSort(array, part + 1, high);
	}
}
double useQuickSort(int array[], int size, int max) {
	clock_t start;
	clock_t stop;
	CLOCK_START;
	quickSort(array, 0, size - 1);
	CLOCK_STOP;
	double time = TIME;
	printf("Quick Sort took %f seconds and sorted %lli items from 0 to %li.\n\n", time, size, max);
	return time;
}

