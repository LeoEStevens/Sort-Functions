#ifndef DEF_H
#include "def.h"
#endif

/*
 * COUNTSORT
 */

//Get max value in array
int getMax(int array[], int max) {
	int high = array[0];
	for(int i = 0; i < max; i++) {
		if(array[i] > high) {
			high = array[i];
		}
	}
	return high;
}
void countSort(int array[], int output[], int max, int exp) {
	int i, count[10] = {0};
	for(i = 0; i < max; i++) {
		count[ (array[i] / exp) % 10 ]++;
	}
	for(i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}
	for(i = max - 1; i >= 0; i--) {
		output[count[ (array[i] / exp) % 10 ] - 1] = array[i];
		count[ (array[i] / exp) % 10]--;
	}
	for(i = 0; i < max; i++) {
		array[i] = output[i];
	}
}

