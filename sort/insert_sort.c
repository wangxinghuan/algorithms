/***************************************************************************
function: insert_sort
description: This is a function use insertion sort algorithm
usage: void insert_sort(int temp[], int direction)
notice: The function will change the sort of array content, so you should 
use a temp array instead of the original array. 
the direction can be set to 0 instead of decline or 1 instead of  
increase.
 ***************************************************************************/
#ifndef _STDIO_H
#define _STDIO_H
#endif

int insert_sort(int array[], int direction, int length){
    int i, j, key;

    if ( direction == 1 ){
        for (j = 1; j < length; j++) {
            key = array[j];
            i = j - 1;
            while ( i >= 0 && array[i] > key ) {
                array[i+1] = array[i];
                i--;
            }
            array[i+1] = key;
        }
    }

    else if(direction == 0 ){
        for(j = 1; j < length; j++){
            i = j - 1;
            key = array[j];
            while ( i >= 0 && array[i] < key ) {
                array[i+1] = array[i];
                i--;
            }
            array[i+1] = key;
        }
    }
    else {
        printf("Input error!\n");
        return -1;
    }
    return 0;
}
