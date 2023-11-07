#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "../include/quadratic_equation_solver.h"
#include "../include/quadratic_equation_tests.h"
#include "../include/floating_point_math.h"



int run_unit_test()
{    
    int n_errors = 0;
           /* test_number| a| b| c| number_of_roots_ref| x1_ref| x2_ref */
    if (b_unit_test(      1, 0, 0, 0,           INF_ROOTS,    NAN,    NAN) == false)  n_errors++;
    if (b_unit_test(      2, 0, 0, 1,            NO_ROOTS,    NAN,    NAN) == false)  n_errors++;
    if (b_unit_test(      3, 0, 1, 0,            ONE_ROOT,      0,    NAN) == false)  n_errors++;
    if (b_unit_test(      4, 1, 0, 0,            ONE_ROOT,      0,    NAN) == false)  n_errors++;
    if (b_unit_test(      5, 1, 1, 0,           TWO_ROOTS,      0,     -1) == false)  n_errors++;
    if (b_unit_test(      6, 1, 1, 1,            NO_ROOTS,    NAN,    NAN) == false)  n_errors++;
    if (b_unit_test(      7, 1, 1,-2,           TWO_ROOTS,      1,     -2) == false)  n_errors++; // check for discriminant
    return n_errors;
}



bool b_unit_test(int test_number, double a, double b, double c, int number_of_roots_ref, double x1_ref, double x2_ref)
{
    double x1 = NAN, x2 = NAN;

    int number_of_roots = solve_quad_eq(a, b, c, &x1, &x2);

    switch (number_of_roots_ref)
    {
    case NO_ROOTS:

        if (isfinite(x1) || isfinite(x2) || number_of_roots != number_of_roots_ref)
        {
            printf(
                "Test %d failed:\n"
                "x1 = %lf, x2 = %lf, number_of_roots = %d\n"
                "Must be: x1 = NAN, x2 = NAN, number_of_roots = 0\n\n",
                test_number, x1, x2, number_of_roots);

            return false;
        }
        else return true;
        break;

    case ONE_ROOT: 
    
        if (!is_equal(x1, x1_ref) || isfinite(x2) || number_of_roots != number_of_roots_ref)
        {
            printf(
                "Test %d failed:\n"
                "x1 = %lf, x2 = %lf, number_of_roots = %d\n"
                "Must be: x1 = %lf, x2 = NAN, "
                "number_of_roots = 1\n\n",
                test_number, x1, x2, number_of_roots, x1_ref);

            return false;
        }
        else return true;
        break;

    case TWO_ROOTS: 
    
        if (!is_equal(x1, x1_ref) || !is_equal(x2, x2_ref) || number_of_roots != number_of_roots_ref)
        {
            printf(
                "Test %d failed:\n"
                "x1 = %lf, x2 = %lf, number_of_roots = %d\n"
                "Must be: x1 = %lf, x2 = %lf, "
                "number_of_roots = 2\n\n",
                test_number, x1, x2, number_of_roots, x1_ref, x2_ref);

            return false;
        }
        else return true;
        break;

    case INF_ROOTS: 
    
        if (isfinite(x1) || isfinite(x2) || number_of_roots != number_of_roots_ref)
        {
            printf(
                "Test %d failed:\n"
                "x1 = %lf, x2 = %lf, number_of_roots = %d\n"
                "Must be: x1 = NAN, x2 = NAN, "
                "number_of_roots = infinite\n\n",
                test_number, x1, x2, number_of_roots);
                
            return false;
        }
        else return true;
        break;

    default:

        printf("\n\nunit_test %d: ERROR: number_of_roots_ref = %d\n", test_number, number_of_roots_ref);
        return false;
        break;
    }
}