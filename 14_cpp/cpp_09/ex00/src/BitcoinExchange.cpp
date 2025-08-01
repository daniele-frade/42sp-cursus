#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>

// OCF
BitcoinExchange::BitcoinExchange() {
    // attempt to load the database file upon construction
    try {
        loadDatabase("data.csv");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(1); // exit if database cannot be loaded.
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _exchangeRates(other._exchangeRates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// loads the exchange rate data from the provided CSV file.
void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Could not open database file: " + filename);
    }

    std::string line;
    std::getline(file, line); 

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string dateStr;
        std::string priceStr;

        if (std::getline(ss, dateStr, ',') && std::getline(ss, priceStr)) {
            float price;
            std::stringstream priceSs(priceStr);
            if (!(priceSs >> price) || priceSs.peek() != EOF) {
                std::cerr << "Warning: Bad price format in database line: " << line << std::endl;
                continue;
            }
            _exchangeRates[dateStr] = price;
        } else {
            std::cerr << "Warning: Bad line format in database: " << line << std::endl;
        }
    }
    file.close();
    if (_exchangeRates.empty()) {
        throw std::runtime_error("Database is empty or could not be parsed.");
    }
}

// parses date string into year, month, day components
void BitcoinExchange::parseDate(const std::string& date, int& year, int& month, int& day) const {
    std::stringstream ss(date);
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;
}

// checks if a year is a leap year
bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// validates if a date (year, month, day) is a real calendar date
bool BitcoinExchange::isValidCalendarDate(int year, int month, int day) const {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year)) {
        daysInMonth[2] = 29;
    }
    return day <= daysInMonth[month];
}

// validates the date string format (YYYY-MM-DD) and calendar validity
bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    int year, month, day;
    try {
        year = std::atoi(date.substr(0, 4).c_str());
        month = std::atoi(date.substr(5, 2).c_str());
        day = std::atoi(date.substr(8, 2).c_str());
    } catch (...) {
        return false;
    }

    if (!isValidCalendarDate(year, month, day)) {
        return false;
    }
    return true;
}

// validates the value string(positive or float, range 0 and 1000)
bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const {
    std::stringstream ss(valueStr);
    // check if conversion succeeded and no extra chars
    if (!(ss >> value) || ss.peek() != EOF) {
        return false;
    }
    if (value < 0) {
        // specific error message from subject
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    // specific error message from subject
    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

// --- Public Method Implementation ---

// processes each line of the input file
void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        // Specific error message from subject
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty() || line.find_first_not_of(" \t\r\n") == std::string::npos) {
            continue;
        }

        std::stringstream ss(line);
        std::string dateStr;
        std::string valueStr;
        std::string pipeSeparator;

        // parse format "date | value"
        if (!std::getline(ss, dateStr, ' ') || !std::getline(ss, pipeSeparator, ' ') || pipeSeparator != "|" || !std::getline(ss, valueStr)) {
            // specific error message from subject
            std::cerr << "Error: bad input => " << line << std::endl;
            continue; // move to next line
        }

        // trim whitespace from dateStr and valueStr if necessary
        dateStr.erase(dateStr.find_last_not_of(" \t\r\n") + 1);
        dateStr.erase(0, dateStr.find_first_not_of(" \t\r\n"));
        valueStr.erase(valueStr.find_last_not_of(" \t\r\n") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t\r\n"));

        // validate date
        if (!isValidDate(dateStr)) {
            // specific error message from subject
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // validate value
        float value;
        if (!isValidValue(valueStr, value)) {
            // error message already printed by isValidValue
            continue;
        }

        // find the exchange rate: std::map::upper_bound returns an iterator
        // to the first element with a key greater than 'dateStr'
        std::map<std::string, float>::const_iterator it = _exchangeRates.upper_bound(dateStr);

        if (it == _exchangeRates.begin()) {
            std::cerr << "Error: No exchange rate found for date " << dateStr << " (too early)." << std::endl;
            continue;
        }
        --it;
        // calculate and display the result
        std::cout << dateStr << " => " << value << " = "
                  << std::fixed << std::setprecision(2)
                  << value * it->second << std::endl;
    }
    file.close();
}