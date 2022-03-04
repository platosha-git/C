#include <stdio.h>
#include <stdlib.h>

#include "output.h"
#include "structs.h"

void print_list(struct list *head)
{
    struct list *pr_head = head;
    while (pr_head)
    {
        if (pr_head->koef == 0)
        {
            pr_head = pr_head->next;
            continue;
        }
        printf("%d %d ", pr_head->koef, pr_head->pow);
        pr_head = pr_head->next;
    }
    printf("L\n");
}

void free_list(struct list *head)
{
    while (head != NULL)
    {
        struct list *tmp = head;
        head = head->next;
        free(tmp);
    }
}