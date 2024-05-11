#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include "quicksort.h"

struct test_vector {
	int *arr;
	int size;
};

void assert_case(struct test_vector const *vect);
struct test_vector *arrangement_case_empty();
struct test_vector *arrangement_case_one_item();
struct test_vector *arrangement_case_two_items();
struct test_vector *arrangement_case_three_items();
struct test_vector *arrangement_case_many_items();
struct test_vector *create_arrangement(int *vect, int size);
struct test_vector *vector_cpy(struct test_vector const *vect);
void test_free_vector(struct test_vector *vect);

int main() {
	struct test_vector *cases[] = {
		arrangement_case_empty(),
		arrangement_case_one_item(),
		arrangement_case_two_items(),
		arrangement_case_three_items(),
		arrangement_case_many_items()
	};

	void (*acts[])(int*, int, int) = {
		quicksort,
		quicksort_tre,
		quicksort_randomized
	};

	int cases_size = sizeof(cases) / sizeof(void*);
	int acts_size = sizeof(acts) / sizeof(void*);

	for (int i = 0; i < acts_size; ++i) {
		for (int j = 0; j < cases_size; ++j) {
			struct test_vector const *case_ = cases[j];
			struct test_vector *case_cpy = vector_cpy(case_);

			(*acts[i])(case_cpy->arr, 0, case_cpy->size-1);

			assert_case(case_cpy);
			test_free_vector(case_cpy);
		};
	}

	// Free memory
	for (int i = 0; i < cases_size; ++i) {
		test_free_vector(cases[i]);
	};

	return 0;
};

void assert_case(struct test_vector const *vect) {
	for (int i = 0; i < vect->size - 1; ++i) {
		assert(vect->arr[i] <= vect->arr[i+1]);
	};
};

struct test_vector *arrangement_case_empty() {
	int arr[0] = {};
	return create_arrangement(arr, 0);
};

struct test_vector *arrangement_case_one_item() {
	int arr[1] = {1};
	return create_arrangement(arr, 1);
};

struct test_vector *arrangement_case_two_items() {
	int arr[2] = {2, -5};
	return create_arrangement(arr, 2);
};

struct test_vector *arrangement_case_three_items() {
	int arr[3] = {2, -5, 3};
	return create_arrangement(arr, 3);
};

struct test_vector *arrangement_case_many_items() {
	int arr[10] = {2, 1, 45, 2, 6, 2, 3, 5, 1, 0};
	return create_arrangement(arr, 10);
};

struct test_vector *create_arrangement(int *vect, int size) {
	struct test_vector *arrange = malloc(sizeof(struct test_vector));
	arrange->size = size;
	arrange->arr = malloc(size * sizeof(int));
	for (int i = 0; i < size; ++i) {
		arrange->arr[i] = vect[i];
	};

	return arrange;
};

struct test_vector *vector_cpy(struct test_vector const *vect) {
	struct test_vector *vect_cpy = malloc(sizeof(struct test_vector));
	vect_cpy->size = vect->size;
	vect_cpy->arr = malloc(vect->size * sizeof(int));
	memcpy(vect_cpy->arr, vect->arr, vect->size * sizeof(int));
	return vect_cpy;
};

void test_free_vector(struct test_vector *vect) {
	free(vect->arr);
	free(vect);
};
