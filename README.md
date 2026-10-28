# Entrega N° III — Algoritmos de Ordenação e Manipulação de Arquivos em C

Este projeto consiste na implementação de cinco algoritmos clássicos de ordenação de dados em linguagem C, integrados a um sistema modular de manipulação e gerenciamento de arquivos de texto (`.txt`).

O sistema realiza a leitura de dados numéricos desordenados a partir de um arquivo de entrada, exibe as etapas e resultados no terminal, ordena a estrutura em memória e permite que o usuário decida como e onde salvar o resultado final.

---

## Integrantes do Grupo

- **Erick da Silva Elias** — 47676779
- **Fabricio Coutinho** — 4795228
- **Marcella Flandes Souza De Mello** — 48386278
- **Matheus Mendes Fagundes** — 48296457

---

## Estrutura do Projeto

O projeto foi organizado de forma modular para promover o desacoplamento de código, facilitando a manutenção e expansão.

```text
meu-projeto/
├── .gitignore
├── Makefile
├── README.md
├── bin/
├── build/
├── include/
│   ├── filemanager.h
│   ├── sorting.h
│   └── type.h
└── src/
    ├── filemanager.c
    ├── sorting.c
    └── main.c
```

### Descrição dos Módulos

- **`include/type.h`**: Contém a definição da estrutura principal (`intArray`) que armazena os dados numéricos e a capacidade do vetor alocado dinamicamente.
- **`include/filemanager.h` & `src/filemanager.c`**: Módulo encarregado da leitura e validação de arquivos de entrada (`.txt`), além do controle de sobrescrita e numeração sequencial dos arquivos gerados.
- **`include/sorting.h` & `src/sorting.c`**: Implementação dos algoritmos de ordenação:
  1. **Bubble Sort**
  2. **Insertion Sort**
  3. **Selection Sort**
  4. **Quick Sort**
  5. **Merge Sort**
- **`src/main.c`**: Ponto de entrada do programa que interage com o usuário por meio de um menu no terminal e orquestra as chamadas dos módulos.

---

## Destaques Técnicos & Decisões de Projeto

### 1. Definição Centralizada do Tipo de Dado (`type.h`)

```c
typedef struct
{
    int size;
    int *array;
} intArray;
```

**Justificativa:** O tipo `intArray` foi isolado em seu próprio arquivo de cabeçalho (`type.h`) porque ele representa o tipo de dado fundamental consumido por todos os outros módulos (`main.c`, `filemanager.c`, `sorting.c`). Centralizar essa estrutura garante facilidade de manutenção: caso ocorra qualquer modificação nos atributos do vetor dinâmico, a alteração é feita em um único ponto, prevenindo inconsistências e erros de compilação cruzada.

### 2. Checagem e Controle de Arquivos (`check_existence`)

```c
int check_existence(const char *name)
{
    char file[40];
    snprintf(file, sizeof(file), "%s.txt", name);
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        return 0; // Não existe
    }
    else
    {
        fclose(fp);
        return 1; // Existe
    }
}
```

**Justificativa:** A função `check_existence` verifica a presença prévia de arquivos com o nome informado no diretório antes de gravar novos dados. Essa checagem concede ao usuário controle total sobre o gerenciamento dos seus arquivos de saída. Ao tentar salvar o resultado da ordenação (por padrão `ordenados.txt`), o sistema oferece opções claras:
- **Substituir** o arquivo existente.
- **Criar um novo arquivo** incrementado automaticamente (ex: `ordenados1.txt`, `ordenados2.txt`).
- **Cancelar** a operação sem perder os dados da execução.

---

## Como Compilar e Executar

### Pré-requisitos
- Compilador **GCC** instalado.
- Ferramenta **Make** (opcional, para compilação automatizada).

### Compilando via Makefile

Na raiz do projeto, execute:

```bash
make
```

O comando irá compilar os fontes presentes em `src/`, utilizar os cabeçalhos de `include/`, salvar os objetos em `build/` e gerar o executável dentro da pasta `bin/`.

### Compilação Manual (sem Make)

Caso prefira compilar manualmente pelo terminal:

```bash
gcc -Iinclude src/filemanager.c src/sorting.c src/main.c -o bin/program
```

---

## Execução do Programa

1. Certifique-se de que o arquivo de entrada `dados.txt` com numeros esteja no mesmo diretório do arquivo executável.
2. Execute o binário gerado:

```bash
./bin/program
```

3. Acompanhe a impressão dos números lidos no terminal.
4. Escolha no menu interativo qual algoritmo de ordenação deseja aplicar (Bubble, Insertion, Selection, Quick ou Merge).
5. Defina no controle de arquivos se deseja salvar a saída ordenada em um arquivo `.txt`.
