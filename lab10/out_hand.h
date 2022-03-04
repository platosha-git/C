#ifndef OUT_HAND_H
#define OUT_HAND_H

#include "in_hand.h"

void free_array(struct product **array, int size);
int output_file(struct product **array, int size);
void output_struct(struct product **array, int size);

#endif
