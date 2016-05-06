/*
 * maxSubSum.c
 * Copyright (C) 2014-08-29 10:11 AlbertTK <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include "maxSubSum.h"

// 运行时间为O(N)
int maxSubSum(const int *array, int size){
    int i;
    int sum = 0;
    int maxSum = 0;

    for (i = 0; i < size; ++i)
    {
        sum += array[i];
        if(sum < 0){
            sum = 0;
        }
        if (sum > maxSum)
        {
            maxSum = sum;
        }
    }

    return maxSum;
}


//运行时间为O(Nlog(N))
//采用分治的思想，将序列分为左边部分，右边部分和中间部分求取最大子序列和

int Max3(int a, int b, int c){

    int temp = a > b ? a : b;

    return c > temp ? c : temp;

}
int getMaxSub(const int *array, int left, int right){
    int leftMaxSum = 0;
    int rightMaxSum = 0;
    int middleLeftSum = 0;
    int middleRightSum = 0;

    if (left == right)
    {
        if (array[left] > 0)
        {
            return array[left];
        }

        return 0;
    }

    int center = (left + right) / 2;

    leftMaxSum = getMaxSub(array, left, center);
    rightMaxSum = getMaxSub(array, center + 1, right);

    //求出跨中间的最大值
    int i;
    int sum = 0;

    for( i = center; i >= 0; i--){
        sum += array[i];
        if(sum > middleLeftSum)
            middleLeftSum = sum;
    }

    sum = 0;
    for (i = center + 1; i < right; ++i)
    {
        sum += array[i];
        if(sum > middleRightSum)
            middleRightSum = sum;
    }

    return Max3(leftMaxSum, rightMaxSum, middleLeftSum + middleRightSum);
}
int maxSubSum2(const int *array, int size){
    return getMaxSub(array, 0, size - 1);
}
