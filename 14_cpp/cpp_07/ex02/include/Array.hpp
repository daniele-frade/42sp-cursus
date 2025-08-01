#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

template <typename T>
class Array {
private:
    T*		_elements;
    size_t	_size;

public:
    // 1. Construction with no parameter: Creates an empty array
    Array() : _elements(NULL), _size(0) {}

    // 2. Construction with an unsigned int n as a parameter: Creates an array of n elements (initialized by default)
    Array(unsigned int n) : _size(n) {
        _elements = new T[n](); // Use new[] to allocate memory. () for value initialization
    }

    // 3. Construction by copy and assignment operator
    // Modifying either the original array or its copy after copying mustn't affect the other array
    Array(Array const& other) : _elements(NULL), _size(other._size) {
        if (_size > 0) {
            _elements = new T[_size]; // Allocate new memory for the copy
            for (size_t i = 0; i < _size; ++i) {
                _elements[i] = other._elements[i]; // Deep copy elements
            }
        }
    }

    Array& operator=(Array const& other) {
        if (this != &other) {
            delete[] _elements; // Free existing memory

            _size = other._size;
            if (_size > 0) {
                _elements = new T[_size]; // Allocate new memory
                for (size_t i = 0; i < _size; ++i) {
                    _elements[i] = other._elements[i]; // Deep copy elements
                }
            } else {
                _elements = NULL; // If other is empty, set to NULL
            }
        }
        return *this;
    }

    // Destructor: Free allocated memory
    ~Array() {
    	delete[] _elements;
    }

    // Elements can be accessed through the subscript operator: []
    // When accessing an element with the [] operator, if its index is out of bounds, an std::exception is thrown.
    T& operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Array index out of bounds.");
        }
        return _elements[index];
    }

    // Overload for const Array instances (read-only access)
    const T& operator[](size_t index) const {
        if (index >= _size) { // Check for out of bounds
            throw std::out_of_range("Array index out of bounds (const access).");
        }
        return _elements[index];
    }

    // A member function size() that returns the number of elements in the array
    // This member function takes no parameters and must not modify the current instance
    size_t size() const {
        return _size;
    }

    // Custom exception class for out of bounds access (optional, but good for clarity)
    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Array index is out of bounds!";
        }
    };
};

#endif