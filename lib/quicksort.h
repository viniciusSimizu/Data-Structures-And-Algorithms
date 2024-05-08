#ifndef QUICKSORT_H
#define QUICKSORT_H

unsigned int quicksort_hoare_partition(int *arr, unsigned int i, unsigned int j);
void quicksort(int *arr, unsigned int i, unsigned int j);
void quicksort_randomized(int *arr, unsigned int i, unsigned int j);
void quicksort_tre(int *arr, unsigned int i, unsigned int j);

#endif
