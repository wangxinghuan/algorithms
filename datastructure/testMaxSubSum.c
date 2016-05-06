/*
 * testSubSum.c
 * Copyright (C) 2014-08-29 10:18 AlbertTK <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include "maxSubSum.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
    const int array[] = {4, -3, 5, -2, -1, 2, 6, -2};
    int sum = 0;
    int size = sizeof(array) / sizeof(array[0]);


    sum = maxSubSum(array, size);

    printf("time = O(N)\n");
    printf("sum = %d\n", sum);
    printf("time = O(Nlog(N))\n");
    sum = maxSubSum2(array, size);
    printf("sum = %d\n", sum);

    return 0;
}
