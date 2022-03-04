#include <stdio.h>
#include <stdlib.h> 

#include "exit_codes.h"
#include "handler_input.h"

int create_fill_matr(double **matr, int *n)
{
	int exit_code = SUCCESS;
	scanf("%d", n);
	if (*n <= 0)
		exit_code = N_ERROR;

	if (exit_code == SUCCESS)
	{
		exit_code = create_matr(matr, *n);
		if (exit_code == SUCCESS)
		{
			initialize_matr_by_zero(matr, *n);
			input_matr(matr, *n);
		}
	}
	return exit_code;
}

int create_matr(double **matr, int n)
{
	int exit_code = SUCCESS;

	if (!matr && !(*matr) && !(**matr))
		exit_code = CREATE_MATR_ERR;
	else
		*matr = (double *) malloc(sizeof(double) * (n + 1));
	return exit_code;
}

void initialize_matr_by_zero(double **matr, int n)
{
	for (int i = 0; i < n; i++)
		(*matr)[i] = 0;
}

void input_matr(double **matr, int n)
{
	for (int i = 0; i < n; i++)
		scanf("%lf", &(*matr)[i]);
}
