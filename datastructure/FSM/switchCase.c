/*
 * switchCase.c
 * Copyright (C) 2014-09-10 16:56 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

/*
 * 打印每一行的第一个非空单词
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    enum states {before, inside, after};

    char c;

    enum states state;

    state = before;

    while((c = getchar()) != EOF) {
        switch(state){
            case before:
                if (c == '\n')
                {
                    putchar('\n');
                }else if (c != ' ')
                {
                    putchar(c);
                    state = inside;
                }
                break;
            case inside:
                if (c == ' ')
                {
                    state = after;
                    break;
                }else if (c == '\n')
                {
                    putchar(c);
                    state = before;
                    break;
                }
                else{
                   putchar(c);
                }
            case after:
                if (c == '\n')
                {
                    putchar('\n');
                    state = before;
                }
        }
    }
    return 0;
}


