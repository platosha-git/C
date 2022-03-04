#include <stdio.h>
#include <stdlib.h> 

#include "exit_codes.h"
#include "operations.h"

void first_func(double **matr, int n)
{
	double m1 = 1;
	for (int i = 0; i < n; i++)
		m1 *= (*matr)[i];
	m1 = abs_calc(m1);
	m1 = sqrt_calc(m1, n);
	remove_elem_less(matr, n, m1);
}

double sqrt_calc(double base, int pow)
{
	double eps = 0.000001;
	double res = base / pow;
	double rn = base;
	while (abs_calc(res - rn) >= eps)
	{
		rn = base;
		for (int i = 1; i < pow; i++)
			rn /= res;
		res = 0.5 * (rn + res);
	}
	return res;
}

double abs_calc(double x)
{ 
	return (x < 0) ? -x : x; 
}

int remove_elem_less(double **matr, int n, double m1)
{
	int j = n;
	for (int i = 0; i < n && j >= 0; i++)
	{
		if ((*matr)[i] < m1)
		{
			swap((*matr)[i], (*matr)[j]);
			j--;
		}
	}

	while ((*matr)[n] < m1 && n >= 0)
	{
		free_elem(matr, n);
		n--;
	}
}

void swap(double elem1, double elem2)
{
	double temp = elem1;
	elem1 = elem2;
	elem2 = temp;
}