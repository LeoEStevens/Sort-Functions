//Headers
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include "helper.h"
#include "quickSort.h"
#include "bubbleSort.h"
#include "countSort.h"
#include "radixSort.h"
#include "mergeSort.h"
#include "heapSort.h"

//Main function
int main(int argc, char* argv[]) {
        //Variable declaration and definition
	int* array;                                     // Pointer to array to be sorted
	int size = 1000000;                             // Default size
	int isize = 0;                                  // Input size (-s arg lets user define size)
	int farMax = 0;                                 // Max number for sparse array
	int midMax = 0;                                 // Max number for medium array
	int closeMax = 0;                               // Max number for dense array
	int q = 0;                                      // arg flag for quickSort
	int b = 0;                                      // arg flag for bubbleSort
	int r = 0;                                      // arg flag for radixSort
	int m = 0;                                      // arg flag for mergeSort
	int h = 0;                                      // arg flag for heapSort
	//Char arrays for holding the names of the fastest sorting arrays
        char ldFast[20];                                
	char lrFast[20];
	char lsFast[20];
	char mdFast[20];
	char mrFast[20];
	char msFast[20];
	char sdFast[20];
	char srFast[20];
	char ssFast[20];
	char largeFast[20];
	char regFast[20];
	char smlFast[20];
	char avgFast[20];
	char denFast[20];
	char medFast[20];
	char sprFast[20];
        //Doubles for holding the fastest speeds, set to 1000 by default so inital check will always be less than
	double ldFst = 1000;
	double lrFst = 1000;
	double lsFst = 1000;
	double mdFst = 1000;
	double mrFst = 1000;
	double msFst = 1000;
	double sdFst = 1000;
	double srFst = 1000;
	double ssFst = 1000;
	double avgFstL = 1000;
	double avgFstR = 1000;
	double avgFstS = 1000;
	double avgFst = 1000;
	double avgFstDen = 1000;
	double avgFstMed = 1000;
	double avgFstSpr = 1000;
        //Clear opterrors
	opterr = 0;
        //int to hold args
	int c;
        //If no args were entered
	if(argc == 1 || (argc > 1 && (strcmp(argv[1],"-s") == 0))) {
		q = 1;
		b = 1;
		r = 1;
		m = 1;
		h = 1;
	}
        //While loop to get args
	while((c = getopt (argc, argv, "qbrmhs:")) != -1) {
		switch(c) {
                        //quickSort arg
			case 'q' :
				q = 1;
				break;
                        //bubbleSort arg
			case 'b' :
				b = 1;
				break;
                        //radixSort arg
			case 'r' :
				r = 1;
				break;
                        //mergeSort arg
			case 'm' :
				m = 1;
				break;
                        //heapSort arg
			case 'h' :
				h = 1;
				break;
                        //Size arg
			case 's' :
				isize = atoi(optarg);
                                //Check if size is within boundaries
                                if(isize <= 0 || isize > ((INT_MAX / 10)) - 1) {
                                        printf("Error: Size must be between 0 and %i.\n", ((INT_MAX / 10) - 1));
                                        return 1;
                                }
				break;
                        //Unknown arg
			case '?' :
				fprintf(stderr, "Unknown option: '%c'.\n", optopt);
				return 1;
			default :
				abort ();
		}
	}
        //Set size to user input size
	if(isize) {
		size = isize;
	}
        //Print information about array being created
	printline(150);
	printf("Creating array of %lli items.\n", size);
	array = (int*)malloc((size * 10) * sizeof(int));
	baseArrayMem += (size * 10) * sizeof(int);
    	if(array == NULL) {
		printf("Malloc failed: Not enough space in RAM to hold array that size.\nTry decreasing -s\n");
		exit(0);
	}
	printline(150);
	
        //Pointers to three different arrays (dense, mid, and sparse)
	int* closeArray;
	int* midArray;
	int* farArray;
        
        //quickSort if q == 1
	if(q == 1) {
		if(isize) {
			size = isize;
		} else {
			size = 100000;
		}
		printline(100);
		printf("QuickSort\n");
		printline(100);
		size *= 10;
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using QuickSort on large dense array.\n");
		double qsLDTime = useQuickSort(closeArray, size, closeMax);
		if(qsLDTime < ldFst) {
			ldFst = qsLDTime;
			strncpy(ldFast, "QuickSort", 20); 
		}
		printf("Using QuickSort on large regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double qsLRTime = useQuickSort(midArray, size, midMax);
		if(qsLRTime < lrFst) {
			lrFst = qsLRTime;
			strncpy(lrFast, "QuickSort", 20); 
		}
		printf("Using QuickSort on large sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double qsLSTime = useQuickSort(farArray, size, farMax);
		if(qsLSTime < lsFst) {
			lsFst = qsLSTime;
			strncpy(lsFast, "QuickSort", 20); 
		}
		double avgL = AVERAGE(qsLDTime, qsLRTime, qsLSTime);
		if(avgL < avgFstL) {
			avgFstL = avgL;
			strncpy(largeFast, "QuickSort", 20); 
		}
		printline(80);
		printf("Average time for QuickSort on large array: %f.\n", avgL);
		printf("Difference: %f\n", (fabs(qsLDTime - qsLSTime)));
		printline(80);
		size /= 10;
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using QuickSort on medium dense array.\n");
		double qsMDTime = useQuickSort(closeArray, size, closeMax);
		if(qsMDTime < mdFst) {
			mdFst = qsMDTime;
			strncpy(mdFast, "QuickSort", 20); 
		}	
		printf("Using QuickSort on medium regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double qsMRTime = useQuickSort(midArray, size, midMax);
		if(qsMRTime < mrFst) {
			mrFst = qsMRTime;
			strncpy(mrFast, "QuickSort", 20); 
		}	
		printf("Using QuickSort on medium sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double qsMSTime = useQuickSort(farArray, size, farMax);
		if(qsMSTime < msFst) {
			msFst = qsMSTime;
			strncpy(msFast, "QuickSort", 20); 
		}
		double avgM = AVERAGE(qsMDTime, qsMRTime, qsMSTime);
		if(avgM < avgFstR ) {
			avgFstR = avgM;
			strncpy(regFast, "QuickSort", 20); 
		}
		printline(80);
		printf("Average time for QuickSort on medium array: %f.\n", avgM);
		printf("Difference: %f\n", (fabs(qsMDTime - qsMSTime)));
		printline(80);
		size /= 10;
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using QuickSort on small dense array.\n");
		double qsSDTime = useQuickSort(closeArray, size, closeMax);
		if(qsSDTime < sdFst) {
			sdFst = qsSDTime;
			strncpy(sdFast, "QuickSort", 20); 
		}
		printf("Using QuickSort on small regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double qsSRTime = useQuickSort(midArray, size, midMax);
		if(qsSRTime < srFst) {
			srFst = qsSRTime;
			strncpy(srFast, "QuickSort", 20); 
		}
		printf("Using QuickSort on small sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double qsSSTime = useQuickSort(farArray, size, farMax);
		if(qsSSTime < ssFst) {
			ssFst = qsSRTime;
			strncpy(ssFast, "QuickSort", 20); 
		}	
		double avgS = AVERAGE(qsSDTime, qsSRTime, qsSSTime);
		if(avgS < avgFstS) {
			avgFstS = avgS;
			strncpy(smlFast, "QuickSort", 20); 
		}
		printline(80);
		printf("Average time for QuickSort on small array: %f.\n", avgS);
		printf("Difference: %f\n", (fabs(qsSDTime - qsSSTime)));
		printline(80);
		double avgQS = AVERAGE(avgL, avgM, avgS);
		if(avgQS < avgFst) {
			avgFst = avgQS;
			strncpy(avgFast, "QuickSort", 20); 
		}
		printline(100);
		double qsAvgD = AVERAGE(qsLDTime, qsMDTime, qsSDTime);
		if(qsAvgD < avgFstDen) {
			avgFstDen = qsAvgD;
			strncpy(denFast, "QuickSort", 20);
		}
	       	printf("Average time for QuickSort on dense arrays: %f.\n", qsAvgD);
		double qsAvgR = AVERAGE(qsLRTime, qsMRTime, qsSRTime);
		if(qsAvgR < avgFstMed) {
			avgFstMed = qsAvgR;
			strncpy(medFast, "QuickSort", 20);
		}
		printf("Average time for QuickSort on regular arrays: %f.\n", qsAvgR);	
		double qsAvgS = AVERAGE(qsLSTime, qsMSTime, qsSSTime);
		if(qsAvgS < avgFstSpr) {
			avgFstSpr = qsAvgS;
			strncpy(sprFast, "QuickSort", 20);
		}
		printf("Average time for QuickSort on sparce arrays: %f.\n", qsAvgS);	
		printline(100);	
		printf("Average time for QuickSort on all arrays: %f.\n", avgQS);
		printf("Difference: %f\n", (fabs(avgL - avgS)));
		printline(100);	
	}
        /* bubbleSort is b == 1,f fastest time is commented out because bubbleSort is O(n^2),
         * and will never be faster than the other arrays that it can be compared against.
         * Included as an example of O(n^2) algo. Also the size is reduce by a factor of 10 if larger than 1000.
         */
	if(b == 1) {
		if((isize != 0) && (isize < 1000)) {
			size = isize;
		}
		else if(isize && (isize >= 1000)) {
			size = isize / 10;
		}
	       	else {
			size = 100000;
		}
		printline(80);
		printf("BubbleSort\n");
		printf("n^2 algorithm so size is reduced by a factor of 10.\n");
		printline(80);
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using BubbleSort on large dense array.\n");
		double bsLDTime = useBubbleSort(closeArray, size, closeMax);
		if(bsLDTime < mdFst) {
			mdFst = bsLDTime;
			strncpy(mdFast, "BubbleSort", 20);
		}	
		printf("Using BubbleSort on large regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double bsLRTime = useBubbleSort(midArray, size, midMax);
		if(bsLRTime < mrFst) {
			mrFst = bsLRTime;
			strncpy(mrFast, "BubbleSort", 20);
		}
		printf("Using BubbleSort on large sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double bsLSTime = useBubbleSort(farArray, size, farMax);
		if(bsLSTime < msFst) {
			msFst = bsLSTime;
			strncpy(msFast, "BubbleSort", 20);
		}
		double avgBL = AVERAGE(bsLDTime, bsLRTime, bsLSTime);
		if(avgBL < avgFstR) {
			avgFstR = avgBL;
			strncpy(largeFast, "BubbleSort", 20);
		}
		printline(80);
		printf("Average time for BubbleSort on large array: %f.\n", avgBL);
		printf("Difference: %f\n", (fabs(bsLDTime - bsLSTime)));
		printline(80);
		size /= 10;
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using BubbleSort on medium dense array.\n");
		double bsMDTime = useBubbleSort(closeArray, size, closeMax);
		if(bsMDTime < sdFst) {
			sdFst = bsMDTime;
			strncpy(sdFast, "BubbleSort", 20);
		}
		printf("Using BubbleSort on medium regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double bsMRTime = useBubbleSort(midArray, size, midMax);
		if(bsMRTime < srFst) {
			srFst = bsMRTime;
			strncpy(srFast, "BubbleSort", 20);
		}
		printf("Using BubbleSort on medium sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double bsMSTime = useBubbleSort(farArray, size, farMax);
		if(bsMSTime < ssFst) {
			ssFst = bsMSTime;
			strncpy(ssFast, "BubbleSort", 20);
		}
		double avgBM = AVERAGE(bsMDTime, bsMRTime, bsMSTime);
		if(avgBM < avgFstS) {
			avgFstS = bsLDTime;
			strncpy(smlFast, "BubbleSort", 20);
		}
		printline(80);
		printf("Average time for Bubble Sort on medium array: %f.\n", avgBM);
		printf("Difference: %f\n", (fabs(bsMDTime - bsMSTime)));
		printline(80);
		size /= 10;
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using BubbleSort on small dense array.\n");
		double bsSDTime = useQuickSort(closeArray, size, closeMax);
		/*
		if(bsSDTime < sdFst) {
			sdFst = bsSDTime;
			strncpy(sdFast, "BubbleSort", 20);
		}
		*/
		printf("Using BubbleSort on small regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double bsSRTime = useQuickSort(midArray, size, midMax);
		/*
		if(bsSRTime < srFst) {
			srFst = bsSRTime;
			strncpy(srFast, "BubbleSort", 20);
		}
		*/
		printf("Using BubbleSort on small sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double bsSSTime = useQuickSort(farArray, size, farMax);
		/*
		if(bsSSTime < ssFst) {
			ssFst = bsSSTime;
			strncpy(ssFast, "BubbleSort", 20);
		}
		*/
		double avgBS = AVERAGE(bsSDTime, bsSRTime, bsSSTime);
		/*
		if(avgBS < avgFstS) {
			avgFstS = avgBS;
			strncpy(smlFast, "BubbleSort", 20);
		}
		*/
		printline(80);
		printf("Average time for BubbleSort on small array: %f.\n", avgBS);
		printf("Difference: %f\n", (fabs(bsSDTime - bsSSTime)));
		printline(80);
		double avgBA = AVERAGE(avgBL, avgBM, avgBS);
		/*
		if(avgBA < avgFst) {
			avgFst = avgBA;
			strncpy(avgFast, "BubbleSort", 20);
		}
		*/
		printline(100);
		double bsAvgD = AVERAGE(bsLDTime, bsMDTime, bsSDTime);
		if(bsAvgD < avgFstDen) {
			avgFstDen = bsAvgD;
			strncpy(denFast, "BubbleSort", 20);
		}
	       	printf("Average time for BubbleSort on dense arrays: %f.\n", bsAvgD);
		double bsAvgR = AVERAGE(bsLRTime, bsMRTime, bsSRTime);
		if(bsAvgR < avgFstMed) {
			avgFstMed = bsAvgR;
			strncpy(medFast, "BubbleSort", 20);
		}
		printf("Average time for BubbleSort on regular arrays: %f.\n", bsAvgR);	
		double bsAvgS = AVERAGE(bsLSTime, bsMSTime, bsSSTime);
		if(bsAvgS < avgFstSpr) {
			avgFstSpr = bsAvgS;
			strncpy(sprFast, "BubbleSort", 20);
		}
		printf("Average time for BubbleSort on sparce arrays: %f.\n", bsAvgS);	
		printline(100);
		printf("Average time for BubbleSort on all arrays: %f.\n", avgBA);
		printf("Difference: %f\n", (fabs(avgBL - avgBS)));
		printline(100);
	}
        //radixSort if r == 1
	if(r == 1) {
		if (isize) {
		       	size = isize;
		} else {
			size = 100000;
		}
		printline(100);
		printf("RadixSort\n");
		printline(100);
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		size *= 10;
		printf("Using RadixSort on large dense array.\n");
		double rsLDTime = useRadixSort(closeArray, size, closeMax);
		if(rsLDTime < ldFst) {
			ldFst = rsLDTime;
			strncpy(ldFast, "RadixSort", 20);
		}
		printf("Using RadixSort on large regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double rsLRTime = useRadixSort(midArray, size, midMax);
		if(rsLRTime < lrFst) {
			lrFst = rsLRTime;
			strncpy(lrFast, "RadixSort", 20);
		}
		printf("Using RadixSort on large sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double rsLSTime = useRadixSort(farArray, size, farMax);
		if(rsLSTime < lsFst) {
			lsFst = rsLSTime;
			strncpy(lsFast, "RadixSort", 20);
		}
		double avgRL = AVERAGE(rsLDTime, rsLRTime, rsLSTime);
		if(avgRL < avgFstL) {
			avgFstL = avgRL;
			strncpy(largeFast, "RadixSort", 20);
		}
		printline(80);
		printf("Average time for RadixSort on large array: %f.\n", avgRL);
		printf("Difference: %f\n", (fabs(rsLDTime - rsLSTime)));
		printline(80);
		size /= 10;
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using RadixSort on medium dense array.\n");
		double rsMDTime = useRadixSort(closeArray, size, closeMax);
		if(rsMDTime < mdFst) {
			mdFst = rsMDTime;
			strncpy(mdFast, "RadixSort", 20);
		}
		printf("Using RadixSort on medium regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double rsMRTime = useRadixSort(midArray, size, midMax);
		if(rsMRTime < mrFst) {
			mrFst = rsMRTime;
			strncpy(mrFast, "RadixSort", 20);
		}
		printf("Using RadixSort on medium sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double rsMSTime = useRadixSort(farArray, size, farMax);
		if(rsMSTime < msFst) {
			msFst = rsMSTime;
			strncpy(msFast, "RadixSort", 20);
		}
		double avgRM = AVERAGE(rsMDTime, rsMRTime, rsMSTime);
		if(avgRM < avgFstR) {
			avgFstR = avgRM;
			strncpy(regFast, "RadixSort", 20);
		}
		printline(80);
		printf("Average time for RadixSort on medium array: %f.\n", avgRM);
		printf("Difference: %f\n", (fabs(rsMDTime - rsMSTime)));
		printline(80);
		size /= 10;
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using RadixSort on small dense array.\n");
		double rsSDTime = useRadixSort(closeArray, size, closeMax);
		if(rsSDTime < sdFst) {
			sdFst = rsSDTime;
			strncpy(sdFast, "RadixSort", 20);
		}
		printf("Using RadixSort on small regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double rsSRTime = useRadixSort(midArray, size, midMax);
		if(rsSRTime < srFst) {
			srFst = rsSRTime;
			strncpy(srFast, "RadixSort", 20);
		}
		printf("Using RadixSort on small sparce array.\n");
		farMax = size * 10;		
		farArray = createArray(array, size, farMax);
		double rsSSTime = useRadixSort(farArray, size, farMax);
		if(rsSSTime < ssFst) {
			ssFst = rsSSTime;
			strncpy(ssFast, "RadixSort", 20);
		}
		double avgRS = AVERAGE(rsSDTime, rsSRTime, rsSSTime);
		if(avgRS < avgFstS) {
			avgFstS = avgRS;
			strncpy(smlFast, "RadixSort", 20);
		}
		printline(80);
		printf("Average time for RadixSort on small array: %f.\n", avgRS);
		printf("Difference: %f\n", (fabs(rsSDTime - rsSSTime)));
		printline(80);
		double avgRA = AVERAGE(avgRL, avgRM, avgRS);
		if(avgRA < avgFst) {
			avgFst = avgRA;
			strncpy(avgFast, "RadixSort", 20);
		}
		printline(100);
		double rsAvgD = AVERAGE(rsLDTime, rsMDTime, rsSDTime);
		if(rsAvgD < avgFstDen) {
			avgFstDen = rsAvgD;
			strncpy(denFast, "RadixSort", 20);
		}
	       	printf("Average time for RadixSort on dense arrays: %f.\n", rsAvgD);
		double rsAvgR = AVERAGE(rsLRTime, rsMRTime, rsSRTime);
		if(rsAvgR < avgFstMed) {
			avgFstMed = rsAvgR;
			strncpy(medFast, "RadixSort", 20);
		}
		printf("Average time for RadixSort on regular arrays: %f.\n", rsAvgR);	
		double rsAvgS = AVERAGE(rsLSTime, rsMSTime, rsSSTime);
		if(rsAvgS < avgFstSpr) {
			avgFstSpr = rsAvgS;
			strncpy(sprFast, "RadixSort", 20);
		}
		printf("Average time for RadixSort on sparce arrays: %f.\n", rsAvgS);	
		printline(100);
		printf("Average time for RadixSort on all arrays: %f.\n", avgRA);
		printf("Difference: %f\n", (fabs(avgRL - avgRS)));
		printline(100);
		//printArray(farArray, size);	
	}
        //mergeSort if m == 1
	if(m == 1) {
		if(isize) {
			size = isize;
		} else {
			size = 100000;
		}
		printline(100);
		printf("MergeSort\n");
		printline(100);
		size *= 10;
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using MergeSort on large dense array.\n");
		double msLDTime = useMergeSort(closeArray, size, closeMax);
		if(msLDTime < ldFst) {
			ldFst = msLDTime;
			strncpy(ldFast, "MergeSort", 20);
		}
	
		printf("Using MergeSort on large regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double msLRTime = useMergeSort(midArray, size, midMax);
		if(msLRTime < lrFst) {
			lrFst = msLRTime;
			strncpy(lrFast, "MergeSort", 20);
		}
		printf("Using MergeSort on large sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double msLSTime = useMergeSort(farArray, size, farMax);
		if(msLSTime < lsFst) {
			lsFst = msLSTime;
			strncpy(lsFast, "MergeSort", 20);
		}
		double avgML = AVERAGE(msLDTime, msLRTime, msLSTime);
		if(avgML < avgFstL) {
			avgFstL = avgML;
			strncpy(largeFast, "MergeSort", 20);
		}
		printline(80);
		printf("Average time for MergeSort on large array: %f.\n", avgML);
		printf("Difference: %f\n", (fabs(msLDTime - msLSTime)));
		printline(80);
		size /= 10;
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using MergeSort on medium dense array.\n");
		double msMDTime = useMergeSort(closeArray, size, closeMax);
		if(msMDTime < mdFst) {
			mdFst = msMDTime;
			strncpy(mdFast, "MergeSort", 20);
		}
		printf("Using MergeSort on medium regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double msMRTime = useMergeSort(midArray, size, midMax);
		if(msMRTime < mrFst) {
			mrFst = msMRTime;
			strncpy(mrFast, "MergeSort", 20);
		}
		printf("Using MergeSort on medium sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double msMSTime = useMergeSort(farArray, size, farMax);
		if(msMSTime < msFst) {
			msFst = msMSTime;
			strncpy(msFast, "MergeSort", 20);
		}
		double avgMM = AVERAGE(msMDTime, msMRTime, msMSTime);
		if(avgMM < avgFstR) {
			avgFstR = avgMM;
			strncpy(regFast, "MergeSort", 20);
		}
		printline(80);
		printf("Average time for MergeSort on medium array: %f.\n", avgMM);
		printf("Difference: %f\n", (fabs(msMDTime - msMSTime)));
		printline(80);
		size /= 10;
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using MergeSort on small dense array.\n");
		double msSDTime = useMergeSort(closeArray, size, closeMax);
		if(msSDTime < sdFst) {
			sdFst = msSDTime;
			strncpy(sdFast, "MergeSort", 20);
		}
		printf("Using MergeSort on small regular array.\n");
		midMax = size;	
		midArray = createArray(array, size, midMax);
		double msSRTime = useMergeSort(midArray, size, midMax);
		if(msSRTime < srFst) {
			srFst = msSRTime;
			strncpy(srFast, "MergeSort", 20);
		}
		printf("Using MergeSort on small sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double msSSTime = useMergeSort(farArray, size, farMax);
		if(msSSTime < ssFst) {
			ssFst = msSSTime;
			strncpy(ssFast, "MergeSort", 20);
		}
		double avgMS = AVERAGE(msSDTime, msSRTime, msSSTime);
		if(avgMS < avgFstS) {
			avgFstS = avgMS;
			strncpy(smlFast, "MergeSort", 20);
		}
		printline(80);
		printf("Average time for MergeSort on small array: %f.\n", avgMS);
		printf("Difference: %f\n", (fabs(msSDTime - msSSTime)));
		printline(80);
		double avgMA = AVERAGE(avgML, avgMM, avgMS);
		if(avgMA < avgFst) {
			avgFst = avgMA;
			strncpy(avgFast, "MergeSort", 20);
		}
		printline(100);
		double msAvgD = AVERAGE(msLDTime, msMDTime, msSDTime);
		if(msAvgD < avgFstDen) {
			avgFstDen = msAvgD;
			strncpy(denFast, "MergeSort", 20);
		}
	       	printf("Average time for MergeSort on dense arrays: %f.\n", msAvgD);
		double msAvgR = AVERAGE(msLRTime, msMRTime, msSRTime);
		if(msAvgR < avgFstMed) {
			avgFstMed = msAvgR;
			strncpy(medFast, "MergeSort", 20);
		}
		printf("Average time for MergeSort on regular arrays: %f.\n", msAvgR);	
		double msAvgS = AVERAGE(msLSTime, msMSTime, msSSTime);
		if(msAvgS < avgFstSpr) {
			avgFstSpr = msAvgS;
			strncpy(sprFast, "MergeSort", 20);
		}
		printf("Average time for MergeSort on sparce arrays: %f.\n", msAvgS);	
		printline(100);
		printf("Average time for MergeSort on all arrays: %f.\n", avgMA);
		printf("Difference: %f\n", (fabs(avgML - avgMS)));
		printline(100);
		//printArray(farArray, size);
	}
        //heapSort if h == 1
	if(h == 1) {
		if(isize) {
			size = isize;
		} else {
			size = 100000;
		}
		printline(100);
		printf("HeapSort\n");
		printline(100);
		size *= 10;
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using HeapSort on large dense array.\n");
		double hsLDTime = useHeapSort(closeArray, size, closeMax);
		if(hsLDTime < ldFst) {
			ldFst = hsLDTime;
			strncpy(ldFast, "HeapSort", 20); 
		}
		printf("Using HeapSort on large regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double hsLRTime = useHeapSort(midArray, size, midMax);
		if(hsLRTime < lrFst) {
			lrFst = hsLRTime;
			strncpy(lrFast, "HeapSort", 20); 
		}
		printf("Using HeapSort on large sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double hsLSTime = useHeapSort(farArray, size, farMax);
		if(hsLSTime < lsFst) {
			lsFst = hsLSTime;
			strncpy(lsFast, "HeapSort", 20); 
		}
		double avgHL = AVERAGE(hsLDTime, hsLRTime, hsLSTime);
		if(avgHL < avgFstL) {
			avgFstL = avgHL;
			strncpy(largeFast, "HeapSort", 20); 
		}
		printline(80);
		printf("Average time for HeapSort on large array: %f.\n", avgHL);
		printf("Difference: %f\n", (fabs(hsLDTime - hsLSTime)));
		printline(80);
		size /= 10;
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using HeapSort on regular dense array.\n");
		double hsMDTime = useHeapSort(closeArray, size, closeMax);
		if(hsMDTime < mdFst) {
			mdFst = hsMDTime;
			strncpy(mdFast, "HeapSort", 20); 
		}	
		printf("Using HeapSort on regular regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double hsMRTime = useHeapSort(midArray, size, midMax);
		if(hsMRTime < mrFst) {
			mrFst = hsMRTime;
			strncpy(mrFast, "HeapSort", 20); 
		}	
		printf("Using HeapSort on regular sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double hsMSTime = useHeapSort(farArray, size, farMax);
		if(hsMSTime < msFst) {
			msFst = hsMSTime;
			strncpy(msFast, "HeapSort", 20); 
		}
		double avgHM = AVERAGE(hsMDTime, hsMRTime, hsMSTime);
		if(avgHM < avgFstR ) {
			avgFstR = avgHM;
			strncpy(regFast, "HeapSort", 20); 
		}
		printline(80);
		printf("Average time for HeapSort on medium array: %f.\n", avgHM);
		printf("Difference: %f\n", (fabs(hsMDTime - hsMSTime)));
		printline(80);
		size /= 10;
		closeMax = size / 10;
		closeArray = createArray(array, size, closeMax);
		printf("Using HeapSort on small dense array.\n");
		double hsSDTime = useHeapSort(closeArray, size, closeMax);
		if(hsSDTime < sdFst) {
			sdFst = hsSDTime;
			strncpy(sdFast, "HeapSort", 20); 
		}
		printf("Using HeapSort on small regular array.\n");
		midMax = size;
		midArray = createArray(array, size, midMax);
		double hsSRTime = useHeapSort(midArray, size, midMax);
		if(hsSRTime < srFst) {
			srFst = hsSRTime;
			strncpy(srFast, "HeapSort", 20); 
		}
		printf("Using HeapSort on small sparce array.\n");
		farMax = size * 10;
		farArray = createArray(array, size, farMax);
		double hsSSTime = useHeapSort(farArray, size, farMax);
		if(hsSSTime < ssFst) {
			ssFst = hsSRTime;
			strncpy(ssFast, "HeapSort", 20); 
		}	
		double avgHS = AVERAGE(hsSDTime, hsSRTime, hsSSTime);
		if(avgHS < avgFstS) {
			avgFstS = avgHS;
			strncpy(smlFast, "HeapSort", 20); 
		}
		printline(80);
		printf("Average time for HeapSort on small array: %f.\n", avgHS);
		printf("Difference: %f\n", (fabs(hsSDTime - hsSSTime)));
		printline(80);
		double avgH = AVERAGE(avgHL, avgHM, avgHS);
		if(avgH < avgFst) {
			avgFst = avgHS;
			strncpy(avgFast, "HeapSort", 20); 
		}
		printline(100);
		double hsAvgD = AVERAGE(hsLDTime, hsMDTime, hsSDTime);
		if(hsAvgD < avgFstDen) {
			avgFstDen = hsAvgD;
			strncpy(denFast, "HeapSort", 20);
		}
	       	printf("Average time for HeapSort on dense arrays: %f.\n", hsAvgD);
		double hsAvgR = AVERAGE(hsLRTime, hsMRTime, hsSRTime);
		if(hsAvgR < avgFstMed) {
			avgFstMed = hsAvgR;
			strncpy(medFast, "HeapSort", 20);
		}
		printf("Average time for HeapSort on regular arrays: %f.\n", hsAvgR);	
		double hsAvgS = AVERAGE(hsLSTime, hsMSTime, hsSSTime);
		if(hsAvgS < avgFstSpr) {
			avgFstSpr = hsAvgS;
			strncpy(sprFast, "HeapSort", 20);
		}
		printf("Average time for HeapSort on sparce arrays: %f.\n", hsAvgS);	
		printline(100);
		printf("Average time for HeapSort on all arrays: %f.\n", avgH);
		printf("Difference: %f\n", (fabs(avgHL - avgHS)));
		printline(100);
		//printArray(closeArray, size);

	
	}	
        //Print theoretical information about sorting methods used (Time and Space complexity)
	if(q == 1) {
		printline(80);
		printf("QuickSort Info:\n");
		printf("Unstable\n\n");
		printf("In-Place\n");
		printf("Time Complexity:\n");
		printf("Best-case performace: O(n log n).\n");
		printf("Average performace: O(n log n).\n");
		printf("Worst-case performace: O(n^2).\n");
		printf("\nSpace Complexity:\n");
		printf("Average: log n\n");
		printf("Worst: n\n");
		printline(80);
	}
	if(b == 1) {
		printline(80);
		printf("BubbleSort Info:\n");
		printf("Stable\n");
		printf("In-Place\n\n");
		printf("Time Complexity:\n");
		printf("Best-case performace: O(n).\n");
		printf("Average performace: O(n^2).\n");
		printf("Worst-case performace: O(n^2).\n");
		printf("\nSpace Complexity:\n");
		printf("Always: 1\n");
		printline(80);
	}
	if(r == 1) {
		printline(80);
		printf("RadixSort Info:\n");
		printf("Stable\n\n");
		printf("Time Complexity:\n");
		printf("Best-case performace: O(n log n).\n");
		printf("Average performace: O(n log n).\n");
		printf("Worst-case performace: O(n (log n)^2).\n");
		printf("\nSpace Complexity:\n");
		printf("Always: n + 2^(digit size)\n");
		printline(80);
	}
	if(m == 1) {
		printline(80);
		printf("MergeSort Info:\n");
		printf("Stable\n\n");
		printf("Time Complexity:\n");
		printf("Best-case performace: O(n log n).\n");
		printf("Average performace: O(n log n).\n");
		printf("Worst-case performace: O(n log n).\n");
		printf("\nSpace Complexity:\n");
		printf("Always: n\n");
		printline(80);
	}
	if(h == 1) {
		printline(80);
		printf("HeapSort Info:\n");
		printf("Unstable\n");
		printf("In-Place (In Structure)\n\n");
		printf("Time Complexity:\n");
		printf("Best-case performace: O(n log n).\n");
		printf("Average performace: O(n log n).\n");
		printf("Worst-case performace: O(n log n).\n");
		printf("\nSpace Complexity:\n");
		printf("Always: 1\n");
		printline(80);
	}
        
        //Print actual information about sorting methods used
	printline(100);
        //Memory usage
	printf("Memory Usage:\n");
	printf("Base Memory Usage: %lli bytes.\n", baseArrayMem);
	if(q == 1) { printf("QuickSort Memory Usage: %lli bytes (%d x Base).\n", quickMem, (int)(quickMem / baseArrayMem)); }
	if(b == 1) { printf("BubbleSort Memory Usage: %lli bytes (%d x Base).\n", bubbleMem, (int)(bubbleMem / baseArrayMem)); }
	if(r == 1) { printf("RadixSort Memory Usage: %lli bytes (%d x Base).\n", radixMem, (int)(radixMem / baseArrayMem)); }
	if(m == 1) { printf("MergeSort Memory Usage: %lli bytes (%d x Base).\n", mergeMem, (int)(mergeMem / baseArrayMem)); }
	if(h == 1) { printf("HeapSort Memory Usage: %lli bytes (%d x Base).\n", heapMem, (int)(heapMem / baseArrayMem)); }
	printline(100);
        //Fastest sorts	
	if(( q + b + r + m + h) > 1) {
		printline(100);
		printf("The fastest algorithm on large dense array is: %s (%f).\n", ldFast, ldFst);
		printf("The fastest algorithm on large regular array is: %s (%f).\n", lrFast, lrFst);
		printf("The fastest algorithm on large sparce array is: %s (%f).\n", lsFast, lsFst);
		printline(75);
		printf("The fastest algorithm on medium dense array is: %s (%f).\n", mdFast, mdFst);
		printf("The fastest algorithm on medium regular array is: %s (%f).\n", mrFast, mrFst);
		printf("The fastest algorithm on medium sparce array is: %s (%f).\n", msFast, msFst);
		printline(75);
		printf("The fastest algorithm on small dense array is: %s (%f).\n", sdFast, sdFst);
		printf("The fastest algorithm on small regular array is: %s (%f).\n", srFast, srFst);
		printf("The fastest algorithm on small sparce array is: %s (%f).\n", ssFast, ssFst);
		printline(75);
		printf("The fastest algorithm on dense arrays is: %s (%f).\n",denFast, avgFstDen);
		printf("The fastest algorithm on medium-density arrays is: %s (%f).\n",medFast, avgFstMed);
		printf("The fastest algorithm on sparce arrays is: %s (%f).\n",sprFast, avgFstSpr);
		printline(75);
		printf("The fastest large array algorithm is: %s (%f).\n",largeFast, avgFstL);
		printf("The fastest regular array algorithm is: %s (%f).\n",regFast, avgFstR);
		printf("The fastest small array algorithm is: %s (%f).\n",smlFast, avgFstS);
		printline(75);
		printf("The fastest average speed algorithm is: %s (%f).\n",avgFast, avgFst);
		printline(100);
	}
        //Free array
	free(array);
        //Exit
	return 0;
}

