/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:10:24 by ghwa              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/17 15:45:04 by ghwa             ###   ########.fr       */
=======
/*   Updated: 2025/04/30 20:17:30 by ghwa             ###   ########.fr       */
>>>>>>> ca79ee258d2dd891180f8e709c686fc1226447ed
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <sstream>
#include <limits.h>


class ScalarConverter {
	public:
		static void convert(const std::string &literal);

	private:
		std::string value;

		ScalarConverter();
		ScalarConverter(const std::string &str);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static bool isChar(const std::string &literal);
		static bool isInt(const std::string &literal);
		static bool isFloat(const std::string &literal);
		static bool isDouble(const std::string &literal);
		static void print(char c, int i, float f, double d, bool validChar);
		static void printnan(const std::string &literal);
};

std::string intToString(int i);

#endif
