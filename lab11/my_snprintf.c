#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#include "my_snprintf.h"

void write_to_buffer(char *buffer, int buf_size, int *index, char argument)
{
    if (*index < buf_size - 1 && buffer != NULL)
        buffer[*index] = argument;
    (*index)++;
}

void init_buf(char *buf, int buf_size)
{
    for (int i = 0; i < buf_size && buf; i++)
        buf[i] = '\0';
}

int my_snprintf(char *buffer, int buf_size, char *format, ...)
{
    init_buf(buffer, buf_size);
    
    va_list ptr;
    va_start(ptr, format);
    
    int i = 0;
    for (char *symb = format; *symb; symb++) 
    {
        if (*symb == '%')
        {
            symb++;
            if (*symb == 'c')
            {
                char argument = va_arg(ptr, int); 
                write_to_buffer(buffer, buf_size, &i, argument);
                continue;
            }

            write_to_buffer(buffer, buf_size, &i, '%');
            continue;
        }
        write_to_buffer(buffer, buf_size, &i, *symb);
    }
    va_end(ptr);
    if (buffer)
        buffer[i] = '\0';
    
    return i;
}
