#ifndef EXPANSION_H
#define EXPANSION_H

void matrix_expansion(int ***matr1, int *x1, int *y1, int ***matr2, int *x2, int *y2);
void expand_one_matr_to_another(int ***matr, int *x, int *y, int *to_x, int *to_y);
void insert_row(int ***matr, int *row_size_matr, int *column_size_matr);
void insert_row_average(int ***matr, int x, int y);
void insert_column(int ***matr, int *row_size_matr, int *column_size_matr);
void insert_min_column(int ***matr, int x, int y);

#endif

