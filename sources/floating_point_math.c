#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "../include/floating_point_math.h"

bool cmp_with_0(double val)
{
    return (fabs(val) < __DBL_EPSILON__);
}

bool is_equal(double val1, double val2)
{
    return (cmp_with_0(val1 - val2));
}