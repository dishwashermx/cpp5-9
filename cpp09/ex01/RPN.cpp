/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 08:34:22 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/08 14:21:26 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <cstdlib>
#include <string>
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

void RPN::calculate(std::string input) {
	std::istringstream iss(input);
	std::string token;

	while (iss >> token) {
		if (token.length() != 1)
			return std::cerr << "Error: token length > 1" << std::endl, void();
		if (isdigit(token[0])) {
			// std::cout << "[DEBUG] Token: " << token[0] << std::endl;
			_stack.push(token[0] - '0');
			continue ;
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/") {
			// std::cout << "[DEBUG] Operator: " << token[0] << std::endl;
			if (_stack.size() < 2)
				return std::cerr << "Error: not enough numbers to perform operation" << std::endl, void();

			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			// std::cout << "[DEBUG] A: " << a << std::endl;
			// std::cout << "[DEBUG] B: " << b << std::endl;
			int result = 0;

			if (token == "+") {
				result = a + b;
				// std::cout << "[DEBUG] A+B Result: " << result << std::endl;
			}
			else if (token == "-") {
				result = a - b;
				// std::cout << "[DEBUG] A-B Result: " << result << std::endl;
			}
			else if (token == "*") {
				result = a * b;
				// std::cout << "[DEBUG] A*B Result: " << result << std::endl;
			}
			else if (token == "/") {
				if (b == 0)
					return std::cerr << "Error: cannot divide by 0" << std::endl, void();
				result = a / b;
			// std::cout << "[DEBUG] A/B Result: " << result << std::endl;
			}
			_stack.push(result);
			continue ;
		}
		else
			return std::cerr << "Error: token is not digit or allowed operator" << std::endl, void();
		}
	if (_stack.size() != 1)
		return std::cerr << "Error: final stack is not a single number" << std::endl, void();
	std::cout << _stack.top() << std::endl;
}