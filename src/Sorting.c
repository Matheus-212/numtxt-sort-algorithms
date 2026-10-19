#include "sorting.h"

void bubble(arraybase z)
{
    int aux;
    for(int i = 0; i < z.size; i++){
        for(int j = 0; j < z.size - 1; j++){
            if(z.array[j] > z.array[j+1]){
                aux = z.array[j];
                z.array[j] = z.array[j+1];
                z.array[j+1] = aux;
            }
        }
    }
}

void insertion(arraybase z)
{
    for (int i = 1; i < z.size; i++)
    {
        int j = i - 1, key = z.array[i];
        while (j >= 0 && z.array[j] > key)
        {
            z.array[j + 1] = z.array[j];
            j--;
        }
        z.array[j + 1] = key;
    }
}

void selection(arraybase z)
{
    int aux, p;
    for (int i = 0; i < z.size; i++)
    {
        p = i;
        for (int j = i + 1; j < z.size; j++)
        {
            if (z.array[p] > z.array[j])
            {
                p = j;
            }
        }
        aux = z.array[i];
        z.array[i] = z.array[p];
        z.array[p] = aux;
    }
}

void merge(arraybase z)
{}

void quick(arraybase z)
{}
