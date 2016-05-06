/*
 * CircleQueue.h
 * Copyright (C) 2014-11-27 18:21 AlbertTK <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#ifndef CIRCLEQUEUE_H
#define CIRCLEQUEUE_H

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

template <typename T>
class CircleQueue
{
public:
    //define the value_type, so the post code is away from type T
    typedef T value_type;
    typedef value_type *pointer;
    typedef value_type* iterator;
    typedef const value_type* const_iterator;
    //size_t independt of machine,more portable
    typedef size_t size_type;
    //define the reference of the element
    typedef value_type& reference;
    typedef const value_type& const_reference;
    //pointers to start, finish and end of the CircleQueue
    iterator start;
    iterator finish;
    iterator end_of_storage;
public:
    //add element
    void push_back(const value_type &);
    //get element
    iterator begin(){return start;}
    const_iterator begin() const {return start;}
    iterator end() {return finish;}
    const_iterator end() const {return finish;}
    //get valid element size
    size_type size() const {return (end() - begin());};
    //get capacity
    size_type capacity() const {return capacity_;};
    //check empty
    bool empty() const {return begin() == end();};
    //oveload the operator []
    reference operator[](size_type n){return *(begin() + n % capacity_);};
    const_reference operator[](size_type n) const {*(begin() + n % capacity_);};
    //get max element
    value_type getMaxElement() const;
    //get default size
    size_type getDefaultSize() const {
        return default_size_;
    }

    //constructor and destructor
    CircleQueue ();
    explicit CircleQueue (size_type);
    virtual ~CircleQueue ();
private:
    const size_type default_size_;
    pointer array_;
    size_type capacity_;
};


//default constructor
template <typename T>
CircleQueue<T>::CircleQueue():default_size_(3){
    array_ = new value_type[default_size_];
    start = finish = array_;
    end_of_storage = start + default_size_;
    capacity_ = default_size_;
}

//set the size of CircleQueue
template <typename T>
CircleQueue<T>::CircleQueue(size_type n):default_size_(n){
    array_ = new value_type[default_size_];
    start = finish = array_;
    end_of_storage = start + default_size_;
    capacity_ = default_size_;
}


template <typename T>
CircleQueue<T>::~CircleQueue(){
    delete array_;
}


template <typename T>
void CircleQueue<T>::push_back(const value_type& element){
    if (end_of_storage != finish)
    {
        *finish = element;
        finish++;
    }else{
        //realloc the memory
        array_ = (pointer)realloc(array_, 2 * default_size_);
        assert(array_ != NULL);
        start = array_;
        finish = start + default_size_;
        end_of_storage = start + 2 * default_size_;
        capacity_ = end_of_storage - start;

        *finish = element;
        finish++;
    }
}


template <typename T>
typename CircleQueue<T>::value_type CircleQueue<T>::getMaxElement() const {
    CircleQueue<T>::const_iterator it = begin();
    T max = *it;
    for (; it != end() ; ++it)
    {
        if (*it > max)
        {
            max = *it;
        }
    }

    return max;
}

#endif /* !CIRCLEQUEUE_H */

