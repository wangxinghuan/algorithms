/*
 * testList.c
 * Copyright (C) 2014-09-09 20:09 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include "list.h"
#include "stdio.h"


int main(int argc, char *argv[])
{
    List l;
    l = MakeList(l);
    printf("IsEmpty: %d\n", IsEmpty(l));
    return 0;
}



