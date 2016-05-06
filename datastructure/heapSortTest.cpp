/*
 * FileName: test.cpp
 * Copyright (C) 2014-08-25 21:22 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include "heapSort.hpp"
#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a[] = {256, 90, 123213, 3, 0 , 12, 24 , 35, 4};
    int size = sizeof(a) / sizeof(a[0]);

    HeapSort<int> hs;
    printf("size is: %d\n", size);
    for(int i = size / 2 ; i >= 1; i-- )
      hs.buildMaxHeap(a -1, i, size);

    printf("Is Max Heap: %d\n", hs.isMaxHeap(a-1, 1, size));
    hs.maxHeapSort(a-1, size);
    for(int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    for(int i = size / 2 ; i >= 1; i-- )
      hs.buildMinHeap(a -1, i, size);

    printf("Is Min Heap: %d\n", hs.isMinHeap(a-1, 1, size));
    hs.minHeapSort(a-1, size);
    for(int i = 0; i < size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
return 0;
}



