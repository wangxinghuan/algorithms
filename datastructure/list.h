/*
 * list.h
 * Copyright (C) 2014-09-09 16:14 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#ifndef LIST_H
#define LIST_H

typedef int ElementType;
struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeList(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
//Position Header(List L);
//Position First(List L);
//Position Advance(List L);
//ElementType Retrieve(Position P);

#endif /* !LIST_H */
