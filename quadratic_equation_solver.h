#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

//constant for compare format double
const double ACCURACY = 1e-6;

enum num_roots
{
    INF_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOTS = 2,
};

//prototype
int run_unit_test();
int unit_test(int n_test, double a, double b, double c, int n_roots_ref, double x1_ref, double x2_ref);
int solve_quad_eq(double a, double b, double c, double* x1, double* x2);
int solve_line_eq(double b, double c, double* x);
void num_of_roots(int n_roots, double x1, double x2);
bool cmp_with_0(double val);
bool is_equal(double val1, double val2);
void clear_buffer();
void read_coefficient(double* coef);