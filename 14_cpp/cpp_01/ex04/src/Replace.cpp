#include "Replace.hpp"
#include <fstream>
#include <iostream>

Replace::Replace(const std::string &filename, const std::string &s1, const std::string &s2)
    : filename(filename), s1(s1), s2(s2) {}

Replace::~Replace() {}

std::string Replace::replaceOccurrences(const std::string &content) const {
    std::string result;
    size_t pos = 0;
    size_t len = s1.length();

    while (true) {
        size_t foundPos = content.find(s1, pos);

        if (foundPos == std::string::npos) {
            result += content.substr(pos);
            break;
        }

        result += content.substr(pos, foundPos - pos);
        result += s2;
        pos = foundPos + len;
    }
    return result;
}

void Replace::replaceOccurrencesInFile() const {
    // Convert std::string to const char* for ifstream and ofstream
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << filename << std::endl;
        return;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not open output file: " << outputFilename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << replaceOccurrences(line) << std::endl;
    }

    inputFile.close();
    outputFile.close();
}
