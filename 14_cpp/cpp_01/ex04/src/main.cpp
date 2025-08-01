#include "Replace.hpp"
#include <iostream>

// Function to print error messages
void printError(const std::string &error) {
    std::cerr << "Error: " << error << std::endl;
}

int main(int argc, char **argv) {
    // Check if the number of arguments is correct
    if (argc != 4) {
        printError("Usage: ./replace <filename> <string_to_replace> <replacement_string>");
        return 1;
    }

    // Extract arguments from command line
    std::string sourceFile = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Validate that none of the input strings are empty
    if (sourceFile.empty()) {
        printError("Filename cannot be empty.");
        return 1;
    }
    if (s1.empty()) {
        printError("The string to replace (s1) cannot be empty.");
        return 1;
    }
    if (s2.empty()) {
        printError("The replacement string (s2) cannot be empty.");
        return 1;
    }

    // Create a Replace object and perform the replacement operation
    Replace replacer(sourceFile, s1, s2);
    replacer.replaceOccurrencesInFile();

    return 0;
}

// Test: ./replace src/test.txt "were" "are"