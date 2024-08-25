#include <stdlib.h>
#include "quicksort.h"

void quicksort_swap(int *arr, int i, int j);
void quicksort_choose_rand(int *arr, int i, int j);

int quicksort_hoare_partition(int *arr, int i, int j) {
	int pivot = j;
	int left = i - 1;
	int right = j;

	while (1) {
		do { ++left; } while (left < j && arr[left] <= arr[pivot]);
		do { --right; } while (right > 0 && arr[right] > arr[pivot]);
		if (left >= right) {
			quicksort_swap(arr, left, j);
			return left;
		};
		quicksort_swap(arr, left, right);
	};
};

void quicksort(int *arr, int i, int j) {
	if (i < j) {
		int idx = quicksort_hoare_partition(arr, i, j);
		quicksort(arr, i, idx-1);
		quicksort(arr, idx+1, j);
	};
};

void quicksort_randomized(int *arr, int i, int j) {
	if (i < j) {
		quicksort_choose_rand(arr, i, j);
		int idx = quicksort_hoare_partition(arr, i, j);
		quicksort_randomized(arr, i, idx-1);
		quicksort_randomized(arr, idx+1, j);
	};
};

void quicksort_tre(int *arr, int i, int j) {
	while (i < j) {
		int idx = quicksort_hoare_partition(arr, i, j);
		quicksort_tre(arr, i, idx-1);
		i = idx + 1;
	};
};

void quicksort_swap(int *arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
};

void quicksort_choose_rand(int *arr, int i, int j) {
	int size = j - i;
	int idx = i + (size * rand() / RAND_MAX);
	quicksort_swap(arr, idx, j);
};
