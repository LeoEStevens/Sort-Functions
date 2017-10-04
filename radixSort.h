#ifndef DEF_H
#include "def.h"
#endif

/*
 * RADIXSORT
 */
void radixSort(int array[], int max) {
	int m = getMax(array, max);
	int* output = (int*)malloc(max * sizeof(int));
	radixMem += (max * sizeof(long int));
	for(int exp = 1; m/exp > 0; exp *= 10) {

		countSort(array, output, max, exp);
	}
	free(output);
}
double useRadixSort(int array[], int size, int max) {
	clock_t start;
	clock_t stop;
	CLOCK_START;
	radixSort(array, size);
	CLOCK_STOP;
	double time = TIME;
	printf("Radix Sort took %f seconds and sorted %lli items from 0 to %li.\n\n", time, size, max);
	return time;
}

