/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:27:53 by ghwa              #+#    #+#             */
/*   Updated: 2025/04/17 15:59:54 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define GREY    "\033[90m"


template <typename T>
void printElement(const T& elem) {
	std::cout << elem << " ";
}

void doubleInt(int& n) {
	n *= 2;
}

int main() {
	std::cout << CYAN << BOLD << "Test 1: print ints" << RESET << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	iter(intArray, 5, printElement<int>);
	std::cout << "\n" << std::endl;

	std::cout << CYAN << BOLD << "Test 2: double ints then print" << RESET << std::endl;
	iter(intArray, 5, doubleInt);
	iter(intArray, 5, printElement<int>);
	std::cout << "\n" << std::endl;

	std::cout << CYAN << BOLD << "Test 3: double print str" << RESET << std::endl;
	std::string strArray[] = {"hello", "world", "!"};
	::iter(strArray, 3, printElement<std::string>);
	std::cout << "\n" << std::endl;
}
