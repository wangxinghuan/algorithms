#include "insert_sort.h"
#include <stdio.h>
int main(int argc, const char *argv[])
{
    int a[5] = {103,2,24,5,6};
    int i;
    printf("a : %ld\n", sizeof(a)/sizeof(a[0]));
    insert_sort(a,1,5);
    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
