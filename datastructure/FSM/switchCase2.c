/*
 * switchCase2.c
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
        if (c == '\n')
        {
            putchar('\n');
            state = before;
        }else{
            switch(state){
                case before:
                    if(c != ' ')
                    {
                        putchar(c);
                        state = inside;
                    }
                    break;
                case inside:
                    if (c == ' ')
                    {
                        state = after;
                    }else{
                        putchar(c);
                    }

                    break;
                case after:
                    break;
            }
        }
    }
    return 0;
}


