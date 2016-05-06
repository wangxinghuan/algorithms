/*
 * switchCase3.c
 * Copyright (C) 2014-09-10 17:18 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include <stdio.h>
enum states {before, inside, after};

void step(enum states *state, char c){
    if ('\n' == c)
    {
        putchar('\n');
        *state = before;
    }else{
        switch(*state){
            case before:
                if (c != ' ')
                {
                    putchar(c);
                    *state = inside;
                }
                break;
            case inside:
                if (c != ' ')
                {
                    putchar(c);
                    break;
                }else{
                    *state = after;
                }
                break;
            case after:
                break;
        }
    }

}

int main(int argc, char *argv[])
{
    enum states state;
    state = before;
    char c;

    while((c = getchar()) != EOF){
        step(&state, c);
    }
    return 0;
}


