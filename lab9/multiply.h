#ifndef MULTIPLY_H
#define MULTIPLY_H

int multiply_handler_matr(int ***matr1, int x1, int y1, int ***matr2, int x2, int y2);
void matr_pow(int ***res1, int ***matr, int ***res2, int x, int y, int pow);
void multiplication_matr(int ***matr1, int ***matr2, int ***res, int x, int y);
void zero_degree_matr(int ***matr, int x, int y);
void assign_matr(int ***matr1, int ***matr2, int x, int y);

#endif

