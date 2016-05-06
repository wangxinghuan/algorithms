/*
 * list.c
 * Copyright (C) 2014-09-09 16:36 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include "list.h"
#include <stdlib.h>
#include <assert.h>

struct Node{
    ElementType Element;
    Position Next;
};


List MakeList(List L){
    L = (List)malloc(sizeof(struct Node));

    return L;
}


int IsEmpty(List L){
    return L->Next == NULL;
}


int IsLast(Position P, List L){

    return P->Next == NULL;
}


Position Find(ElementType X, List L){

    Position P;

    P = L->Next;

    while(P != NULL && L->Element != X) {
        P = P->Next;
    }

    return P;
}


void Delete(ElementType X, List L){
    Position p;

    p = FindPrevious(X, L);

    Position temp;

    if (IsLast(p, L))
    {
        temp = p->Next;
        p->Next = temp->Next;
        free(temp);
    }

}


Position FindPrevious(ElementType X, List L){
    Position p;

    p = L->Next;
    while(p->Next != NULL && p->Next->Element != X){
        p = p->Next;
    }

    return p;
}


void Insert(ElementType X, List L, Position P){
    Position temp;

    temp = (Position)malloc(sizeof(struct Node));
    assert(temp);

    temp->Element = X;
    temp->Next = P->Next;
    P->Next = temp;
}


void DeleteList(List L){
    Position p;

    p = L->Next;
    L->Next = NULL;
    Position temp;
    while(p->Next != NULL) {
       temp = p->Next;
       free(p);
       p = temp;
    }
}

