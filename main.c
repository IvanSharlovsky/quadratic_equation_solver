#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "quadratic_equation_solver.h"
#include "quadratic_equation_tests.h"

//Getting coefficient from input until getting number
void get_coefficient(double* coef, char coef_name); 
void clear_buffer();

int main()
{
    //Starting test
    int number_of_failed_test = run_unit_test();

    if (number_of_failed_test != 0)
    {
        printf("FAILED! Number of failed test is %d\n", number_of_failed_test);
        return 0;
    }
    
    printf("\n"
        "---------------------------------------------------\n"
        "# quadratic equation solver\n"
        "# Sharlovskiy Ivan, 2023\n"
        "-------------------------------------------------\n\n"
        "To solve a quadratic equation (ax^2 + bx + c = 0), "
        "please, enter the coefficients:\n");

    double a = NAN, b = NAN, c = NAN;

    //Getting coefficient from input until getting number
    get_coefficient(&a, 'a');
    get_coefficient(&b, 'b');
    get_coefficient(&c, 'c');

    double x1 = NAN, x2 = NAN;

    //General function in this project
    int number_of_roots = solve_quad_eq(a, b, c, &x1, &x2); 
    print_answer(number_of_roots, x1, x2);

    return 0;

}

void get_coefficient(double* coef, char coef_name)
{    
    printf("\nCoefficient %c= ", coef_name);
    
    bool allow_enter = 0;

    if ((allow_enter = scanf("%lf", coef)) == false)
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
