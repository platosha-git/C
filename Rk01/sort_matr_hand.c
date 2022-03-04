#include <stdio.h>
#include <stdlib.h> 

#include "sort_matr_hand.h"
#include "handler_input.h"
#include "exit_codes.h"

void sort_matr(int ***matr, int x, int y)
{
    for (int k = 0; k < x * y; k++)
    {
        for (int i = 0; i < x - 1; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (j != x - 1)
                {
                    if ((*matr)[i][j + 1] < (*matr)[i][j])
                        swap((*matr)[i][j + 1], (*matr)[i][j]);                 
                }
                else
                {
                    if ((*matr)[i + 1][0] < (*matr)[i][j] && (i != x - 1))
                        swap((*matr)[i + 1][0], (*matr)[i][j]);
                }
            }
        }
    }
}

void swap(int elem1, int elem2)
{
	int temp = elem1;
    elem1 = elem2;
	elem2 = temp;
}

void sort_increase(int ***matr, int x, int y, int i)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < y - 1; j++)
        {
            if ((*matr)[i][j] > (*matr)[i][j + 1])
            {
                int temp = (*matr)[i][j];
                (*matr)[i][j] = (*matr)[i][j + 1];
                (*matr)[i][j + 1] = temp;
            }
        }
    }
}

void sort_decrease(int ***matr, int x, int y, int i)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < y - 1; j++)
        {
            if ((*matr)[i][j] < (*matr)[i][j + 1])
            {
                int temp = (*matr)[i][j];
                (*matr)[i][j] = (*matr)[i][j + 1];
                (*matr)[i][j + 1] = temp;
            }
        }
    }
}