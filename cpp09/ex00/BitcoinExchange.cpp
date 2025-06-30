/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:20:56 by ghwa              #+#    #+#             */
/*   Updated: 2025/06/30 12:23:28 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

BitcoinExchange::BitcoinExchange(std::string filename) {
	std::cout << "Parsing Data File" << std::endl;

	this->dataFileAddress = filename;
	std::ifstream dataFile(this->dataFileAddress.c_str());
	if (!dataFile.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	std::getline(dataFile, line); // skipping header line

	while (std::getline(dataFile, line)) {
			std::istringstream iss(line);
			std::string date, valueStr;
			if (!std::getline(iss, date, ',') || !std::getline(iss, valueStr)) {
				std::cerr << "Warning: skipping invalid line in database: " << line << std::endl;
				continue;
			}
			std::stringstream valStream(valueStr);
			float value;
			valStream >> value;
			btcData[date] = value;
		}
	dataFile.close();
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "Destructor" << std::endl;
}
