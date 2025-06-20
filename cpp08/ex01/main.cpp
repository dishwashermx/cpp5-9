/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:58:19 by ghwa              #+#    #+#             */
/*   Updated: 2025/06/20 15:06:43 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

int main() {
	try {
		std::cout << CYAN << BOLD << "Test 1: Add numbers manually" << RESET << std::endl;
		Span sp1(5);
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp1.longestSpan() << std::endl;

		std::cout << CYAN << BOLD << "\nTest 2: Add range using vector" << RESET << std::endl;
		std::vector<int> vec;
		for (int i = 0; i < 10000; ++i)
			vec.push_back(rand() % 100000);
		Span sp2(10000);
		sp2.addNumber(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

		std::cout << CYAN << BOLD << "\nTest 3: Add range using list" << RESET << std::endl;
		std::list<int> lst;
		lst.push_back(50);
		lst.push_back(20);
		lst.push_back(70);
		lst.push_back(40);
		Span sp3(10);
		sp3.addNumber(lst.begin(), lst.end());
		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp3.longestSpan() << std::endl;


		std::cout << CYAN << BOLD << "\nTest 4: Trigger overflow exception" << RESET << std::endl;
		Span sp4(2);
		sp4.addNumber(1);
		sp4.addNumber(2);
		sp4.addNumber(3); // This should throw
	} catch (const std::exception& e) {
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << CYAN << BOLD << "\nTest 5: Span on empty container" << RESET << std::endl;
		Span sp5(5);
		std::cout << sp5.shortestSpan() << std::endl; // This should throw
	} catch (const std::exception& e) {
		std::cerr << BOLD << "Exception caught: " << e.what() << RESET << std::endl;
	}

	return 0;
}
