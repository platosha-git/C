#include <stdio.h>
#include <stdlib.h> 

#include "handler_output.h"

void delete_matr(int ***matr, int x, int y) 
{
    if (*matr != NULL) 
    {
        for (int i = 0; i < x; i++)
            free((*matr)[i]);
        free(*matr);
        *matr = NULL;
    }
}

void output_matr(int ***matr, int x, int y) 
{
    printf("\n");
    for (int i = 0; i < x; i++) 
    {
        for (int j = 0; j < y; j++)
            printf("%d  ", (*matr)[i][j]);
        printf("\n");
    }
    printf("\n");
}
