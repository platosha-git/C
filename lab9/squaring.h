#ifndef SQUARING_H
#define SQUARING_H

void squaring_matr(int ***matr, int *x, int *y);
int max_matr_row(int **matr, int x, int y);
int max_matr_column(int **matr, int x, int y);
void delete_column(int ***matr, int x, int y, int max_j);
void delete_row(int ***matr, int x, int y, int max_i);

#endif

