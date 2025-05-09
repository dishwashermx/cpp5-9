/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:07:46 by ghwa              #+#    #+#             */
/*   Updated: 2025/05/09 14:00:52 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main() {
	try {
		std::cout << CYAN << BOLD << "Tests for Constructors" << RESET << std::endl;
		Span a;
		Span b(5);
		Span c(b);
		a = b;
		std::cout << CYAN << BOLD << "\nTests for addNumber" << RESET << std::endl;
		a.addNumber(10000);
		a.addNumber(9999);
		a.addNumber(-300);
		a.addNumber(2);
		Span d;
		std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "Longest span: " << a.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	return 0;
}
