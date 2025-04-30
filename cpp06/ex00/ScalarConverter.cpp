/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:10:01 by ghwa              #+#    #+#             */
/*   Updated: 2025/04/30 20:17:24 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : value("") {
	std::cout << "Default Constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const std::string &str) : value(str) {
	std::cout << "Parameterized Constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) : value(other.value) {
	std::cout << "Copy Constructor called." << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	std::cout << "Copy Assignment Operator called." << std::endl;
	if (this == &other) {
		return *this;
	}
	value = other.value;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor called" << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
	try {
		if (isChar(literal)) {
			char c = literal[0];
			print(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c), true);
		}
		else if (isInt(literal)) {
			char* end;
			long l = strtol(literal.c_str(), &end, 10);

			if (l > INT_MAX || l < INT_MIN || *end != '\0')
				throw std::out_of_range("Integer value out of range");

			int i = static_cast<int>(l);
			bool validChar = (i >= 0 && i <= 127 && isprint(i));
			print(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i), validChar);
		}
		else if (isFloat(literal)) {
			std::stringstream ss(literal);
			float f;
			ss >> f;

			int i = static_cast<int>(f);
			bool validChar = (i >= 0 && i <= 127 && isprint(i));
			print(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f), validChar);
		}
		else if (isDouble(literal)) {
			std::stringstream ss(literal);
			double d;
			ss >> d;

			int i = static_cast<int>(d);
			bool validChar = (i >= 0 && i <= 127 && isprint(i));
			print(static_cast<char>(i), i, static_cast<float>(d), d, validChar);
		}
		else if (literal == "nan" || literal == "nanf" ||
				 literal == "-inf" || literal == "+inf" || literal == "inf" ||
				 literal == "-inff" || literal == "+inff")
		{
			printnan(literal);
		}
		else {
			throw std::invalid_argument("Invalid literal format");
		}
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}


bool ScalarConverter::isChar(const std::string &literal) {
	return (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string &literal) {
	size_t i = 0;
	if ((literal[0] == '+' || literal[0] == '-') && literal.length() > 1)
		i++;
	while(i < literal.length()) {
		if (!isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}
bool ScalarConverter::isFloat(const std::string &literal) {
	size_t i = 0;
	bool hasDigit = false;
	bool hasDot = false;

	if (literal.empty())
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		++i;
	for (; i < literal.length(); ++i) {
		if (std::isdigit(literal[i])) {
			hasDigit = true;
		}
		else if (literal[i] == '.') {
			if (hasDot) return false;
			hasDot = true;
		}
		else if (literal[i] == 'f' && i == literal.length() - 1) {
			return hasDot && hasDigit;
		}
		else {
			return false;
		}
	}

	return false;
}

bool ScalarConverter::isDouble(const std::string &literal) {
	size_t i = 0;
	bool hasDot = false;
	bool hasDigit = false;

	if (literal.empty())
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		++i;
	for (; i < literal.length(); ++i) {
		if (std::isdigit(literal[i])) {
			hasDigit = true;
		}
		else if (literal[i] == '.') {
			if (hasDot) return false;
			hasDot = true;
		}
		else {
			return false;
		}
	}
	return hasDot && hasDigit;
}

std::string intToString(int i) {
	std::ostringstream oss;
	oss << i;
	return oss.str();
}

void ScalarConverter::print(char c, int i, float f, double d, bool validChar) {
	std::cout << "char: \'" << (validChar ? std::string(1, c) : "Non displayable") << "\'\n";

	std::cout << "int: " << (i > INT_MAX || i < INT_MIN ? "impossible" : intToString(i)) << "\n";

	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf\n";
	else if (std::isinf(f))
		std::cout << (f < 0 ? "-inff" : "inff") << "\n";
	else if (std::abs(f) > std::numeric_limits<float>::max())
		std::cout << "float: inff" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(2) << f << "f\n";

	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan\n";
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inf" : "inf") << "\n";
	else
		std::cout << std::fixed << std::setprecision(2) << d << std::endl;
}

void ScalarConverter::printnan(const std::string &literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf") {
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
	}
	if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
	}
}
