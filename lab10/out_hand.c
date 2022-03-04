#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "out_hand.h"
#include "exit_codes.h"

#define FILE_NAME "stockpile.txt"

int output_file(struct product **array, int size)
{
    int exit_code = SUCCESS;

    FILE *out = fopen(FILE_NAME, "w");
    if (out == NULL)
        exit_code = FILE_ERR;
    if (exit_code == SUCCESS)
    {
        for (int i = 0; i < size; i++)
        {
            fprintf(out, "%s\n", (*array)[i].article);
            fprintf(out, "%s\n", (*array)[i].name);
            fprintf(out, "%d\n", (*array)[i].count);
        }
        fclose(out);
    }
    return exit_code;
}

void free_array(struct product **array, int size)
{
    if (*array != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            free((*array)[i].article);
            free((*array)[i].name);
        }
        free((*array));
        *array = NULL;
    }
}

void output_struct(struct product **array, int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("article = %s\n", (*array)[i].article);
        printf("name = %s\n", (*array)[i].name);
        printf("count = %d\n", (*array)[i].count);
    }
}