/*
 * test.c
 * Copyright (C) 2014-09-14 22:06 Albert Wang <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 50
#define MAX_HEIGHT 16
#define MAX_LENGTH_WITH_SPACE 600
#define MIN_LENGTH 4
#define MIN_HEIGHT 2


int getLCM(int *array, int size);

int initIntArray(int array[][MAX_LENGTH], int col[]){
    char c;
    char str[5];

    int line = 0;
    int j = 0;
    int k = 0;
    int i = 0;

    for (i = 0; i < MAX_LENGTH_WITH_SPACE; )
    {
        c = getchar();
        if ('0' <= c && c <= '9')
        {
            str[k] = c;
            k++;
        }else if(c == ' ')
        {
            while((c = getchar()) == ' ');
            ungetc(c, stdin);
            if (c == '\n' || c == '\r')
            {
                continue;
            }

            if (i == 0 && '0' <= c && c <= '9')
            {
                continue; } array[line][j] = atoi(str);
            memset(str, '\0', 5);
            k = 0;
            j++;
        }else if( c == '\n' || c == '\r')
        {
            if (i == 0)
            {
                i = 0;
                continue;
            }
            array[line][j] = atoi(str);
            memset(str, '\0', 5);
            k = 0;
            col[line] = ++j;
            j = 0;
            line++;
            i = 0;
            continue;
        }else if(c == EOF)
        {
            break;
        }else {
            return -1;
        }

        i++;
    }

    return line ;
}

int getLine(char *str, int max){
    char c;
    int i;
    int k = 0;

    for (i = 0; i < max; i++)
    {
        c = getchar();
        if ( ('0' <= c && c <= '9') || c == ' ')
        {
            str[k] = c;
            k++;
        }else if (c == '\n' || c == '\r')
        {
            return strlen(str);
        }

        if (c == EOF)
        {
            return 0;
        }
    }

    return strlen(str);
}


int setIntArray(int array[][MAX_LENGTH], int line, char * str, int len){

    char temp[5];
    int i = 0;
    int j = 0;
    int k = 0;


    for (i = 0; i <= len; ++i)
    {
        if (i == len)
        {
            array[line][j] = atoi(temp);
            return ++j;
        }
        if ( '0' <= str[i] && str[i] <= '9')
        {
            temp[k] = str[i];
            k++;
            continue;
        }

        if (str[i] == ' ')
        {
            array[line][j] = atoi(temp);
            memset(temp, '\0', 5);
            k = 0;
            j++;
        }
    }

    return j;

}


int getMinPeriod(int input[][MAX_LENGTH], int row, int col[]){

    int i;
    int flag = 0;
    int len;
    int j = 0;
    int k;
    int period = 0;

    int periodArray[row];

    for (i = 0; i < row; ++i)
    {
        len = col[i] - 1;
        for (j = 1; j <= len; ++j)
        {
            if (len % j == 0)
            {
                flag = 1;
            }
            for (k = j; k < len; ++k)
            {
                if (input[i][k] != input[i][k % j])
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
            {
                periodArray[i] = j;
                printf("min period is: %d\n", j);
                break;
            }
        }
    }

    period = getLCM(periodArray, row);

    if (len == period )
    {
       return 0;
    }

    return period;

}


int getGCD(int x, int y){

    if (x % y == 0)
    {
        return y;
    }else{
        return getGCD(y, x % y);
    }
}




//get the least common multiple
int getLCM(int *array, int size){
    int x;
    int y;
    int temp;
    int gcd = 1;
    int result = 1;
    int i;

    x = array[0];
    for (i = 0; i < size - 1; ++i)
    {
        y = array[i+1];
        if (x < y)
        {
            temp = x;
            x = y;
            y = temp;
        }

        gcd = getGCD(x, y);

        printf("the gcd is: %d\n", gcd);

        result = (x * y) / gcd;

        x = result;
    }

    return result;
}


//check Incorrect input

int isIncorrectInput(int array[][MAX_LENGTH], int row, int col[]){

    //Incorrect input

    int i;
    int j;

    if (!(MIN_HEIGHT + 1 <= row && row <= MAX_HEIGHT + 1))
    {
                return 1;
    }

    int tempCol = col[0];

    for (i = 0; i < row; ++i)
    {
        if (!(MIN_LENGTH + 1 <= col[i] && col[i] <= MAX_LENGTH + 1) || col[i] != tempCol)
        {
            return 1;
        }
    }

    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col[i]; ++j)
        {
            if(!(0 <= array[i][j] && array[i][j] <= 15)){
                return 1;
            }
        }
    }

    return 0;

}


int isNotRepresentFrieze(int array[][MAX_LENGTH], int row, int col[]){
    int i;

    //check top
    for (i = 0; i < col[0]; ++i)
    {
       if(array[0][i] & 0x03 || ((!(array[0][i] & 0x04)) && (i != col[0] - 1))){
           printf("top ............\n");
           return 1;
       }
    }

    //check bottom
    for (i = 0; i < col[row-1]; ++i)
    {
        if (array[row - 1][i] & 0x08 || ((!(array[0][i] & 0x04)) && (i != col[row-1] - 1)))
        {
           printf("bottom............\n");
            return 1;
        }
    }

    //check right
    for (i = 0; i < row; ++i)
    {
       if (array[i][col[i] - 1] & 0x0E)
       {
           printf("right............\n");
          return 1;
       }
    }

    //check crossing
    int j;
    for (i = 0; i < row - 1; ++i)
    {
        for (j = 0; j < col[i] - 1; ++j)
        {
            if ((array[i][j]& 0x08) && (array[i+1][j] & 0x02))
            {
           printf("crossing............\n");
                return 1;
            }
        }
    }


    //check period
    if(getMinPeriod(array, row, col) <= 2){
           printf("period............\n");
        return 1;
    }

    return 0;
}




int main(int argc, char *argv[])
{
    /*    char str[MAX_LENGTH_WITH_SPACE];
          int input[MAX_HEIGHT][MAX_LENGTH] = {{-1}};

          int i = 0;
          int col[MAX_LENGTH] = {0};
          int row = 0;
          int j;
          while(getLine(str,MAX_LENGTH_WITH_SPACE)) {
    //while(getline(&str ,MAX_LENGTH, stdin)) {
    //printf("%s",str);
    col[i] = setIntArray(input, i, str, strlen(str));
    i++;
    }

    row = i;
    */

    int input[MAX_HEIGHT][MAX_LENGTH] = {{-1}};
    int i;
    int j;

    int col[MAX_LENGTH];
    int row;
    int period;

    if((row = initIntArray(input, col)) == -1 ){
       printf("Incorrect input.\n");
       return EXIT_FAILURE;
    }


    printf("row = %d\n", row);
    for (i = 0; i < row; ++i)
    {
        printf("col = %d\n", col[i]);
        for (j = 0; j < col[i]; ++j)
        {
            printf("%d ", input[i][j]);
        }

        printf("\n");
    }


    //check Incorrect input
    if (isIncorrectInput(input, row, col))
    {
       printf("Incorrect input.\n");
       return EXIT_FAILURE;
    }


    //check Input does not represent a frieze

    if (isNotRepresentFrieze(input, row, col))
    {
       printf("Input does not represent a frieze.\n");
       return EXIT_FAILURE;
    }

    printf("get min period\n");

    period = getMinPeriod(input, row, col);

    printf("period is: %d\n", period);

    return 0;
}



