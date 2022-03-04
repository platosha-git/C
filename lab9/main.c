#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <errno.h>

#include "handler_input.h"
#include "squaring.h"
#include "expansion.h"
#include "multiply.h"
#include "handler_output.h"
#include "exit_codes.h"

int main(void)
{
    int exit_code = SUCCESS;
    
    int m = 0, n = 0;
    int **a = NULL;

    int p = 0, q = 0;
    int **b = NULL;
    
    exit_code = read_squar_matr(&a, &n, &m);
    
    if (exit_code == SUCCESS)
    {
        exit_code = read_squar_matr(&b, &p, &q);
        if (exit_code == SUCCESS)
        {
            matrix_expansion(&a, &n, &m, &b, &p, &q);
            exit_code = multiply_handler_matr(&a, n, m, &b, p, q);
        }
        else
        {
            delete_matr(&a, n, m);
            delete_matr(&b, p, q);
        }
    }    
    delete_matr(&a, n, m);
    delete_matr(&b, p, q);
    return exit_code;
}
