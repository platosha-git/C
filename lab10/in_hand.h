#ifndef IN_HAND_H
#define IN_HAND_H

struct product
{
    char *article;
    char *name;
    int count;
};

int input_handler(struct product **array, int *size);
char *get_string(char *msg);
void node_constructor(int *size, int *max_size, struct product **array, char *article, char *name, int count);

#endif
