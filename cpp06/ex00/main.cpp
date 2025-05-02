/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:27:53 by ghwa              #+#    #+#             */
/*   Updated: 2025/04/30 20:17:18 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main() {
	// Test cases for different input literals
	std::cout << "Testing conversion for different literals:\n";

	// Test with a character literal
	std::cout << "\nInput: 'a'\n";
	ScalarConverter::convert("a");

	// Test with an integer literal
	std::cout << "\nInput: '42'\n";
	ScalarConverter::convert("42");

	// Test with a floating-point literal
	std::cout << "\nInput: '42.42f'\n";
	ScalarConverter::convert("42.42f");

	// Test with a double literal
	std::cout << "\nInput: '42.42'\n";
	ScalarConverter::convert("42.42");

	// Test with a string that is not convertible to a number (invalid case)
	std::cout << "\nInput: 'invalid123'\n";
	ScalarConverter::convert("invalid123");

	// Test with a special case (nan)
	std::cout << "\nInput: 'nan'\n";
	ScalarConverter::convert("nan");

	// Test with a special case (infinity)
	std::cout << "\nInput: 'inf'\n";
	ScalarConverter::convert("inf");

	// Test with a negative floating-point literal
	std::cout << "\nInput: '-42.42'\n";
	ScalarConverter::convert("-42.42");


	return 0;
}

