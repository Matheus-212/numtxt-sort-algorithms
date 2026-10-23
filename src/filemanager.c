#include "filemanager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_erro(const char *text)
{
    printf("\033[31merro: %s\033[0m\n", text);
}

intArray read_file(const char *file)
{
    FILE *fp = fopen(file, "r");
    intArray p;
    p.size = 0;
    p.array = NULL;
    if (fp == NULL)
    {
        char erro[30] = {"nao encontrado \0"};
        strcat(erro, file);
        print_erro(erro);
        return p;
    }
    int n, i = 0, base = 10;
    p.array = (int *)malloc(base * sizeof(int));
    if (p.array == NULL)
    {
        print_erro("Falha na alocacao de memoria!");
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
    if (i == 0)
    {
        char erro[30] = {"Numeros nao encontrados em \0"};
        strcat(erro, file);
        print_erro(erro);
    }
    p.size = i;
    fclose(fp);
    return p;
}

void create_file(const char *file, intArray array)
{
    FILE *fp = fopen(file, "w");
    if (fp == NULL)
    {
        print_erro("Falha ao criar/abrir o arquivo especificado");
        return;
    }
    for (int i = 0; i <= array.size - 1; i++)
    {
        fprintf(fp, "%d ", array.array[i]);
    }
    printf("\nfinalizado o arquivo %s\n", file);
    fclose(fp);
}

int check_existence(const char *name)
{
    char file[40];
    snprintf(file, sizeof(file), "%s.txt", name);
    FILE *fp = fopen(file, "r");
    printf("\n%s ", file);
    if (fp == NULL)
    {
        printf(" 0\n");
        return 0; // doesn't exist
    }
    else
    {
        printf(" 1\n");
        return 1; // exist
    }
}
void ger(const char *namefile, intArray array)
{
    int res = -1;
    while (res < 0 || res > 2)
    {
        printf("\nDeseja criar %s.txt\n", namefile);
        printf("[1] Sim, [0] Nao\n");
        printf("-> ");
        scanf("%d", &res);
        switch (res)
        {
        case 1:
            int check = check_existence(namefile);
            char file[40];
            if (check == 0)
            {
                snprintf(file, sizeof(file), "%s.txt", namefile);
                create_file(file, array);
            }
            else
            {
                int res = 3;
                while (res < 0 || res > 2)
                {
                    printf("\nArquivo de mesmo nome(%s.txt)\n", namefile);
                    printf("[1] Substituir, [2] Criar um novo, [0] Cancelar\n");
                    printf("-> ");
                    scanf("%d", &res);
                    switch (res)
                    {
                    case 1:
                        snprintf(file, sizeof(file), "%s.txt", namefile);
                        create_file(file, array);
                        break;
                    case 2:
                        int n = 0, key = 1;
                        while (key != 0)
                        {
                            n++;
                            snprintf(file, sizeof(file), "%s%d", namefile, n);
                            key = check_existence(file);
                        }
                        snprintf(file, sizeof(file), "%s%d.txt", namefile, n);
                        create_file(file, array);
                        break;
                    case 0:
                        break;
                    default:
                        printf("\nOpcao invalida.\n");
                        break;
                    }
                }
            }
            break;
        case 0:
            break;
        default:
            printf("\nOpcao invalida.\n");
            break;
        }
    }
}
