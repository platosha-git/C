#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
    
#include "in_hand.h"
#include "correct_input.h"  
#include "changes.h"
#include "out_hand.h"
#include "exit_codes.h"

int main(void)
{    
    int size = 0;
    int exit_code = SUCCESS;

    struct product *products_array = NULL;
    
    exit_code = input_handler(&products_array, &size);
    if (exit_code == SUCCESS)
    {
        string_concat(&products_array, size);
        exit_code = remove_product(&products_array, &size); 
        if (exit_code == SUCCESS && size > 0)
        {
            exit_code = sort_products(&products_array, size);
            if (exit_code == SUCCESS)
                exit_code = output_file(&products_array, size);
        }
    }
    free_array(&products_array, size);
    return exit_code;
}

