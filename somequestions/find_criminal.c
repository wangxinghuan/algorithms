/*
 * find_criminal.c
 * Copyright (C) 2015-01-23 15:52 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    int count = 0;
    int sum = 0;
    int A, B, C, D, E;

    for (A = 0; A < 2; ++A)
    {
        for (B = 0; B < 2; ++B)
        {
            for (C = 0; C < 2; ++C)
            {
                for (D = 0; D < 2; ++D)
                {
                    for (E = 0; E < 2; ++E)
                    {
                        sum = 0;
                        sum += ((A == 0 ) || (A == 1 && B == 1)) ? 1 : 0;
                        sum += ((B + C) == 1) ? 1 : 0;
                        sum += (C == D) ? 1: 0;
                        sum += (D + E >= 1) ? 1 : 0;
                        sum += (E == 0 || (E == 1 && A == 1 && B == 1)) ? 1 : 0;

                        if (sum == 5)
                        {
                            count++;
                            printf("This is the %d th answer:\n", count);
                            printf("Suspect A is %s\n", (A == 1) ? "criminal" : "not criminal");
                            printf("Suspect B is %s\n", (B == 1) ? "criminal" : "not criminal");
                            printf("Suspect C is %s\n", (C == 1) ? "criminal" : "not criminal");
                            printf("Suspect D is %s\n", (D == 1) ? "criminal" : "not criminal");
                            printf("Suspect E is %s\n", (E == 1) ? "criminal" : "not criminal");
                            printf("\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}

