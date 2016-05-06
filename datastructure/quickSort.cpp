/*
 * FileName: qSort.cpp
 * Copyright (C) 2014-08-25 15:31 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include <stdio.h>


void quickSort(int array[], int left, int right){
    if (left >= right) {
        return;
    }

    int low = left;
    int high = right;

    int key = array[left];

    while(left < right && key <= array[right]){
        --right;
    }
    array[left] = array[right];
    while(left < right && array[left] <= key){
        ++left;
    }
    array[right] = array[left];
    
    array[left] = key;

    quickSort(array, low, left - 1);
    quickSort(array, left + 1, high);

}



int main(int argc, const char *argv[])
{
    int a [] = {1, 2, 5, 2, 3, 4, 1, 6};

    int size = sizeof(a) / sizeof(a[0]);
    quickSort(a, 0, size - 1);


    for(int i = 0; i < size; i++){
        printf("a[%d] = %d \n", i, a[i]);
    }
    return 0;
}
