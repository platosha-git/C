#include <stdio.h>
#include <stdlib.h> 

#include "handler_input.h"
#include "multiply.h"
#include "handler_output.h"
#include "exit_codes.h"

int multiply_handler_matr(int ***matr1, int x1, int y1, int ***matr2, int x2, int y2)
{
    int exit_code = SUCCESS;
    int r = -1, g = -1;

    int **res1 = NULL;
    int **res2 = NULL;

    if (x1 == x2 && y1 == y2)
    {
        int x = x1;
        int y = y1;
        exit_code = get_size_pow_matr("r = ", &r, 0);
        if (exit_code == SUCCESS)
        {
            exit_code = get_size_pow_matr("g = ", &g, 0);
            if (exit_code == SUCCESS)
            {
                exit_code = create_matr(&res1, x, y);
                if (exit_code == SUCCESS)
                {
                    exit_code = create_matr(&res2, x, y);
                    if (exit_code == SUCCESS)
                    {
                        if (r == 0) 
                            zero_degree_matr(matr1, x, y);

                        if (g == 0)
                            zero_degree_matr(matr2, x, y);

                        if (r > 1)
                        {
                            multiplication_matr(matr1, matr1, &res1, x, y);
                            r--;    
                        }
                        else
                        {
                            multiplication_matr(matr1, matr2, &res1, x, y);
                            r--;
                            g--;
                        }

                        matr_pow(&res1, matr1, &res2, x, y, r - 1);
                        matr_pow(&res1, matr2, &res2, x, y, g);

                        output_matr(&res1, x, y);
                    }
                    else
                    {
                        delete_matr(&res1, x, y);
                        delete_matr(&res2, x, y);
                    }
                }
                else 
                    delete_matr(&res1, x, y);
            }
            else
            {
                delete_matr(matr1, x, y);
                delete_matr(matr2, x, y);
            }
        }
        else 
        {
            delete_matr(matr1, x, y);
            delete_matr(matr2, x, y);
        }               
        delete_matr(&res1, x, y);
        delete_matr(&res2, x, y);
    }
    else
        exit_code = EXPENSION_ERR;
    return exit_code;
}

void zero_degree_matr(int ***matr, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (i == j)
                (*matr)[i][j] = 1;
            else 
                (*matr)[i][j] = 0;
        }
    }
}

void matr_pow(int ***res1, int ***matr, int ***res2, int x, int y, int pow)
{
    for (int i = 0; i < pow; i++)
    {   
        multiplication_matr(res1, matr, res2, x, y);
        assign_matr(res2, res1, x, y);
    }
}

void multiplication_matr(int ***matr1, int ***matr2, int ***res, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            (*res)[i][j] = 0;
            for (int k = 0; k < y; k++)
                (*res)[i][j] += (*matr1)[i][k] * (*matr2)[k][j];
        }
    }
}

void assign_matr(int ***matr1, int ***matr2, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            (*matr2)[i][j] = (*matr1)[i][j];
        }
    }
}
