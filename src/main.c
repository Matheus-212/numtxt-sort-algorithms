#include "sorting.h"
#include "filemanager.h"
#include <stdio.h>
#include <stdlib.h>

void printArrey(arraybase z)
{
    for (int i = 0; i <= z.size - 1; i++)
    {
        printf("%d ", z.array[i]);
    }
}

void clearBuffer(int c) {
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main()
{
    char *filename = "dados.txt";
    arraybase arr = input(filename);
    if (arr.size != 0)
    {
        printf("dados de entrada: ");
        printArrey(arr);
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
            printf("[0] cancelar\n");
            printf("-> ");
            scanf("%d", &res);
            switch (res)
            {
            case 1:
                bubble(&arr);
                break;
            case 2:
                insertion(&arr);
                break;
            case 3:
                selection(&arr);
                break;
            case 4:
                quick(&arr, 0, arr.size-1);
                break;
            case 5:
                merge(&arr);
                break;
            case 0:
                system("pause");
                return 0;
            default:
                printf("\nOpcao invalida.\n");
                break;
            }
            clearBuffer(res);
        }
        printf("dados de saida: ");
        printArrey(arr);
        printf("\n");
        output("ordenados.txt", arr);
    }
    else
    {
        system("pause");
        return 1;
    }
    system("pause");
    return 0;
}
