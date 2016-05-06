/*
 * encapFSM.cpp
 * Copyright (C) 2014-09-10 17:57 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include <stdio.h>

class StateMachine
{
public:
    StateMachine () : state(before){};
    virtual ~StateMachine ();

    void FeedChar(int c){
        int idx2 = (' ' == c) ? 0 : ('\n' == c) ? 1 : 2;
        struct branch *b = &table[state][idx2];
        state = (enum states)b->new_state;
        if (b->should_putchar)
        {
            putchar(c);
        }
    }

private:
    enum states {before = 0, inside = 1, after = 2} state;
    struct branch{
        unsigned char new_state:2;
        unsigned char should_putchar:1;
    };

    static struct branch table[3][3];
};


struct StateMachine::branch StateMachine::table[3][3] = {
//input event:          ' '           '\n'       'other*'
/*state before*/    {{before,0}, {before, 1}, {inside, 1}},
/*state inside*/    {{after, 0}, {before, 1}, {inside, 1}},
/*state after*/     {{after, 0}, {before, 1}, {after, 0}}
};

StateMachine:: ~StateMachine (){
}

int main(int argc, char *argv[])
{
    int c;
    StateMachine machine;
    while((c = getchar()) != EOF) {
        machine.FeedChar(c);
    }
    return 0;
}
