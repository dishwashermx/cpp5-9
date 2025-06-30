/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:12:27 by ghwa              #+#    #+#             */
/*   Updated: 2025/06/30 12:07:49 by ghwa             ###   ########.fr       */
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
		argv[1] = '\0';
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << '\n';
	}
	return (0);
}