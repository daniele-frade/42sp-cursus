#include <iostream>
#include <string>
#include "Array.hpp"

// Function to print array elements
template <typename T>
void printArray(const Array<T>& arr, const std::string& name) {
    std::cout << name << " (size: " << arr.size() << "): [";
    for (size_t i = 0; i < arr.size(); ++i) {
        try {
            std::cout << arr[i];
            if (i < arr.size() - 1)
                std::cout << ", ";
        } catch (const std::exception& e) {
            std::cout << "Error accessing element: " << e.what();
        }
    }
    std::cout << "]" << std::endl;
}

int main() {
    std::cout << "--- Test 1: Default constructor (empty array) ---" << std::endl;
    Array<int> emptyArray;
    printArray(emptyArray, "emptyArray");
    std::cout << std::endl;

    std::cout << "--- Test 2: Size constructor and initialization ---" << std::endl;
    Array<int> intArray(5); // Creates an array of 5 ints, initialized to 0
    printArray(intArray, "intArray");
    for (size_t i = 0; i < intArray.size(); ++i) {
        intArray[i] = i + 1; // Assign values
    }
    printArray(intArray, "intArray (assigned)");
    std::cout << std::endl;

    std::cout << "--- Test 3: Copy constructor ---" << std::endl;
    Array<int> copiedArray = intArray; // Calls copy constructor
    printArray(copiedArray, "copiedArray");
    // Modify original and check copy
    intArray[0] = 99;
    std::cout << "After modifying intArray[0]:" << std::endl;
    printArray(intArray, "intArray");
    printArray(copiedArray, "copiedArray"); // Should remain unchanged
    std::cout << std::endl;

    std::cout << "--- Test 4: Assignment operator ---" << std::endl;
    Array<int> assignedArray(3); // Smaller array
    for (size_t i = 0; i < assignedArray.size(); ++i) {
        assignedArray[i] = 10 + i;
    }
    printArray(assignedArray, "assignedArray (initial)");

    assignedArray = copiedArray; // Calls assignment operator
    std::cout << "After assignedArray = copiedArray:" << std::endl;
    printArray(assignedArray, "assignedArray");
    // Modify copiedArray and check assignedArray
    copiedArray[0] = 77;
    std::cout << "After modifying copiedArray[0]:" << std::endl;
    printArray(copiedArray, "copiedArray");
    printArray(assignedArray, "assignedArray"); // Should remain unchanged
    std::cout << std::endl;

    std::cout << "--- Test 5: Access with operator[] and out of bounds exception ---" << std::endl;
    try {
        std::cout << "Accessing intArray[2]: " << intArray[2] << std::endl;
        std::cout << "Attempting to access intArray[10] (out of bounds)..." << std::endl;
        std::cout << intArray[10] << std::endl; // This should throw an exception
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught generic exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 6: Const access ---" << std::endl;
    const Array<int> constArray = intArray; // Uses copy constructor
    printArray(constArray, "constArray");
    try {
        std::cout << "Accessing constArray[1]: " << constArray[1] << std::endl;
        // constArray[0] = 1; // This would cause a compile-time error, as expected
        std::cout << "Attempting to access constArray[10] (out of bounds)..." << std::endl;
        std::cout << constArray[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 7: Array of complex types (std::string) ---" << std::endl;
    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "Templates";
    printArray(stringArray, "stringArray");

    Array<std::string> copiedStringArray = stringArray;
    copiedStringArray[0] = "Hola";
    std::cout << "After modifying copiedStringArray[0]:" << std::endl;
    printArray(stringArray, "stringArray");
    printArray(copiedStringArray, "copiedStringArray");
    std::cout << std::endl;

    return 0;
}

// Main from subject:
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }