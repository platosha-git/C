#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "input.h"
#include "structs.h"
#include "exit_codes.h"

int input_polinom(struct list **head)
{
	char *pln = get_string();
	int exit_code = check_string(pln);
	if (exit_code == SUCCESS)
	{
		exit_code = fill_polinom(pln, head);
		if (exit_code == SUCCESS)
			exit_code = check_polinom(*head);	
	}		
	free(pln);
	
	return exit_code;
}

void insert_node(struct list **head, struct list **current, int index, int kf, int dg)
{
	struct list *temp = (struct list *) malloc(sizeof(struct list));
	temp->pow = dg;
	temp->koef = kf;

	if (index == 0)
	{
		*head = temp;
		*current = temp;
	}
	else
	{
		(*current)->next = temp;
		*current = (*current)->next;
		(*current)->next = NULL;
	}
}

char *get_string()
{
	char *str = (char *) malloc(sizeof(char));
	str[0] = '\0';

	int i = 0;
	char symb = getchar();
	while (symb != '\n')
	{
		i++;
		str = (char *) realloc(str, (i + 1) * sizeof(char));
		str[i - 1] = symb;
		str[i] = '\0';
		symb = getchar();
	}
	return str;
}

int check_string(char *pln)
{
	int exit_code = SUCCESS;
	int i = 0;
	while (pln[i] != '\0' && exit_code == SUCCESS)
	{
		if (pln[i] < '0' || pln[i] >'9')
			if (pln[i] != '-' && pln[i] != ' ')
				exit_code = POLINOM_ERROR;
		i++;
	}
	return exit_code;
}

int fill_polinom(char *pln, struct list **head)
{
	int exit_code = SUCCESS;

	int i = 0, j = 0, node_counter = 0, elem_counter = 0;
	bool is_positive = true;
	int elem = 0, kf = 0;
	struct list *current = NULL;

	while (pln[i] != '\0')
	{
		if (pln[i] == ' ')
		{
			if (j % 2 == 0)
			{
				if (!is_positive)
					elem *= -1;
				kf = elem;
			}
			else
			{
				if (!is_positive)
					elem *= -1;
				insert_node(head, &current, node_counter, kf, elem);
				node_counter++;
			}
			elem = 0;
			is_positive = true;
			elem_counter++;
			i++;
			j++;
			continue;
		}

		if (pln[i] == '-')
		{
			is_positive = false;
			i++;
		}

		elem *= 10;
		elem += pln[i] - '0';
		i++;
	}
	
	if (i > 0)
	{
		if (!is_positive)
			elem *= -1;
		insert_node(head, &current, node_counter, kf, elem);
		node_counter++;
		elem_counter++;
	}

	if (elem_counter % 2 != 0 || node_counter == 0 || pln[i] != '\0')
		exit_code = POLINOM_ERROR;
	return exit_code;
}

int check_var(char *var)
{
	int exit_code = SUCCESS;
	if (strcmp(var, "val") != 0 && strcmp(var, "ddx") != 0 && strcmp(var, "sum") != 0 && strcmp(var, "dvd") != 0)
		exit_code = VAR_ERROR;
	return exit_code;
}

int check_polinom(struct list *head)
{
	int exit_code = SUCCESS;
	struct list *head_check = head;

	while (head_check->next != NULL)
	{
		if (head_check->pow <= head_check->next->pow)
		{
			exit_code = POLINOM_ERROR;
			break;
		}
		head_check = head_check->next;
	}
	return exit_code;
}
