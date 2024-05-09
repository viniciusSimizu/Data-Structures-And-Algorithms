#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include "quicksort.h"

struct vector {
	int *arr;
	size_t size;
};

void assert_case(struct vector const *vect);
struct vector *arrangement_case_empty();
struct vector *arrangement_case_one_item();
struct vector *arrangement_case_two_items();
struct vector *arrangement_case_three_items();
struct vector *arrangement_case_many_items();
struct vector *create_arrangement(int *vect, size_t size);
struct vector *vector_cpy(struct vector const *vect);

int main() {
	size_t cases_size = 5;
	struct vector *cases[] = {
		arrangement_case_empty(),
		arrangement_case_one_item(),
		arrangement_case_two_items(),
		arrangement_case_three_items(),
		arrangement_case_many_items()
	};

	size_t acts_size = 3;
	void *acts[] = {
		quicksort,
		quicksort_tre,
		quicksort_randomized
	};

	for (int i = 0; i < acts_size; ++i) {
		for (int j = 0; j < cases_size; ++j) {
			struct vector const *case_ = cases[j];

			struct vector *case_cpy = vector_cpy(case_);
			assert_case(case_cpy);
			free(case_cpy);
		};
	}

	// Free memory
	for (size_t i = 0; i < cases_size; ++i) {
		free(cases[i]);
	};

	return 0;
};

void assert_case(struct vector const *vect) {
	for (size_t i = 0; i < vect->size - 1; ++i) {
		assert(vect->arr[i] <= vect->arr[i+1]);
	};
};

struct vector *arrangement_case_empty() {
	return create_arrangement(malloc(0), 0);
};

struct vector *arrangement_case_one_item() {
	int arr[1] = {1};
	return create_arrangement(arr, 1);
};

struct vector *arrangement_case_two_items() {
	int arr[2] = {2, -5};
	return create_arrangement(arr, 2);
};

struct vector *arrangement_case_three_items() {
	int arr[3] = {2, -5, 3};
	return create_arrangement(arr, 3);
};

struct vector *arrangement_case_many_items() {
	int arr[10] = {2, 1, 45, 2, 6, 2, 3, 5, 1, 0};
	return create_arrangement(arr, 10);
};

struct vector *create_arrangement(int *vect, size_t size) {
	struct vector *arrange = malloc(sizeof(struct vector));
	arrange->size = size;
	arrange->arr = malloc(size * sizeof(int));
	for (int i = 0; i < size; ++i) {
		arrange->arr[i] = vect[i];
	};

	return arrange;
};

struct vector *vector_cpy(struct vector const *vect) {
	struct vector *vect_cpy = malloc(sizeof(struct vector));
	vect_cpy->size = vect->size;
	vect_cpy->arr = malloc(vect->size * sizeof(int));
	memcpy(vect_cpy->arr, vect->arr, vect->size * sizeof(int));
	return vect_cpy;
};
