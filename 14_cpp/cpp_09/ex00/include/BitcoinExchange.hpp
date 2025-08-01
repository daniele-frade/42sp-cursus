#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange {
private:

    // std::map = key: date (string), value: price (float for precision)
    std::map<std::string, float> _exchangeRates;

    // Loads the data.csv file into _exchangeRates map
    void loadDatabase(const std::string& filename);
    // Validates a date string format (YYYY-MM-DD)
    bool isValidDate(const std::string& date) const;
    // Converts a date string to components (year, month, day)
    void parseDate(const std::string& date, int& year, int& month, int& day) const;
    // Validates if a date is a real calendar date (e.g., Feb 30th is invalid)
    bool isLeapYear(int year) const;
    bool isValidCalendarDate(int year, int month, int day) const;
    // Validates a value string (float or positive integer between 0 and 1000)
    bool isValidValue(const std::string& valueStr, float& value) const;

public:
    // OCF
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    // Public method to process the input file and calculate bitcoin values
    void processInputFile(const std::string& filename);
};

#endif