#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <errno.h>

#include "exit_codes.h"
#include "handler_input.h"
#include "sort_matr_hand.h"
#include "handler_output.h"

int main(void)
{
    int exit_code = SUCCESS;
    
    int m = 0, n = 0;
    int **a = NULL;
    
    exit_code = in_hand_matr(&a, &n, &m);
    output_matr(&a, n, m);
    
    if (exit_code == SUCCESS)
        sort_matr(&a, n, m); 
    output_matr(&a, n, m);
    delete_matr(&a, n, m);
    return exit_code;
}