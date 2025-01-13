/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:10:01 by ghwa              #+#    #+#             */
/*   Updated: 2025/01/13 15:43:44 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
	try {
		if (isChar(literal)) {
			char c = literal[0];
			print(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c), true);
		}
		if ()

	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string &literal) {
	return (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string &literal) {
	
}

bool ScalarConverter::isFloat(const std::string &literal) {

}

bool ScalarConverter::isDouble(const std::string &literal) {

}

void ScalarConverter::print(char c, int i, float f, double d, bool ValidChar) {

}