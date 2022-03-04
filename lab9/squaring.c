#include <stdio.h>
#include <stdlib.h> 

#include "squaring.h"
#include "exit_codes.h"

void squaring_matr(int ***matr, int *x, int *y)
{
    while ((*x) != (*y)) 
    {
        int max_matr_i = max_matr_row(*matr, *x, *y);
        int max_matr_j = max_matr_column(*matr, *x, *y);

        if ((*x) < (*y))
        {
            delete_column(matr, *x, *y, max_matr_j);
            (*y)--;
        }
        else 
        {
            delete_row(matr, *x, *y, max_matr_i);
            (*x)--;
        }
    }
}

int max_matr_row(int **matr, int x, int y)
{
    int max_elem = matr[0][0];
    int max_str = 0;

    for (int i = 0; i < y; i++) 
    {
        for (int j = 0; j < x; j++) 
        {
            if (matr[j][i] >= max_elem) 
            {
                max_elem = matr[j][i];
                max_str = j;
            }
        }
    }
    return max_str;
}

int max_matr_column(int **matr, int x, int y)
{
    int max_elem = matr[0][0];
    int max_column = 0;

    for (int i = 0; i < y; i++) 
    {
        for (int j = 0; j < x; j++) 
        {
            if (matr[j][i] >= max_elem) 
            {
                max_elem = matr[j][i];
                max_column = i;
            }
        }
    }
    return max_column;
}


void delete_column(int ***matr, int x, int y, int max_j)
{
    for (int i = 0; i < x; i++) 
    {
        for (int j = 0; j < y; j++) 
        {
            if (j > max_j) 
                (*matr)[i][j - 1] = (*matr)[i][j];
        }
    }

    for (int i = 0; i < x; i++) 
        (*matr)[i] = (int *)realloc((*matr)[i], (y - 1) * sizeof(int));
}

void delete_row(int ***matr, int x, int y, int max_i)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (i > max_i)
                (*matr)[i - 1][j] = (*matr)[i][j];
        }
    }
    free((*matr)[x - 1]);
    *matr = (int **)realloc(*matr, (x - 1) * sizeof(int *));
}
