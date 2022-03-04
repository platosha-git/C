#include <stdio.h>
#include <stdlib.h> 
#include <limits.h>
#include <stdbool.h>
#include <stdarg.h>

#include "my_snprintf.h"

#define SIZE_BUF 50

bool equal_buffers(char *buf, char *expected_buf)
{
    bool are_equal = true;

    for (int i = 0; i < SIZE_BUF; i++)
    {
        if (buf[i] != expected_buf[i])
        {
            are_equal = false;
            break;
        }
    }    
    return are_equal;
}

void init_bufs(char *buf, char *exp_buf)
{
    for (int i = 0; i < SIZE_BUF; i++)
    {
        buf[i] = '\0';
        exp_buf[i] = '\0';
    }
}

void char_tests(char order, int buf_size, char *specificator, char argument)
{
    char buf[SIZE_BUF], expected_buf[SIZE_BUF];
    init_bufs(buf, expected_buf);
    int n = my_snprintf(buf, buf_size, specificator, argument);
    int expected = snprintf(expected_buf, buf_size, specificator, argument);

    //printf("Test %c\n", order);
    if (n == expected && equal_buffers(buf, expected_buf))
        printf("OK\n");
    else
        printf("ERROR\n");
}

int main(void) 
{
    char_tests('1', 0, "%c", 'a');
    char_tests('2', 1, "%c", 'a');
    char_tests('3', 2, "%c", 'a');
    char_tests('4', 3, "%c", ' ');
    char_tests('5', 2, "if %%c %c test\n .", 'a');
    char_tests('6', 2, "if %%c %c test\n .", 'a');
    char_tests('7', 20, "if %%c %c test\n .", 'a');
    char_tests('8', 2, "if \0 and %c test\n .", 'a');
    char_tests('9', 2, "%c", '\0');
    char_tests('0', 2, "%c", '%');
    char_tests('1', 2, "%c", '1');
    char_tests('2', 10, "%% more testd for that work", '.');

//many arguments
    char buf[SIZE_BUF], expected_buf[SIZE_BUF];
    init_bufs(buf, expected_buf);
    int n = my_snprintf(buf, 4, "%c%c%c", 'a', 'b', 'c');
    int expected = snprintf(expected_buf, 4, "%c%c%c", 'a', 'b', 'c');

    //printf("Test %c\n", order);
    if (n == expected && equal_buffers(buf, expected_buf))
        printf("OK\n");
    else
        printf("ERROR\n");

//second
    init_bufs(buf, expected_buf);
    n = my_snprintf(buf, 6, "%c %c %c", 'a', '\0', 'c');
    expected = snprintf(expected_buf, 6, "%c %c %c", 'a', '\0', 'c');

    if (n == expected && equal_buffers(buf, expected_buf))
        printf("OK\n");
    else
        printf("ERROR\n");

//third    
    init_bufs(buf, expected_buf);
    n = my_snprintf(buf, 15, "%%%c %c", 'a', 'c');
    expected = snprintf(expected_buf, 15, "%%%c %c", 'a', 'c');

    if (n == expected && equal_buffers(buf, expected_buf))
        printf("OK\n");
    else
        printf("ERROR\n");

//fourth
    /*char *null_buf = NULL;
    n = my_snprintf(null_buf, 6, "%c %c %c", 'a', '\0', 'c');
    printf("n = %d\n", n);*/

    return 0;
}
