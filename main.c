#include <stdio.h>
#include <math.h>
#include "quadratic_equation_solver.h"

int main() {

    int n_errors = run_unit_test();

    if (n_errors != 0) {
        printf("FAILED! Number of failed test is %d\n", n_errors);
        return 0;
    }
    else {

        printf("# quadratic equation solver\n"
            "# Sharlovsky Ivan, -.-.2023\n\n"
            "To solve a quadratic equation (ax^2 + bx + c = 0) "
            "please, enter the coefficients:\n");

        double a = NAN, b = NAN, c = NAN;

        printf("\nFirst coefficient (a)= ");
        read_coefficient(&a);

        printf("\nSecond coefficient (b)= ");
        read_coefficient(&b);

        printf("\nThird coefficient (c)= ");
        read_coefficient(&c);

        double x1 = NAN, x2 = NAN;

        int n_roots = solve_quad_eq(a, b, c, &x1, &x2);

        num_of_roots(n_roots, x1, x2);
    }
}