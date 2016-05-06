/*
 * binarySearch.cpp
 * Copyright (C) 2014-09-02 10:52 AlbertTK <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */
#include <stdio.h>

int binarySearch(int array[], int left, int right, int k){

   if (left == right && array[left] != k) {
       return -1;
   }

    int mid = (left + right) / 2;

    if(array[mid] == k){
        return mid;
    }

    if(array[mid] > k){
        return binarySearch(array, left, mid, k);
    }

    if(array[mid] < k){
        return binarySearch(array, mid + 1, right, k);
    }

    return -1;
}

int binSearch(int array[], int size, int searchValue){
    return binarySearch(array, 0, size -1, searchValue);
}


int main(int argc, char *argv[])
{
    int test[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(test) / sizeof(test[0]);

    int pos;
    for(int i = 0; i < size + 3; i++){
        pos = binSearch(test, size, i);
        printf("i = %d; pos = %d\n", i, pos);
    }
    return 0;
}

