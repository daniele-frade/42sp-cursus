#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef> // size_t

// 1-address of an array
// 2-length of the array
// 3-function that will be called on every element of the array
template <typename T, typename Func>
void iter(T* array, size_t length, Func func) {
    if (array == NULL)
        return;
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T>
void printer(T element) {
    std::cout << element << std::endl;
}

#endif