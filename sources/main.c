#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "../include/quadratic_equation_solver.h"
#include "../include/quadratic_equation_tests.h"

void get_coefficient(double* coef, char coef_name);
void clear_buffer();

int main()
{
    int number_of_failed_test = run_unit_test();

    if (number_of_failed_test != 0)
    {
        printf("FAILED! Number of failed test is %d\n", number_of_failed_test);
        return 0;
    }
    else
    {
        printf(
            "# quadratic equation solver\n"
            "# Sharlovskiy Ivan, 2023\n\n"
            "To solve a quadratic equation (ax^2 + bx + c = 0), "
            "please, enter the coefficients:\n");

        double a = NAN, b = NAN, c = NAN;
        char var_a = 'a', var_b = 'b', var_c = 'c';

        get_coefficient(&a, var_a);

        get_coefficient(&b, var_b);

        get_coefficient(&c, var_c);

        double x1 = NAN, x2 = NAN;

        int number_of_roots = solve_quad_eq(a, b, c, &x1, &x2);

        answer(number_of_roots, x1, x2);

        return 0;
    }
}

void get_coefficient(double* coef, char coef_name)
{    
    printf("\nCoefficient (%c)= ", coef_name);
    
    bool b_allowed_enter = 0;

    if ((b_allowed_enter = scanf("%lf", coef)) == false)
    {
        printf("Invalid enter!\n");
        clear_buffer();
        get_coefficient(coef, coef_name);
    }
}

void clear_buffer()
{
    while (getchar() != '\n') { ; }
}