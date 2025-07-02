/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:12:27 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/02 13:16:40 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <exception>
#include <fstream>

int main(int argc, char** argv) {
	try {
		if (argc != 2) {
			std::cerr << "Usage: ./btc <input_file>" << std::endl;
			return 1;
		}

		BitcoinExchange Bit("data.csv");
		Bit.processInput(argv[1]);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}