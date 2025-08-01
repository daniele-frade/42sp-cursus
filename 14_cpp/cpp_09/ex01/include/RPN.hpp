#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>

class RPN {
	private:
		// private constructor to prevent instantiation (static class)
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		
		static bool isOperator(char c);
		static bool isDigit(char c);
	public:
		// member function to evaluate RPN expression
		static int evaluate(const std::string& expression);
};

#endif