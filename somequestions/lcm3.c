/*
 * lcm3.c
 * Copyright (C) 2015-01-28 11:33 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include <stdio.h>

unsigned long lcm(unsigned long a, unsigned long b);
unsigned long lcm3(unsigned long a, unsigned long b, unsigned long c);


int main(int argc, char *argv[])
{
    unsigned long x, y, z;

    printf("Input 3 positive numbers:\n");
    scanf("%lu%lu%lu", &x, &y, &z);
    printf("The least common multiple: %lu\n", lcm3(x, y, z));

    return 0;
}


unsigned long lcm(unsigned long a, unsigned long b){
    unsigned long multiple = 0, c = 0;

    multiple = a * b;
    while( a % b != 0){
        c = a % b;
        a = b;
        b = c;
    }

    return (multiple / b);
}


unsigned long lcm3(unsigned long a, unsigned long b, unsigned long c){

    return lcm(lcm(a, b), c);
}
