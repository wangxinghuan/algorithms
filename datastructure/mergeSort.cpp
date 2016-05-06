/*
 * mergeSort.cpp
 * Copyright (C) 2014-09-01 20:34 AlbertTK <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include <stdio.h>
#include <string.h>
void merge(int array[], int left, int right, int temp[]);
bool mergeSort(int array[], int n);
void mergeSortedArray(int a[], int left, int mid, int right, int temp[]);

void mergeSortedArray(int array[], int left, int mid, int right, int temp[]){

    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right){
        if(array[i] < array[j]){
            temp[k++] = array[i++];
        }

        if(array[j] < array[i]) {
            temp[k++] = array[j++];
        }

        if (array[i]  == array[j])
        {
            temp[k++] = array[i++];
            temp[k++] = array[j++];
        }
    }

    while(i <= mid){
        temp[k++] = array[i++];
    }

    while(j <= right){
        temp[k++] = array[j++];
    }

    for(i = left; i <= right; i++){
        array[i] = temp[i];
    }
}


void merge(int array[], int  left, int right, int temp[]){

    if (left == right){
        return;
    }else{
        int mid = (left + right) / 2;
        merge(array, left, mid, temp);
        merge(array, mid + 1, right, temp);
        mergeSortedArray(array, left, mid, right, temp);
    }
}


bool mergeSort(int array[], int n){
    int *temp = new int(n);

    if(temp == NULL){
        return false;
    }

    memset(temp, 0, n);
    merge(array, 0, n - 1, temp);

    return true;
}

int main()
{
    int test[] = {1, 3, 4, 2};


    int size = sizeof(test) / sizeof(test[0]);

    mergeSort(test, size);

    //int *temp = new int(size);
    //mergeSortedArray(test, 0, size / 2, size - 1, temp);
    int i;
    for (i = 0; i < size; ++i)
    {
        printf("%d ", test[i]);
    }

    printf("\n");
    return 0;
}


