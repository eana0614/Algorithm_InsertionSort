#define _CRT_SECURE_NO_DEPRECATE

#include "rwchead.h"

int* insertionSort(int* inputArray, int length) {
	int i, j, key = 0;

	for (i=1; i<length; i++) {
		key = inputArray[i];
		j = i - 1;
		while (j >= 0 && inputArray[j] > key) {
			inputArray[j + 1] = inputArray[j];
			j = j - 1;
		}
		inputArray[j + 1] = key;
	}

	return inputArray;

}

int main(void) {

	char* inputFileName = "random.txt";
	char* outpuFileName = "c insertion sort.txt";

	int count = countElement(inputFileName);

	int* readfile = readTxtfile(inputFileName, count);

	int* sortedArray = insertionSort(readfile, count);

	writeTxtFile(sortedArray, outpuFileName, count);
	printf("!] Sucess! \n");
}