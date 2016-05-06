/*
 * table.c
 * Copyright (C) 2014-09-10 17:42 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include <stdio.h>

enum states {before = 0, inside = 1, after = 2};

struct branch {
    unsigned char new_state:2;
    unsigned char should_putchar:1;
};

struct branch table[3][3] = {
//input event:          ' '           '\n'       'other*'
/*state before*/    {{before,0}, {before, 1}, {inside, 1}},
/*state inside*/    {{after, 0}, {before, 1}, {inside, 1}},
/*state after*/     {{after, 0}, {before, 1}, {after, 0}}
};


void step(enum states *state, char c){
    int idx2 = c == ' ' ? 0 : c == '\n' ? 1 : 2;
    struct branch *b = &table[*state][idx2];

    *state = (enum states)b->new_state;
    if (b->should_putchar)
    {
        putchar(c);
    }
}


int main(int argc, char *argv[])
{
    enum states state;
    char c;

    state = before;
    while((c = getchar()) != EOF) {
        step(&state, c);
    }
    return 0;
}
