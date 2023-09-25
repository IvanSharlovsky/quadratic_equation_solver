// Quadratic equation solver
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

//------------------------------------------------------------------------

int main()
{

    int n_errors = run_unit_test();

    if (n_errors != 0)
    {
        printf("FAILED! Number of failed test is %d\n", n_errors);
        return 0;
    }
    else
    {
        printf("# quadratic equation solver\n"
            "# Sharlovsky Ivan, 03.04.2023\n\n"
            "To solve a quadratic equation (ax^2 + bx + c = 0) "
            "please enter the coefficients:\n");

        // the coefficients in the equation

        double a = NAN, b = NAN, c = NAN;

        int ok_enter = 0;

        while (ok_enter < 3)
        {
            ok_enter = 0;

            printf("\nFirst coefficient (a)= ");

            int result = scanf_s("%lf", &a);

            if (result != 1)
            {
                clear_buffer();
            }
            else ok_enter++;

            clear_buffer();

            printf("\nSecond coefficient (b)= ");

            result = scanf_s("%lf", &b);

            if (result != 1)
            {
                clear_buffer();
            }
            else ok_enter++;

            clear_buffer();

            printf("\nThird coefficient (c)= ");

            result = scanf_s("%lf", &c);

            if (result != 1)
            {
                clear_buffer();
            }
            else ok_enter++;

            clear_buffer();

            if (ok_enter < 3)
            {
                printf("\nERROR ENTER\n");
            }
        }

        double x1 = NAN, x2 = NAN;
        int n_roots = solve_quad_eq(a, b, c, &x1, &x2);
        num_of_roots(n_roots, x1, x2);
    }
}
//------------------------------------------------------------------------

//------------------------------------------------------------------------
int run_unit_test()
{
    int n_errors = 0;
                /* n_test| a| b| c| n_roots_ref| x1_ref| x2_ref */
    if (unit_test(      1, 0, 0, 0, INF_ROOTS,      NAN, NAN) == false)  n_errors++;
    if (unit_test(      2, 0, 0, 1, NO_ROOTS,       NAN, NAN) == false)  n_errors++;
    if (unit_test(      3, 0, 1, 0, ONE_ROOT,         0, NAN) == false)  n_errors++;
    if (unit_test(      4, 1, 0, 0, ONE_ROOT,         0, NAN) == false)  n_errors++;
    if (unit_test(      5, 1, 1, 0, TWO_ROOTS,        0,  -1) == false)  n_errors++;
    if (unit_test(      6, 1, 1, 1, NO_ROOTS,       NAN, NAN) == false)  n_errors++;
    if (unit_test(      7, 1, 1,-2, TWO_ROOTS,        1,  -2) == false)  n_errors++; // check for discriminant
    return n_errors;
}
//------------------------------------------------------------------------
int unit_test(int n_test, double a, double b, double c,
    int n_roots_ref, double x1_ref, double x2_ref)
{
    double x1 = NAN, x2 = NAN;

    int n_roots = solve_quad_eq(a, b, c, &x1, &x2);

    switch (n_roots_ref)
    {
    case NO_ROOTS:  if (isfinite(x1) || isfinite(x2) || n_roots != n_roots_ref)
    {

        printf("Test %d failed:\n"
            "x1 = %lf, x2 = %lf, n_roots = %d\n"
            "Must be: x1 = NAN, x2 = NAN, n_roots = 0\n\n",
            n_test, x1, x2, n_roots);
        return false;
    }
                 else return true;
        break;

    case ONE_ROOT: if (!is_equal(x1, x1_ref) || isfinite(x2) || n_roots != n_roots_ref)
    {
        printf("Test %d failed:\n"
            "x1 = %lf, x2 = %lf, n_roots = %d\n"
            "Must be: x1 = %lf, x2 = NAN, "
            "n_roots = 1\n\n",
            n_test, x1, x2, n_roots, x1_ref);
        return false;
    }
                 else return true;
        break;

    case TWO_ROOTS: if (!is_equal(x1, x1_ref) || !is_equal(x2, x2_ref) || n_roots != n_roots_ref)
    {
        printf("Test %d failed:\n"
            "x1 = %lf, x2 = %lf, n_roots = %d\n"
            "Must be: x1 = %lf, x2 = %lf, "
            "n_roots = 2\n\n",
            n_test, x1, x2, n_roots, x1_ref, x2_ref);
        return false;
    }
                  else return true;
        break;

    case INF_ROOTS: if (isfinite(x1) || isfinite(x2) || n_roots != n_roots_ref)
    {
        printf("Test %d failed:\n"
            "x1 = %lf, x2 = %lf, n_roots = %d\n"
            "Must be: x1 = NAN, x2 = NAN, "
            "n_roots = infinite\n\n",
            n_test, x1, x2, n_roots);
        return false;
    }
                  else return true;
        break;

    default: printf("\n\nunit_test %d (): ERROR: n_roots_ref = %d\n",
        n_test, n_roots_ref);
        return false;
        break;
    }
}
//------------------------------------------------------------------------
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
//------------------------------------------------------------------------
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
//------------------------------------------------------------------------
void num_of_roots(int n_roots, double x1, double x2)
{
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
//------------------------------------------------------------------------
bool cmp_with_0(double val)
{
    return (fabs(val) < ACCURACY);
}
//------------------------------------------------------------------------
bool is_equal(double val1, double val2)
{
    return (cmp_with_0(val1 - val2));
}
//------------------------------------------------------------------------
void clear_buffer()
{
    while (getchar() != '\n') { ; }
}