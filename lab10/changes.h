#ifndef CHANGES_H
#define CHANGES_H

#include "in_hand.h"

void string_concat(struct product **array, int size); 
void to_upp(char *str);
int remove_product(struct product **array, int *size);
int case_zero_array(struct product **array, int *size);

int sort_products(struct product **array, int size);  
void my_sort(struct product *base, int num, int (*cmp)(struct product, struct product));
int cmp_article(struct product a, struct product b);
int cmp_name(struct product a, struct product b);
int cmp_count(struct product a, struct product b);

#endif
