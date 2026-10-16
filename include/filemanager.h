#ifndef filemanager_H
#define filemanager_H

typedef struct
{
    int size;
    int *array;
} arraybase;

arraybase input(const char *file);
void output(const char *file, arraybase arr);

#endif
