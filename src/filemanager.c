#include "filemanager.h"
#include <stdio.h>
#include <stdlib.h>

arraybase input(const char *file)
{
    FILE *fp = fopen(file, "r");
    arraybase p;
    p.size = 0;
    p.array = NULL;
    if (fp == NULL)
    {
        printf("Erro: %s nao encontrado\n", file);
        return p;
    }
    int n, i = 0, base = 10;
    p.array = (int *)malloc(base * sizeof(int));
    if (p.array == NULL)
    {
        printf("Erro: falha na alocacao de memoria!\n");
        fclose(fp);
        return p;
    }
    while (fscanf(fp, "%d", &n) == 1)
    {
        if (i >= base)
        {
            base *= 2;
            p.array = (int *)realloc(p.array, base * sizeof(int));
        }
        p.array[i] = n;
        i++;
    }
    if(i == 0){
        printf("Erro: numeros nao encontrados em %s.\n",file);
    }
    p.size = i;
    fclose(fp);
    return p;
}

void output(const char *file, arraybase arr)
{
    FILE *fp = fopen(file, "w");
    if (fp == NULL)
    {
        printf("Erro: falha ao criar/abrir o arquivo especificado\n");
    }
    for (int i = 0; i <= arr.size - 1; i++)
    {
        fprintf(fp, "%d ", arr.array[i]);
    }
    fclose(fp);
}
