#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

int countArrayLength(char* inputfile) {
	int result = 0;
	int temp;
	FILE *file = NULL;
	file = fopen(inputfile, "r");

	if (file != NULL) {
		while (!feof(file)){
			fscanf(file, "%d\n", &temp);
			result++;
		}
		fclose(file);
	}
	else {
		printf("!] FILE OPEN ERROR\n");
		exit(1);
	}

	return result-1;

}

int* readTxtfile(char* inputfile, int length) {
	int* tempArray = (int*)malloc(sizeof(int)*length);
	int temp;
	int i = 0;

	FILE *file = NULL;
	file = fopen(inputfile, "r");

	if (file != NULL) {
		while (!feof(file)) {
			fscanf(file, "%d\n", &temp);
			tempArray[i] = temp;
			i++;
		}
	}
	else {
		printf("!] FILE OPEN ERROR\n");
		exit(1);
	}

	return tempArray;
}

void writeTxtFile(int* sortedArray, char* outputfilename, int length) {
	FILE *writeFile = NULL;
	int i;
	writeFile = fopen(outputfilename, "w");
	
	if (writeFile != NULL) {
		for (i = 0; i < length; i++) {
			fprintf(writeFile, "%d\n", sortedArray[i]);
		}
		fclose(writeFile);
	}
	else {
		printf("!] FILE OPEN ERROR\n");
		exit(1);
	}
}

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

	int count = countArrayLength(inputFileName);

	int* readfile = readTxtfile(inputFileName, count);

	int* sortedArray = insertionSort(readfile, count);

	writeTxtFile(sortedArray, outpuFileName, count);
	printf("!] Sucess! \n");
}