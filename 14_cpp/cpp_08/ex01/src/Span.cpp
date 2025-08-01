#include "Span.hpp"
#include <iostream> 

Span::Span(unsigned int N) : _maxSize(N) {
    _data.reserve(N);
}

Span::Span(const Span& other) : _data(other._data), _maxSize(other._maxSize) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _data = other._data;
        _maxSize = other._maxSize;
    }
    return *this;
}

Span::~Span() {}

// Optional getter for data
const std::vector<int>& Span::getNumbers() const {
    return _data;
}

// Add a single number to the Span 
void Span::addNumber(int number) {
    if (_data.size() < _maxSize) {
        _data.push_back(number);
    } else {
        throw SpanFullException();
    }
}

// Find the shortest span (distance) between numbers 
long Span::shortestSpan() const {
    if (_data.size() < 2) {
        throw NotEnoughNumbersException();
    }

    // Create a copy to sort without modifying the original data
    std::vector<int> sortedData = _data;
    std::sort(sortedData.begin(), sortedData.end());
    
    // Initialize with max possible value
    long minSpan = std::numeric_limits<long>::max();

    // Iterate through sorted data to find the smallest difference between adjacent elements
    for (size_t i = 0; i < sortedData.size() - 1; ++i) {
        long currentSpan = static_cast<long>(sortedData[i+1]) - sortedData[i];
        if (currentSpan < minSpan) {
            minSpan = currentSpan;
        }
    }
    return minSpan;
}

// Find the longest span (distance) between numbers 
long Span::longestSpan() const {
    if (_data.size() < 2) {
        throw NotEnoughNumbersException();
    }

    // Find min and max elements using std::min_element and std::max_element
    int minVal = *std::min_element(_data.begin(), _data.end());
    int maxVal = *std::max_element(_data.begin(), _data.end());

    return static_cast<long>(maxVal) - minVal;
}