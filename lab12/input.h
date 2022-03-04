#ifndef INPUT_H
#define INPUT_H

#include "structs.h"

int input_polinom(struct list **head);
void insert_node(struct list **head, struct list **current, int index, int kf, int dg);

char *get_string();
int fill_polinom(char *pln, struct list **head);

int check_string(char *pln);
int check_var(char *var);
int check_polinom(struct list *head);

#endif
