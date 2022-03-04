#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

#include "changes.h"
#include "correct_input.h"
#include "exit_codes.h"
#include "out_hand.h"

#define REMOVE "LIPSTICK"

void string_concat(struct product **array, int size)
{
    for (int i = 0; i < size; i++)
    { 
        int len1 = strlen((*array)[i].article);
        int len2 = strlen((*array)[i].name);
        (*array)[i].article = realloc((*array)[i].article, (len1 + len2 + 1) * sizeof(char));
        
        for (int j = 0; j < len2; j++)
            (*array)[i].article[len1 + j] = (*array)[i].name[j];
        (*array)[i].article[len1 + len2] = '\0';

        to_upp((*array)[i].article); 
    }
}

void to_upp(char *str)
{
    while (*str != '\0')
    {
        *str = toupper(*str);
        str++;
    }
}

int remove_product(struct product **array, int *size)
{
    int exit_code = SUCCESS;

    for (int i = 0; i < *size; i++)
    {
        if (strcmp((*array)[i].article, REMOVE) == 0 && (*array)[i].count == 0)
        {
            free((*array)[i].article);
            free((*array)[i].name);
            for (int j = i; j < *size - 1; j++)
                (*array)[j] = (*array)[j + 1];
            *array = (struct product *)realloc(*array, (*size) * sizeof(struct product));
            (*size)--;
        }
        exit_code = case_zero_array(array, size);
    }
    return exit_code;
}

int case_zero_array(struct product **array, int *size)
{
    int exit_code = SUCCESS;
    if (*size <= 1)
    {
        if (*size == 1)
        {
            if (strcmp((*array)[0].article, REMOVE) == 0 && (*array)[0].count == 0)
            {
                free_array(array, *size);
                *size = 0;
            }
        }
        char *key = get_string("Input key");
        exit_code = correct_key(key);
        free(key);
        exit_code = EMPTY_ERR;
    }
    return exit_code;
}

int sort_products(struct product **array, int size)
{
    int exit_code = SUCCESS;
    char *key = get_string("Input key");
    exit_code = correct_key(key);

    if (exit_code == SUCCESS)
    { 
        if (strcmp(key, "ARTICLE") == 0)
            my_sort(*array, size, cmp_article);
        if (strcmp(key, "NAME") == 0)
            my_sort(*array, size, cmp_name);
        if (strcmp(key, "COUNT") == 0)
            my_sort(*array, size, cmp_count);    
    }    
    free(key);
    return exit_code;       
}

void my_sort(struct product *base, int num, int (*cmp)(struct product, struct product))
{
    for (int i = 0; i < num; i++ )
    {
        for (int j = 1; j < num - i; j++)
        {
            if (cmp(base[j - 1], base[j]) > 0)
            {
                struct product temp = base[j - 1];
                base[j - 1] = base[j];
                base[j] = temp;
            }
        }
    }
}

int cmp_article(struct product a, struct product b)
{
    return strcmp(a.article, b.article);
}

int cmp_name(struct product a, struct product b)
{
    return strcmp(a.name, b.name);
}

int cmp_count(struct product a, struct product b)
{
    return a.count - b.count;
}
