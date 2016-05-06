/*
 * solve_equations.c
 * Copyright (C) 2015-01-23 16:23 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include <stdio.h>
#include <math.h>

double g(double x);

int main(int argc, char *argv[])
{
    double x0 = 1, x1 = 0;
    int count = 0;
    printf("x%d = %10f\n", count, x0);
    while(fabs(x1 - x0) >= 1e-10) {
        x1 = x0;
        x0 = g(x1);
        count++;
        printf("x%d = %10f\n", count, x0);
    }

    printf("approximate x%d = %10f\n", count, x0);
    return 0;
}


double g(double x){
    return pow(x, 6) / 8.0 - 0.5;
}

