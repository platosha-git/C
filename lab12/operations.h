#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "structs.h"

int polinom_calc(struct list *head);
double pow_calc(double bas, int exp);
int check_arg(char *sarg, double *arg);

void derivate_calc(struct list *head);

void addition_polinoms(struct list *head1, struct list *head2);

void separation_polinoms(struct list *head);

#endif