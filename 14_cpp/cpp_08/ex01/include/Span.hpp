#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <numeric>
# include <limits>

class Span {
private:
    std::vector<int> _data;
    unsigned int     _maxSize;

public:
    // OCF
    Span(unsigned int N); 
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    // Member functions
    void addNumber(int number);
    long shortestSpan() const;
    long longestSpan() const;


    // Optional getter for data
    const std::vector<int>& getNumbers() const;

    // Template member function to add a range of numbers 
    template <typename InputIt>
    void addNumbers(InputIt first, InputIt last) {
        // Calculate the number of elements in the range
        size_t count = 0;
        for (InputIt it = first; it != last; ++it) {
            count++;
        }
        // Check if adding the range would exceed _maxSize 
        if (_data.size() + count > _maxSize) {
            throw std::out_of_range("Cannot add range: Exceeds Span capacity.");
        }
        // Add the elements using std::vector's insert method
        _data.insert(_data.end(), first, last);
    }

    // Exception classes
    class SpanFullException : public std::runtime_error {
    public:
        SpanFullException() : std::runtime_error("Span is full, cannot add more numbers.") {}
    };

    class NotEnoughNumbersException : public std::logic_error {
    public:
        NotEnoughNumbersException() : std::logic_error("Not enough numbers to calculate span (need at least 2).") {}
    };
};

#endif