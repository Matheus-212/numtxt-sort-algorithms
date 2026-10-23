#ifndef SORTING_H
#define SORTING_H

#include "type.h"

void bubble_sort(intArray  *array);
void insertion_sort(intArray  *array);
void selection_sort(intArray  *array);
void quick_sort(intArray  *array, int start, int end);
void merge_sort(intArray  *array);

#endif
