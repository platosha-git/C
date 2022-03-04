#include <stdio.h>
#include <stdlib.h> 
#include <math.h> 

#include "expansion.h"
#include "exit_codes.h"

void matrix_expansion(int ***matr1, int *x1, int *y1, int ***matr2, int *x2, int *y2)
{
    while (*x1 != *x2)
    {       
        if (*x2 > *x1)
            expand_one_matr_to_another(matr1, x1, y1, x2, y2);
        else 
            expand_one_matr_to_another(matr2, x2, y2, x1, y1);
    }
}

void expand_one_matr_to_another(int ***matr, int *x, int *y, int *to_x, int *to_y)
{
    while (*x != *to_x)
    {
        insert_row(matr, x, y);
        (*x)++;
    }
    while (*y != *to_y)
    {
        insert_column(matr, x, y);
        (*y)++;
    }
}

void insert_row(int ***matr, int *row_size_matr, int *column_size_matr)
{
    *matr = (int **)realloc(*matr, (*row_size_matr + 1) * sizeof(int *));
    (*matr)[*row_size_matr] = (int *)malloc(*column_size_matr * sizeof(int));

    insert_row_average(matr, *row_size_matr, *column_size_matr);
}

void insert_row_average(int ***matr, int x, int y)
{
    int sum = 0;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            sum += (*matr)[j][i];
        if (sum < 0 && sum % x != 0)
        {
            sum /= x;
            sum--;
        }
        else
            sum /= x;
        (*matr)[x][i] = sum; 
        sum = 0;
    }
}

void insert_column(int ***matr, int *row_size_matr, int *column_size_matr)
{
    for (int i = 0; i < *row_size_matr; i++) 
        (*matr)[i] = (int *)realloc((*matr)[i], (*column_size_matr + 1) * sizeof(int));

    insert_min_column(matr, *row_size_matr, *column_size_matr);
}

void insert_min_column(int ***matr, int x, int y)
{
    int min = 0;
    for (int i = 0; i < x; i++)
    {
        min = (*matr)[i][0];
        for (int j = 0; j < y; j++)
        {
            if ((*matr)[i][j] < min) 
                min = (*matr)[i][j];
        }
        (*matr)[i][y] = min;
    }   
}
