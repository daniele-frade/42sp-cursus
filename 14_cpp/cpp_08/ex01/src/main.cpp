#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <cstdlib>
#include <ctime>

int main() {

    // --- Test Case 1: Example from subject ---
    std::cout << "\n--- Subject Example Test ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Numbers in Span: ";
        for (size_t i = 0; i < sp.getNumbers().size(); ++i) {
            std::cout << sp.getNumbers()[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl; // Expected: 2
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;  // Expected: 14
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // --- Test Case 2: Adding to a full Span ---
    std::cout << "\n--- Test: Adding to Full Span ---" << std::endl;
    try {
        Span sp_full(3);
        sp_full.addNumber(1);
        sp_full.addNumber(2);
        sp_full.addNumber(3);
        std::cout << "Span is full, trying to add 4..." << std::endl;
        sp_full.addNumber(4); // Should throw SpanFullException
        std::cout << "This line should not be printed." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // --- Test Case 3: Not enough numbers for span calculation ---
    std::cout << "\n--- Test: Not Enough Numbers ---" << std::endl;
    try {
        Span sp_one(1);
        sp_one.addNumber(42);
        std::cout << "Span has one number, trying shortestSpan..." << std::endl;
        sp_one.shortestSpan(); // Should throw NotEnoughNumbersException
        std::cout << "This line should not be printed." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Span sp_empty(5);
        std::cout << "Span is empty, trying longestSpan..." << std::endl;
        sp_empty.longestSpan(); // Should throw NotEnoughNumbersException
        std::cout << "This line should not be printed." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // --- Test Case 4: Adding a range of numbers (small) ---
    std::cout << "\n--- Test: Add Range (Small) ---" << std::endl;
    try {
        Span sp_range(10);
        std::vector<int> numbers_to_add;
        for (int i = 0; i < 5; ++i) {
            numbers_to_add.push_back(i * 2 + 1); // 1, 3, 5, 7, 9
        }
        sp_range.addNumbers(numbers_to_add.begin(), numbers_to_add.end());
        std::cout << "Numbers added from range: ";
        for (size_t i = 0; i < sp_range.getNumbers().size(); ++i) {
            std::cout << sp_range.getNumbers()[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Shortest Span: " << sp_range.shortestSpan() << std::endl; // Expected: 2
        std::cout << "Longest Span: " << sp_range.longestSpan() << std::endl;  // Expected: 8
    } catch (const std::exception& e) { //
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // --- Test Case 5: Adding a range that exceeds capacity ---
    std::cout << "\n--- Test: Add Range (Exceeds Capacity) ---" << std::endl;
    try {
        Span sp_range_fail(3); // Capacity of 3
        std::vector<int> big_numbers;
        for (int i = 0; i < 5; ++i) { // 5 numbers to add
            big_numbers.push_back(i);
        }
        std::cout << "Span capacity: 3, trying to add 5 numbers from range..." << std::endl;
        sp_range_fail.addNumbers(big_numbers.begin(), big_numbers.end()); // Should throw
        std::cout << "This line should not be printed." << std::endl;
    } catch (const std::exception& e) { //
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    // --- Test Case 6: Large number test (at least 10,000 numbers)  ---
    std::cout << "\n--- Test: Large Number Test (10,000+) ---" << std::endl;
    unsigned int large_n = 15000; // Testing with 15,000 numbers
    try {
        Span large_sp(large_n);
        std::vector<int> large_numbers_vec;
        large_numbers_vec.reserve(large_n); // Pre-allocate for efficiency

        // Seed random number generator
        std::srand(static_cast<unsigned int>(std::time(0)));

        // Fill with random numbers or a sequence for predictable spans
        // For predictable spans, let's use a sequence
        for (unsigned int i = 0; i < large_n; ++i) {
             large_numbers_vec.push_back(i * 2);
        }
        large_numbers_vec.push_back(-5); // Introduce a very small number
        large_numbers_vec.push_back(30005); // Introduce a very large number

        // Shuffle for more realistic test of min/max element
        std::random_shuffle(large_numbers_vec.begin(), large_numbers_vec.end());

        // Add them using the range function
        large_sp.addNumbers(large_numbers_vec.begin(), large_numbers_vec.end());

        std::cout << "Added " << large_sp.getNumbers().size() << " numbers." << std::endl;
        std::cout << "Shortest Span: " << large_sp.shortestSpan() << std::endl;
        // Expected: 1 (if 2 adjacent values like 2,3 or 4,5 exist) or 2 (from 0,2,4,...)
        std::cout << "Longest Span: " << large_sp.longestSpan() << std::endl;
        // Expected: 30005 - (-5) = 30010
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

// Main from subject:
// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }
// Expected output:
// 2
// 14