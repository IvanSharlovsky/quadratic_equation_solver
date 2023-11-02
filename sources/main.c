#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "../include/quadratic_equation_solver.h"
#include "../include/quadratic_equation_tests.h"

void read_coefficient(double* coef);
void clear_buffer();

int main() {

    int number_of_failed_test = run_unit_test();

    if (number_of_failed_test != 0) {
        printf("FAILED! Number of failed test is %d\n", number_of_failed_test);
        return 0;
    }
    else {

        printf(
            "# quadratic equation solver\n"
            "# Sharlovsky Ivan, 2023\n\n"
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

        int number_of_roots = solve_quad_eq(a, b, c, &x1, &x2);

        answer(number_of_roots, x1, x2);
    }
}

void read_coefficient(double* coef) {
    
    bool allowed_enter = 0;

    if ((allowed_enter = scanf("%lf", coef)) == false) {
        printf("Invalid enter!\n"
        "coefficient = ");
        clear_buffer();
        read_coefficient(coef);
    }
}

void clear_buffer() {

    while (getchar() != '\n') { ; }
}