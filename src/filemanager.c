#include "filemanager.h"
#include <stdio.h>

arraybase input(const char *file)
{
    FILE *fp = fopen(file, "r");
    arraybase p;
    p.size = 0;
    p.array = NULL;
    if (fp == NULL)
    {
        printf("ERRO! arquivo não encontrado\n");
        return p;
    }
    int n, i = 0, base = 10;
    p.array = (int *)malloc(base * sizeof(int));
    if (p.array == NULL)
    {
        printf("Erro de alocação de memória!\n");
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
    p.size = i;
    fclose(fp);
    return p;
}

void output(const char *file, arraybase arr)
{
    FILE *fp = fopen(file, "w");
    if (fp == NULL)
    {
        abrir_erro();
        printf("erro: falha ao criar/abrir o arquivo especificado\n");
        fechar_erro();
    }
    for (int i = 0; i <= arr.size - 1; i++)
    {
        fprintf(fp, "%d ", arr.array[i]);
    }
    fclose(fp);
}
