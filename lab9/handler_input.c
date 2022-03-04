#include <stdio.h>
#include <stdlib.h> 

#include "handler_input.h"
#include "multiply.h"
#include "squaring.h"
#include "handler_output.h"
#include "exit_codes.h"

int read_squar_matr(int ***matr, int *x, int *y)
{
    int exit_code = creation_matr(matr, x, y);
    if (exit_code == SUCCESS)  
        squaring_matr(matr, x, y);
    else
        delete_matr(matr, *x, *y);
    return exit_code;
}

int creation_matr(int ***matr, int *x, int *y)
{
    int exit_code = get_size_pow_matr("x = ", x, 1);
    if (exit_code == SUCCESS)
    { 
        exit_code = get_size_pow_matr("y = ", y, 1);
        if (exit_code == SUCCESS)
        {   
            exit_code = create_matr(matr, *x, *y);
            if (exit_code == SUCCESS)
                input_matr(*matr, *x, *y);
            else 
                delete_matr(matr, *x, *y);
        }
        else
            delete_matr(matr, *x, *y);  
    }
    else
        delete_matr(matr, *x, *y);
    return exit_code;
}

int get_size_pow_matr(char *msg, int *elem, int border)
{
    printf("%s", msg);
    scanf("%d", elem);
    int exit_code = incorrect_input(*elem, border);
    return exit_code;
}

int create_matr(int ***matr, int x, int y) 
{
    int exit_code = SUCCESS;
    if (!matr && !(*matr) && !(**matr))
        exit_code = CREATE_MATR_ERR;
    else
    {
        *matr = (int **)malloc(x * sizeof(int *));
        for (int i = 0; i < x; i++)
            (*matr)[i] = (int *)malloc(y * sizeof(int));
        initialize_matr_by_zero(matr, x, y);
    }
    return exit_code;
}

void initialize_matr_by_zero(int ***matr, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
            (*matr)[i][j] = 0;
    }
}

int incorrect_input(int x, int y)
{
    int exit_code = SUCCESS;
    if (x < y || x >= 30)
    {
        printf("Your input is incorrect\n");
        exit_code = INPUT_ERR;
    }
    return exit_code;
}

void input_matr(int **matr, int x, int y)
{
    printf("Fill in the matrix row by row.\n\n");
    for (int i = 0; i < x; i++) 
    {
        for (int j = 0; j < y; j++) 
            scanf("%d", matr[i] + j);
            //matr[i][j] = rand() % 10;
    }
    printf("\n");
}
