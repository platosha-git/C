#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#include "in_hand.h"
#include "exit_codes.h"
#include "correct_input.h"

int input_handler(struct product **array, int *size)
{
    int exit_code = SUCCESS;
    int max_size = 1;

    *array = (struct product *) malloc(max_size * sizeof(struct product));

    while (1)
    {
        char *article = get_string("Input article");
        if (strcmp(article, "nothing") == 0 || strcmp(article, "NOTHING") == 0)
        {
            free(article);
            break;
        }

        exit_code = correct_article(article);
        if (exit_code == SUCCESS)
        {
            char *name = get_string("Input name");
            exit_code = correct_name(name);

            if (exit_code == SUCCESS)
            {
                int count = 0;
                printf("\nInput count\n");
                scanf("%d", &count);

                exit_code = correct_count(count);

                if (exit_code == SUCCESS)
                {
                    node_constructor(size, &max_size, array, article, name, count);
                    getchar();
                }
                else
                {
                    free(article);
                    free(name);
                    break;
                }
            } 
            else
            {            
                free(article);
                free(name);
                break; 
            }
        }
        else
        {
            free(article);
            break;
        }
    }
    *array = (struct product *) realloc(*array, *size * sizeof(struct product));
    return exit_code;
}

char *get_string(char *msg)
{
    printf("\n%s\n", msg);
    char *str = (char *) malloc(sizeof(char));
    str[0] = '\0';

    char symb;
    int i = 0;
    while (scanf("%c", &symb) == 1)
    {
        i++;
        str = (char *) realloc(str, i * sizeof(char));
        if (symb != '\n')
        {
            str[i - 1] = symb;
        }
        else
        {
            str[i - 1] = '\0';
            break;
        }
    }
    return str;
}

void node_constructor(int *size, int *max_size, struct product **array, char *article, char *name, int count)
{
    if (*size == *max_size)
    {
        *max_size *= 2;
        *array = (struct product *) realloc(*array, *max_size * sizeof(struct product));        
    }

    (*array)[*size].article = article;
    (*array)[*size].name = name;
    (*array)[*size].count = count;
       
    (*size)++;
}