/*
 * test.c
 * Copyright (C) 2014-11-27 19:54 AlbertTK <xingh1991@gmail.com>
 *
 * Distributed under terms of the GNU license.
 */

#include <iostream>

#include "CircleQueue.h"

int main(int argc, char *argv[])
{
    CircleQueue<int> cq;

    //add element
    cq.push_back(1);
    cq.push_back(2);
    cq.push_back(5);
    cq.push_back(6);
    cq.push_back(4);
    cq.push_back(2);

    //use iterator to get element
    std::cout << "use the iterator to get element" << std::endl;
    std::cout << "Element: ";
    for (CircleQueue<int>::iterator it = cq.begin(); it != cq.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    //use index to get element
    std::cout << "use the [] to get element" << std::endl;
    std::cout << "Element: ";
    for (CircleQueue<int>::size_type i = 0; i != cq.size(); ++i)
    {
        std::cout << cq[i] << " ";
    }
    std::cout << std::endl;

    //get valid size
    std::cout << "valid size: " << cq.size() << std::endl;
    //default value;
    std::cout << "default size: " << cq.getDefaultSize() << std::endl;
    //get max size  / capacity
    std::cout << "capacity: " << cq.capacity() << std::endl;
    //get max element
    std::cout << "max element: " << cq.getMaxElement() << std::endl;
    return 0;
}


