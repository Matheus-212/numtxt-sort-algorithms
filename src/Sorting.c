#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(intArray *array)
{
    int aux;
    for (int i = 0; i < array->size; i++)
    {
        for (int j = 0; j < array->size - 1; j++)
        {
            if (array->array[j] > array->array[j + 1])
            {
                aux = array->array[j];
                array->array[j] = array->array[j + 1];
                array->array[j + 1] = aux;
            }
        }
    }
}

void insertion_sort(intArray *array)
{
    for (int i = 1; i < array->size; i++)
    {
        int j = i - 1, key = array->array[i];
        while (j >= 0 && array->array[j] > key)
        {
            array->array[j + 1] = array->array[j];
            j--;
        }
        array->array[j + 1] = key;
    }
}

void selection_sort(intArray *array)
{
    int aux, p;
    for (int i = 0; i < array->size; i++)
    {
        p = i;
        for (int j = i + 1; j < array->size; j++)
        {
            if (array->array[p] > array->array[j])
            {
                p = j;
            }
        }
        aux = array->array[i];
        array->array[i] = array->array[p];
        array->array[p] = aux;
    }
}

void quick_sort(intArray *array, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = array->array[end], aux;
    int j = start, i;
    for (i = start; i <= end - 1; i++)
    {
        if (array->array[i] <= pivot)
        {
            aux = array->array[j];
            array->array[j] = array->array[i];
            array->array[i] = aux;
            j++;
        }
    }
    aux = array->array[j];
    array->array[j] = array->array[i];
    array->array[i] = aux;

    quick_sort(array, start, j - 1);
    quick_sort(array, j + 1, end);
}

void merge_sort(intArray *array)
{
    if (array->size <= 1)
        return;

    int mid = array->size / 2;

    intArray left;
    intArray right;
    left.size = mid;
    right.size = array->size - mid;

    left.array = (int *)malloc(left.size * sizeof(int));
    right.array = (int *)malloc(right.size * sizeof(int));

    if (left.array == NULL || right.array == NULL)
    {
        return;
    }

    for (int i = 0; i < array->size; i++)
    {
        if (i < mid)
        {
            left.array[i] = array->array[i];
        }
        else
        {
            right.array[i - mid] = array->array[i];
        }
    }

    merge_sort(&left);
    merge_sort(&right);

    int i = 0, j = 0, k = 0;
    while (i < left.size && j < right.size)
    {
        if (left.array[i] <= right.array[j])
        {
            array->array[k] = left.array[i];
            i++;
        }
        else
        {
            array->array[k] = right.array[j];
            j++;
        }
        k++;
    }

    while (i < left.size)
    {
        array->array[k] = left.array[i];
        i++;
        k++;
    }
    while (j < right.size)
    {
        array->array[k] = right.array[j];
        j++;
        k++;
    }

    free(left.array);
    free(right.array);
}
