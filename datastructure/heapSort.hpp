/*
 * heapSort.hpp
 * Copyright (C) 2014-08-28 21:44 AlbertTK <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <algorithm>

template<class T>
class HeapSort
{
    public:
        HeapSort ();
        virtual ~HeapSort ();

        void buildMaxHeap(T *array, int pos, int size);
        bool isMaxHeap(T *array, int pos, int size);
        void maxHeapSort(T *array, int size);

        void buildMinHeap(T *array, int pos, int size);
        bool isMinHeap(T *array, int pos, int size);
        void minHeapSort(T *array, int size);
    private:
        /* data */
};

template<class T>
HeapSort<T>::HeapSort(){

}


template<class T>
HeapSort<T>::~HeapSort(){

}


template<class T>
void HeapSort<T>::buildMaxHeap(T *array, int pos, int size){
    int lchild;
    int rchild;
    int max;

    while(1){
        lchild = pos * 2;
        rchild = pos * 2 + 1;
        max = pos;

        if(lchild <= size && array[lchild] > array[max]){
            max = lchild;
        }

        if(rchild <= size && array[rchild] > array[max]){
            max = rchild;
        }

        if (max == pos)
        {
            break;
        }

        std::swap(array[max], array[pos]);
        pos = max;
    }

}


template<class T>
bool HeapSort<T>::isMaxHeap(T *array, int pos, int size){
    int lchild = pos * 2;
    int rchild = pos * 2 + 1;

    if(lchild <= size && array[lchild] > array[pos]){
        return false;
    }

    if (lchild <= size && 0 == isMaxHeap(array, lchild, size))
    {
        return false;
    }

    if(rchild <= size && array[rchild] > array[pos]){
        return false;
    }

    if (rchild <= size && 0 == isMaxHeap(array, rchild, size))
    {
        return false; 
    }

    return true;
}


template<class T>
void HeapSort<T>::maxHeapSort(T *array, int size){
    while(size > 0) {
        std::swap(array[1], array[size]);
        size--;
        buildMaxHeap(array, 1, size);
    }
}


template<class T>
void HeapSort<T>::buildMinHeap(T *array, int pos, int size){
    int lchild;
    int rchild;
    int min;

    while(1){
        lchild = pos * 2;
        rchild = pos * 2 + 1;
        min = pos;

        if(lchild <= size && array[lchild] < array[min]){
            min = lchild;
        }

        if(rchild <= size && array[rchild] < array[min]){
            min = rchild;
        }

        if (min == pos)
        {
            break;
        }

        std::swap(array[min], array[pos]);
        pos = min;
    }


}

template<class T>
bool HeapSort<T>::isMinHeap(T *array, int pos, int size){
    int lchild = pos * 2;
    int rchild = pos * 2 + 1;

    if(lchild <= size && array[lchild] < array[pos]){
        return false;
    }

    if (lchild <= size && 0 == isMinHeap(array, lchild, size))
    {
        return false;
    }

    if(rchild <= size && array[rchild] < array[pos]){
        return false;
    }

    if (rchild <= size && 0 == isMinHeap(array, rchild, size))
    {
        return false; 
    }

    return true;

}


template<class T>
void HeapSort<T>::minHeapSort(T *array, int size){
    while(size > 0) {
        std::swap(array[1], array[size]);
        size--;
        buildMinHeap(array, 1, size);
    }

}
#endif /* !HEAPSORT_HPP */
