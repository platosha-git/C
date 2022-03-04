#include <stdio.h>
#include <stdlib.h> 

#include "handler_output.h"

void delete_matr(double **matr, int n)
{
	if (*matr != NULL) 
	{
		free(*matr);
		*matr = NULL;
	}
}

void output_matr(double **matr, int n)
{
	for (int i = 0; i < n; i++) 
		printf("%.6lf ", (*matr)[i]);
	printf("\n");
}
