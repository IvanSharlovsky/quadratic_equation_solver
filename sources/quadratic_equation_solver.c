#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "../include/quadratic_equation_solver.h"
#include "../include/floating_point_math.h"



int solve_quad_eq(double a, double b, double c, double* x1, double* x2)
{
    assert(x1);
    assert(x2);

    if (cmp_with_0(a))
    {
        return solve_line_eq(b, c, x1);
    }
    else
    {
        double discriminant = b * b - 4 * a * c;
        //veriable to optimize calculating
        double double_a = 2 * a;

        if (discriminant >= 0)
        {
            if (cmp_with_0(discriminant))
            {
                *x1 = -b / (double_a);
                return ONE_ROOT;
            }
            else
            {
                //veriable to optimize calculating
                double sqrt_discriminant = sqrt(discriminant);

                *x1 = (-b + sqrt_discriminant) / (double_a);
                *x2 = (-b - sqrt_discriminant) / (double_a);

                return TWO_ROOTS;
            }
        }
        else
        {
            return NO_ROOTS;
        }
    }
}



int solve_line_eq(double b, double c, double* x)
{
    if (cmp_with_0(b))
    {
        return (cmp_with_0(c)) ? INF_ROOTS : NO_ROOTS;
    }
    else
    {
        *x = -c / b;
        return ONE_ROOT;
    }
}



void print_answer(int number_of_roots, double x1, double x2)
{
    switch (number_of_roots)
    {
    case NO_ROOTS: 
        printf("\n\nThis equation hasn't any roots\n");
        break;

    case ONE_ROOT: 
        printf("\n\nThis equation has one root\n"
        "result1 = %lf\n", x1);
        break;

    case TWO_ROOTS: 
        printf("\n\nThis equation has two roots\n"
        "result1 = %lf\tresult2 = %lf\n", x1, x2);
        break;

    case INF_ROOTS: 
        printf("\n\nThis equation has infinite number of roots\n");
        break;

    default: 
        printf("\n\nERROR: n_roots = %d\n", number_of_roots);
        break;
    }
}