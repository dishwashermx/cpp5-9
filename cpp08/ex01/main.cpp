/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:07:46 by ghwa              #+#    #+#             */
/*   Updated: 2025/05/07 15:17:36 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main() {
	try {
		std::cout << CYAN << BOLD << "Tests for Constructors" << RESET << std::endl;
		Span a;
		Span b(2);
		Span c(b);
		a = b;
		std::cout << CYAN << BOLD << "\nTests for addNumber" << RESET << std::endl;
		a.addNumber(6);
		a.addNumber(3);
		a.addNumber(2);
		Span d;
		std::cout << "Shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "Longest span: " << a.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	return 0;
}
