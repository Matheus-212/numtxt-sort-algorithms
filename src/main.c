#include "sorting.h"
#include "filemanager.h"
#include <stdio.h>
#include <stdlib.h>

void clear_buffer(int c)
{
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void print_arrey(intArray z)
{
    for (int i = 0; i <= z.size - 1; i++)
    {
        printf("%d ", z.array[i]);
    }
}

int main()
{
    char *filename = "dados.txt";
    intArray arr = read_file(filename);
    if (arr.size != 0)
    {
        printf("dados de entrada: ");
        print_arrey(arr);
        printf("\n");
        int res = -1;
        while (res < 0 || res > 5)
        {
            printf("\nSelecione o algoritmo de ordenacao: \n");
            printf("[1] bubble\n");
            printf("[2] insertion\n");
            printf("[3] selection\n");
            printf("[4] quick\n");
            printf("[5] merge\n");
            printf("[0] cancelar");
            printf("\n-> ");
            scanf("%d", &res);
            switch (res)
            {
            case 1:
                bubble_sort(&arr);
                break;
            case 2:
                insertion_sort(&arr);
                break;
            case 3:
                selection_sort(&arr);
                break;
            case 4:
                quick_sort(&arr, 0, arr.size - 1);
                break;
            case 5:
                merge_sort(&arr);
                break;
            case 0:
                system("pause");
                return 0;
            default:
                printf("\nOpcao invalida.\n");
                break;
            }
            clear_buffer(res);
        }
        printf("dados de saida: ");
        print_arrey(arr);
        create_file_controller("ordenados", arr);
    }
    else
    {
        system("pause");
        return 1;
    }
    system("pause");
    free(arr.array);
    return 0;
}
