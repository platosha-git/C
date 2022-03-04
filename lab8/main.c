#include <stdio.h>
#include <stdlib.h> 

#include "exit_codes.h"
#include "handler_input.h"
#include "operations.h"
#include "handler_output.h"

int main(void)
{
    int exit_code = SUCCESS;
    
    int n = 0;
    double *a = NULL;
    
    exit_code = create_fill_matr(&a, &n);
    if (exit_code == SUCCESS)
    	first_func(&a, n);

    output_matr(&a, n);
    
    
    delete_matr(&a, n);
    return exit_code;
}
