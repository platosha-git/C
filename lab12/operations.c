#include <stdio.h>
#include <stdlib.h>

#include "operations.h"
#include "structs.h"
#include "output.h"
#include "input.h"
#include "exit_codes.h"

//val
int polinom_calc(struct list *head)
{
	int exit_code = SUCCESS;
	char *sarg = get_string();
	double arg = 0;
	struct list *current = head;

	exit_code = check_arg(sarg, &arg);
	free(sarg);
	if (exit_code == SUCCESS)
	{
		double res = 0;
		double pow_arg = 0;
		int kf = 0;

		while (current)
		{
			kf = current->koef;
			pow_arg = pow_calc(arg, current->pow);
			current = current->next;
			res += kf * pow_arg;
		}
		printf("%.6f\n", res);
	}
	return exit_code;
}

double pow_calc(double bas, int exp)
{
	double ret = 0;
	if (exp == 0)
		ret = 1;
	else if (exp == 1)
		ret = bas;
	else if (exp % 2 == 0)
		ret = pow_calc(bas * bas, exp / 2);
	else
		ret = pow_calc(bas * bas, exp / 2) * bas;
	return ret;
}

int check_arg(char *sarg, double *arg)
{
	int exit_code = SUCCESS;
	int i = 0, sign = 0;
	int factor = 0;
	while (sarg[i] != '\0')
	{
		if (sarg[i] == '-')
		{
			sign++;
			i++;
			continue;
		}
		if (sarg[i] == '.')
		{
			factor = i;
			i++;
			continue;
		}
		if (sarg[i] < '0' || sarg[i] > '9')
		{
			exit_code = ARG_ERROR;
			break;
		}
		(*arg) *= 10;
		(*arg) += sarg[i] - '0';
		i++;
	}

	if (i == 0)
		exit_code = ARG_ERROR;
	if (sign % 2 != 0)
		(*arg) *= -1;
	if (factor != 0)
	{
		for (int j = 0; j < i - factor - 1; j++)
			(*arg) /= 10;
	}
	return exit_code;
}


//ddx
void derivate_calc(struct list *head)
{
	int kf = 0, dg = 0;
	struct list *current = head;

	while (current)
	{
		kf = current->koef;
		dg = current->pow;

		current->koef = kf * (dg);
		current->pow = dg - 1;

		current = current->next;
	}
	print_list(head);
}


//sum
void addition_polinoms(struct list *head1, struct list *head2)
{
	int kf1 = 0, kf2 = 0;
	int dg1 = 0, dg2 = 0;
	int i = 0;

	struct list *res = NULL;
	struct list *res_head = NULL;
	struct list *cur1 = head1;
	struct list *cur2 = head2;

	while (cur1 && cur2)
	{
		kf1 = cur1->koef;
		dg1 = cur1->pow;

		kf2 = cur2->koef;
		dg2 = cur2->pow;

		if (dg1 > dg2)
		{
			insert_node(&res_head, &res, i, kf1, dg1);
			cur1 = cur1->next;
		}
		else if (dg1 == dg2)
		{
			insert_node(&res_head, &res, i, kf1 + kf2, dg1);
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		else if (dg1 < dg2)
		{
			insert_node(&res_head, &res, i, kf2, dg2);
			cur2 = cur2->next;
		}
		i++;
	}

	while (cur1)
	{
		insert_node(&res_head, &res, i, cur1->koef, cur1->pow);
		cur1 = cur1->next;    
	}
	while (cur2)
	{
		insert_node(&res_head, &res, i, cur2->koef, cur2->pow);
		cur2 = cur2->next;    
	}
	print_list(res_head);
	free_list(res_head);
}


//dvd
void separation_polinoms(struct list *head)
{
	struct list *even = head;
	struct list *odd = head;

	while (even)
	{
		if (even->pow % 2 == 0)
			printf("%d %d ", even->koef, even->pow);
		even = even->next;
	}
	printf("L\n");

	while (odd)
	{
		if (odd->pow % 2 != 0)
			printf("%d %d ", odd->koef, odd->pow);
		odd = odd->next;
	}
	printf("L\n");
}