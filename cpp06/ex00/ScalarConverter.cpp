/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:10:01 by ghwa              #+#    #+#             */
/*   Updated: 2025/01/17 10:48:56 by ghwa             ###   ########.fr       */
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
	std::stringstream ss(literal);
	try {
		if (isChar(literal)) {
			char c;
			ss >> c;
			print(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c), true);
		}
		else if (isInt(literal)) {
			int i;
			ss >> i;
			print(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i), isprint(i));
		}
		else if (isFloat(literal)) {
			float f;
			ss >> f;
			print(0, static_cast<int>(f), f, static_cast<double>(f), false);
		}
		else if (isDouble(literal)) {
			double d;
			ss >> d;
			print(0, static_cast<int>(d), static_cast<float>(d), d, false);
		}
		else if (literal == "nan" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "-inff" || literal == "+inff")
			printnan(literal);
		else
			throw std::invalid_argument("Invalid literal format");

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
	int decimal = 0;

	if ((literal[0] == '+' || literal[0] == '-'))
		i++;
	while (i < literal.length() && std::isdigit(literal[i]))
		i++;
	while (literal[i] == '.')
		i++, decimal++;
	while (i < literal.length() && std::isdigit(literal[i]))
		i++;
	return (decimal == 1 && i == literal.length());
}

bool ScalarConverter::isDouble(const std::string &literal) {
	size_t i = 0;
	int decimal = 0;

	if ((literal[0] == '+' || literal[0] == '-'))
		i++;
	while (i < literal.length() && std::isdigit(literal[i]))
		i++;
	while (literal[i] == '.')
		i++, decimal++;
	while (i < literal.length() && std::isdigit(literal[i]))
		i++;

	if (i < literal.length() && (literal[i] == 'e' || literal[i] == 'E')) {
		i++;
		if (literal[i] == '+' || literal[i] == '-') {
			i++;
		}
		if (i < literal.length() && std::isdigit(literal[i])) {
			while (i < literal.length() && std::isdigit(literal[i]))
				i++;
		} else
			return false;
	}
	return (decimal == 1 && i == literal.length());
}

std::string intToString(int i) {
	std::ostringstream oss;
	oss << i;
	return oss.str();
}

void ScalarConverter::print(char c, int i, float f, double d, bool validChar) {
	std::cout << "char: \'" << (validChar ? std::string(1, c) : "Non displayable") << "\'\n";

	std::cout << "int: " << (i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min() ? "impossible" : intToString(i)) << "\n";

	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf\n";
	else if (std::isinf(f))
		std::cout << (f < 0 ? "-inff" : "inff") << "\n";
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f\n";

	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan\n";
	else if (std::isinf(d))
		std::cout << (d < 0 ? "-inf" : "inf") << "\n";
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::printnan(const std::string &literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nan" || literal == "+inf" || literal == "-inf") {
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
	}
	if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
	}
}
