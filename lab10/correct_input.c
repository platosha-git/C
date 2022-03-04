#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

#include "correct_input.h"
#include "exit_codes.h"

int correct_article(char *str)
{
    int exit_code = SUCCESS;
    
    if (strlen(str) == 0)
        exit_code = ARTICLE_ERR;
    if (exit_code == SUCCESS)
    {
        while (*str != '\0')
        {
            if (!isupper(*str) || !isalpha(*str))
            {
                exit_code = ARTICLE_ERR;
                printf("Article input is incorrect.\n");
                break;
            }
            str++;
        }
    }
    return exit_code;
}

int correct_name(char *str)
{
    int exit_code = SUCCESS;

    if (strlen(str) == 0)
        exit_code = NAME_ERR;
    if (exit_code == SUCCESS)
    {
        while (*str != '\0')
        {
            if (!isalpha(*str))
            {
                exit_code = NAME_ERR;
                printf("Name input is incorrect.\n");
                break;
            }
            str++;
        }
    }
    return exit_code;
}

int correct_count(int count)
{
    int exit_code = SUCCESS;

    if (count < 0)
        exit_code = COUNT_ERR;
    
    return exit_code;
}

int correct_key(char *str)
{
    int exit_code = SUCCESS;
    if (strcmp(str, "ARTICLE") && strcmp(str, "NAME") && strcmp(str, "COUNT"))
    {
        printf("Key input is incorrect.\n");
        exit_code = KEY_ERR;
    }
    return exit_code;
}
