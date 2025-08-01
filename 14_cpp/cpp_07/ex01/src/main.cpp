#include "Iter.hpp"

int main() {
	std::cout << "\n1.Test with an array of integers:" << std::endl;
    int intArray[] = {0, 1, 2, 3, 4, 42, 42, 42, 42, 42};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
    iter(intArray, intArrayLength, printer<int>);

	std::cout << "\n2.Test with an array of doubles:" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
    iter(doubleArray, doubleArrayLength, printer<double>);
	
	std::cout << "\n3.Test with an array of chars:" << std::endl;
    char charArray[] = {'a', 'b', 'c'};
    size_t charArrayLength = sizeof(charArray) / sizeof(charArray[0]);
    iter(charArray, charArrayLength, printer<char>);
	std::cout << std::endl;

    return 0;
}