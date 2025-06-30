/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:20:56 by ghwa              #+#    #+#             */
/*   Updated: 2025/06/30 15:00:23 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

BitcoinExchange::BitcoinExchange() {
	std::cout << "Default Constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string filename) {
	std::cout << "Parameterized Constructor" << std::endl;

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

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	std::cout << "Copy Constructor" << std::endl;
	*this = other;
}


BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	std::cout << "Copy Assignment Operator" << std::endl;
	if (this == &other)
		return (*this);
	this->dataFileAddress = other.dataFileAddress;
	this->btcData = other.btcData;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "Destructor" << std::endl;
}

void BitcoinExchange::processInput(std::string filename) {
	this->inputFileAddress = filename;
	std::ifstream inputFile(this->inputFileAddress.c_str());
	if (!inputFile.is_open())
		throw std::runtime_error("Error: could not open database file.");
}