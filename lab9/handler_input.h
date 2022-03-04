#ifndef HANDLER_INPUT_H
#define HANDLER_INPUT_H

int read_squar_matr(int ***matr, int *x, int *y);
int creation_matr(int ***matr, int *x, int *y);
int get_size_pow_matr(char *msg, int *elem, int border);
int create_matr(int ***matr, int x, int y);
void initialize_matr_by_zero(int ***matr, int x, int y);
int incorrect_input(int x, int y);
void input_matr(int **matr, int x, int y);

#endif

