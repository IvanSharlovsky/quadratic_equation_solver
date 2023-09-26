#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "floating_point_math.h"

//constant for compare format double
const double ACCURACY = 1e-6;

bool cmp_with_0(double val) {

    return (fabs(val) < ACCURACY);
}

bool is_equal(double val1, double val2) {

    return (cmp_with_0(val1 - val2));
}