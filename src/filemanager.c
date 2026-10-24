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
        char *erro = (char *)malloc(strlen("nao encontrado ") + strlen(file) + 1);
        if (erro != NULL) {
            strcpy(erro, "nao encontrado ");
            strcat(erro, file);
            print_erro(erro);
            free(erro);
        } else {
            print_erro("nao encontrado (erro ao alocar mensagem)");
        }
        return p;
    }

    // Alocação inicial do array dinâmico
    int i = 0, base = 2;
    p.array = (int *)malloc(base * sizeof(int));
    if (p.array == NULL)
    {
        print_erro("Falha na alocacao de memoria!");
        fclose(fp);
        return p;
    }

    // Buffer para ler o conteúdo do arquivo
    // Usamos uma estratégia de ler o arquivo em blocos ou linha por linha
    char linha[1024];

    while (fgets(linha, sizeof(linha), fp) != NULL)
    {
        char *ptr = linha;
        char *endptr;

        while (*ptr != '\0')
        {
            // strtol converte o número e move endptr para o primeiro caractere após o número
            long n = strtol(ptr, &endptr, 10);

            // Se ptr e endptr forem iguais, significa que nenhum número foi lido nesta posição
            if (ptr == endptr) {
                // Avança um caractere (pode ser uma vírgula, espaço, letra, etc.) e tenta de novo
                ptr++;
                continue;
            }

            // Se chegamos aqui, um número válido foi extraído
            if (i >= base)
            {
                base *= 2;
                int *temp = (int *)realloc(p.array, base * sizeof(int));
                if (temp == NULL) {
                    print_erro("Falha na realocacao de memoria!");
                    free(p.array);
                    p.array = NULL;
                    p.size = 0;
                    fclose(fp);
                    return p;
                }
                p.array = temp;
            }

            p.array[i] = (int)n;
            i++;

            // Avança o ponteiro de leitura para onde o strtol parou
            ptr = endptr;
        }
    }

    // Se nenhum número foi encontrado no arquivo inteiro
    if (i == 0)
    {
        char erro[512];
        snprintf(erro, sizeof(erro), "Numeros nao encontrados em %s", file);
        print_erro(erro);
        free(p.array);
        p.array = NULL;
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
    if (fp == NULL)
    {
        return 0; // doesn't exist
    }
    else
    {
        return 1; // exist
    }
}
void create_file_controller(const char *namefile, intArray array)
{
    int res = -1;
    while (res < 0 || res > 2)
    {
        printf("\n\nDeseja criar %s.txt\n", namefile);
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
