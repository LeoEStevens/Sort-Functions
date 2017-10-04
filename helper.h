//Helper Functions

//Print line spacer
void printline(int num) {
	for(int i = 0; i < num; i++) {
		printf("=");
	}
	printf("\n");
}
//Fill an array with rand num
int* createArray(int array[], int size, int max) {	
	time_t t;
	srand((unsigned) time(&t));
	for(int i = 0; i < size; i++) {
		array[i] = rand() % max;
	}
	return array;
}
//Print an array
void printArray(int array[], int size) {
	int counter = 0;
	for(int i = 0; i < size; i++) {
		if(counter  == 5) {
			printf("\n");
			counter = 0;
		}
		printf("Array[%lli]= %li\t\t\t", i, array[i]);
		counter++;
	}
	printf("\n");
}

//Swap ints at two indexes
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//Array partition for splitting array
int partition(int array[], int low, int high) {
	int pivot = array[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if(array[j] <= pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}
