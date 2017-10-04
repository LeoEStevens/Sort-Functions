#ifndef DEF_H
#include "def.h"
#endif

/*
 * MERGESORT
 */
void merge(int array[], int low, int mid, int end) {
	int i, j, k;
	int n1 = mid - low + 1;
	int n2 = end - mid;
	int* lowArray = (int*)malloc(n1 * sizeof(int));
	mergeMem += n1 * sizeof(int);
	int* highArray = (int*)malloc(n2 * sizeof(int));
	mergeMem += n2 * sizeof(int);
	for(i = 0; i < n1; i++) {
		lowArray[i] = array[low + i];
	}
	for(j = 0; j < n2; j++) {
		highArray[j] = array[mid + 1 + j];
	}
	i = 0;
	j = 0;
	k = low;
	while((i < n1) && (j < n2)) {
		if(lowArray[i] <= highArray[j]) {
			array[k] = lowArray[i];
			i++;
		} 
		else {
			array[k] = highArray[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		array[k] = lowArray[i];
		i++;
		k++;
	}
	while (j < n2) {
		array[k] = highArray[j];
		j++;
		k++;
	}
	free(lowArray);
	free(highArray);
}
void mergeSort(int array[], int low, int high) {
	if (low < high) {
		int mid = (low + (high - 1)) / 2;
		mergeSort(array, low, mid);
		mergeSort(array, mid + 1, high);

		merge(array, low, mid, high);
	}
}

double useMergeSort(int array[], int size, int max) {
	clock_t start;
	clock_t stop;
	CLOCK_START;
	mergeSort(array, 0, size - 1);
	CLOCK_STOP;
	double time = TIME;
	printf("Merge Sort took %f seconds and sorted %lli items from 0 to %li.\n\n", time, size, max);
	return time;
}


