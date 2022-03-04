#include <stdio.h>
#include <stdlib.h> 

#include "exit_codes.h"
#include "structs.h"
#include "size_pixels.h"

#define BMP_FILE "winter.bmp"

int main(void)
{    
    int exit_code = SUCCESS;

    FILE *filename = NULL;
    filename = fopen(BMP_FILE, "rb");
    if (filename == NULL)
    	exit_code = FILE_ERROR;
    if (exit_code == SUCCESS)
    {
    	read_size_pixels(filename);
    	fclose(filename);
    }
    return exit_code;
}

