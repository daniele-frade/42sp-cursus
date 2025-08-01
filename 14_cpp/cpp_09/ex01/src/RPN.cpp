#include "RPN.hpp"
#include <sstream>
#include <iostream>

// OCF
RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

// helper function to check if a character is a digit
bool RPN::isDigit(char c) {
    return c >= '0' && c <= '9';
}

// helper function to check if a character is an operator
bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// main evaluation logic for RPN expression
int RPN::evaluate(const std::string& expression) {
    std::stack<int> s;
    std::stringstream ss(expression);
    std::string token;

    // iterate through each token in the expression
    while (ss >> token) {
        if (token.length() == 1 && isDigit(token[0])) {
            s.push(token[0] - '0');
        } else if (token.length() == 1 && isOperator(token[0])) {
            // if the token is a single operator (+, -, *, /)
            if (s.size() < 2) {
                throw std::runtime_error("Error: Not enough operands for operator.");
            }

            // pop the two top operands (operand2 then operand1)
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            int result;

            // perform the operation based on the operator
            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        throw std::runtime_error("Error: Division by zero.");
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    throw std::runtime_error("Error: Unknown operator.");
            }
            // push the result back onto the stack
            s.push(result);
        } else {
            throw std::runtime_error("Error: Invalid input.");
        }
    }

    // after processing all tokens, the stack should contain exactly one result
    if (s.size() != 1) {
        throw std::runtime_error("Error: Invalid expression.");
    }

    return s.top();
}