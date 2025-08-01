#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
    // --- STEP 1: INITIAL STATE ---
    std::cout << "--- STEP 1: INITIAL STATE ---" << std::endl;
    Data originalData(42, "Hello World", 3.14159);
    
    std::cout << "\nOriginal Data Object Created:" << std::endl;
    std::cout << "  Value: " << originalData.getValue() << std::endl;
    std::cout << "  Name: " << originalData.getName() << std::endl;
    std::cout << "  Decimal: " << originalData.getDecimal() << std::endl;
    std::cout << "Original Data address: " << &originalData << std::endl;
    std::cout << "-----------------------------" << std::endl;

    // --- STEP 2: SERIALIZATION ---
    std::cout << "\n--- STEP 2: SERIALIZATION ---" << std::endl;
    std::cout << "Converting the original Data pointer to an integer..." << std::endl;
    uintptr_t serializedPtr = Serializer::serialize(&originalData);
    
    std::cout << "Serialized integer value (uintptr_t): " << serializedPtr << std::endl;
    std::cout << "-----------------------------" << std::endl;

    // --- STEP 3: DESERIALIZATION ---
    std::cout << "\n--- STEP 3: DESERIALIZATION ---" << std::endl;
    std::cout << "Converting the integer value back to a Data pointer..." << std::endl;
    Data* deserializedDataPtr = Serializer::deserialize(serializedPtr);
    
    std::cout << "Deserialized pointer (Data*): " << deserializedDataPtr << std::endl;
    std::cout << "-----------------------------" << std::endl;

    // --- STEP 4: VERIFICATION ---
    std::cout << "\n--- STEP 4: VERIFICATION ---" << std::endl;
    std::cout << "Comparing original and deserialized pointers." << std::endl;

    if (&originalData == deserializedDataPtr) {
        std::cout << "\nSUCCESS: Original pointer and deserialized pointer ARE EQUAL." << std::endl;
    } else {
        std::cout << "\nFAILURE: Original pointer and deserialized pointer ARE NOT EQUAL." << std::endl;
    }
    
    std::cout << "\nVerifying data integrity by accessing through the new pointer:" << std::endl;
    std::cout << "  Value: " << deserializedDataPtr->getValue() << std::endl;
    std::cout << "  Name: " << deserializedDataPtr->getName() << std::endl;
    std::cout << "  Decimal: " << deserializedDataPtr->getDecimal() << std::endl;
    std::cout << "-----------------------------" << std::endl;
    
    return 0;
}