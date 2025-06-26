/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:12:27 by ghwa              #+#    #+#             */
/*   Updated: 2025/06/26 13:36:45 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <exception>
#include <fstream>

int main(int argc, char** argv) {
	try {
		if (argc != 2) {
			throw Bit::InputException();
		}
		std::ifstream inputFile(argv[1]);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	return (0);
}