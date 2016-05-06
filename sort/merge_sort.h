/***************************************************************************
function: merge_sort

description : This is a function use merge sort algorithm 

usage:
        void merge_sort(int start, int end, int temp[])

        The function will change the contents order of temp, so you showuld         use a temp array instead of the original if you don't want to change        the contents

        the length of array can be calculated by sizeof(array_name)/sizeof(a        rray_name[0])

        Interesting, you can choose the start or end of any position of the         array.For example, u can set start = 2 to start from the second para        metric,and set end = 4 to end up with the fourth parametric.

return value:
        On success, this call return 1, On error, -1 is returned
***************************************************************************/

void merge(int start, int mid, int end , int a[]){
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1];
    int right[n2];
    int i, j, k;

    for (i = 0; i < n1; i++) {
        left[i] = a[start + i];
    }
    for (j = 0; j < n2; j++) {
        right[j] = a[mid + 1 + j];
    }

    i = j = 0;
    k = start;
    while ( i < n1 && j < n2 ) {
        if ( left[i] < right[j] ) {
            a[k++] = left[i++];
        }
        else {
            a[k++] = right[j++];
        }
    }
    while ( i < n1 ) {
        a[k++] = left[i++];
    }
    while ( j < n2 ) {
        a[k++] = right[j++];
    }
}

int merge_sort(int start, int end, int a[]){
    if (start > end) {
        return -1;
    }
    int mid;
    if(start < end) {
        mid = (start + end) / 2;
        merge_sort(start, mid, a);
        merge_sort(mid + 1, end, a);
        merge(start, mid, end, a);
    } 
    return 0;
}
