#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>

class Replace {
private:
    std::string filename;  // Stores the name of the file
    std::string s1;        // The substring to search for
    std::string s2;        // The substring to replace with

	// Helper function to replace occurrences of s1 with s2 in a string
    std::string replaceOccurrences(const std::string &content) const;

public:
    // Constructor initializing filename, s1, and s2
    Replace(const std::string &filename, const std::string &s1, const std::string &s2);
    // Destructor
    ~Replace();
    // Performs the file replacement operation
    void replaceOccurrencesInFile() const;
    
};

#endif