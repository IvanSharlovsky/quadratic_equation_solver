#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include "quadratic_equation_solver.h"


//constant for compare format double
const double ACCURACY = 1e-6;



int solve_quad_eq(double a, double b, double c, double* x1, double* x2) {

    assert(x1);
    assert(x2);
    if (cmp_with_0(a)) {
    
        return solve_line_eq(b, c, x1);
    }
    else {
    
        double discriminant = b * b - 4 * a * c;
        //veriable to optimize calculating
        double double_a = 2 * a;

        if (discriminant >= 0) {
        
            if (cmp_with_0(discriminant)) {
            
                *x1 = -b / (double_a);
                return ONE_ROOT;
            }
            else {
            
                //veriable to optimize calculating
                double sqrt_discriminant = sqrt(discriminant);

                *x1 = (-b + sqrt_discriminant) / (double_a);
                *x2 = (-b - sqrt_discriminant) / (double_a);

                return TWO_ROOTS;
            }
        }
        else {
        
            return NO_ROOTS;
        }
    }
}



int solve_line_eq(double b, double c, double* x) {

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



void num_of_roots(int n_roots, double x1, double x2) {

    switch (n_roots)
    {
    case 0: printf("\n\nNo roots!\n");
        break;

    case 1: printf("\n\nThere is only one root.\n");
        printf("result1 = %lf\n", x1);
        break;

    case 2: printf("\n\nresult1 = %lf\tresult2 = %lf\n", x1, x2);
        break;

    case INF_ROOTS: printf("\n\nAny number\n");
        break;

    default: printf("\n\nmain(): ERROR: n_roots = %d\n", n_roots);
        break;
    }
}



bool cmp_with_0(double val) {

    return (fabs(val) < ACCURACY);
}



bool is_equal(double val1, double val2) {

    return (cmp_with_0(val1 - val2));
}