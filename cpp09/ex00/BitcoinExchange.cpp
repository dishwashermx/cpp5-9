/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:20:56 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/03 13:54:38 by ghwa             ###   ########.fr       */
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

float BitcoinExchange::getRate(const std::string& date, std::map<std::string, float>& btcData) {
	std::map<std::string, float>::const_iterator it = btcData.find(date);
	if (it != btcData.end()) {
		return it->second;
	}

	it = btcData.lower_bound(date);
	if (it == btcData.begin())
		throw std::runtime_error("No earlier data available.");
	if (it == btcData.end() || it->first != date)
		--it;
	return it->second;
}
