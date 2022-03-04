#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exit_codes.h"
#include "structs.h"
#include "input.h"
#include "operations.h"
#include "output.h"

int main(void)
{    
	int exit_code = SUCCESS;

	struct list *head = NULL;

	char *var = get_string();
	exit_code = check_var(var);

	if (exit_code == SUCCESS)
	{
		exit_code = input_polinom(&head);
		if (exit_code == SUCCESS)
		{
			if (strcmp(var, "val") == 0)
				exit_code = polinom_calc(head);
			else if (strcmp(var, "ddx") == 0)
				derivate_calc(head);
			else if (strcmp(var, "sum") == 0)
			{
				struct list *head_2 = NULL;
				exit_code = input_polinom(&head_2);

				if (exit_code == SUCCESS)
					addition_polinoms(head, head_2);
				free_list(head_2);
			}
			else if (strcmp(var, "dvd") == 0)
				separation_polinoms(head);
			else
				exit_code = VAR_ERROR;
		}
	}
	free(var);
	free_list(head);
	return exit_code;
}