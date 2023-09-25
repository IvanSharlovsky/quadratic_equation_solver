#include <stdio.h>
#include <stdbool.h>
#pragma once

enum num_roots
{
    INF_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
};

//prototype

int solve_quad_eq(double a, double b, double c, double* x1, double* x2);
int solve_line_eq(double b, double c, double* x);
void num_of_roots(int n_roots, double x1, double x2);
bool cmp_with_0(double val);
bool is_equal(double val1, double val2);