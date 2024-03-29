#pragma once

enum num_roots
{
    INF_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
};

int solve_quad_eq(double a, double b, double c, double* x1, double* x2);
int solve_line_eq(double b, double c, double* x);
void print_answer(int number_of_roots, double x1, double x2);
