/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:20:56 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/03 17:46:02 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <map>
#include <cstdlib>

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

	std::string line;
	std::getline(inputFile, line); // skipping header line

	while (std::getline(inputFile, line)) {
		std::string date, value;
		if (!splitInputLine(line, date, value)) {
			std::cerr << "Error: bad format input => " << line << std::endl;
			// continue;
		}
		if (!isValidDate(date)) {
			std::cerr << "Error: bad date input => " << line << std::endl;
			// continue;
		}
		// if (!validValue(value)) {
		// 	std::cerr << "Error: bad value input." << std::endl;
		// 	continue;
		// }
		// printLine(line);
		std::cout << "[DEBUG]" << " \"" << date << "\" | \"" << value << "\"" << std::endl;
	}
	inputFile.close();
}

bool BitcoinExchange::splitInputLine(const std::string& line, std::string& date, std::string& value) {
	size_t sep = line.find(" | ");
	if (sep == std::string::npos)
	return false;

	size_t start = line.find_first_not_of(" \t\r\n", 0);
	size_t end = line.find_last_not_of(" \t\r\n", sep - 1);
	date = (start == std::string::npos || end == std::string::npos) ? "" : line.substr(start, end - start + 1);

	start = line.find_first_not_of(" \t\r\n", sep + 3);
	end = line.find_last_not_of(" \t\r\n");
	value = (start == std::string::npos || end == std::string::npos) ? "" : line.substr(start, end - start + 1);

	if (date.empty() || value.empty())
		return false;

	return true;
}

bool BitcoinExchange::isValidDate(std::string date) {
	if (date.length() != 10) return false;
	for (int i = 0; i < 10; ++i) {
		if (i == 4 || i == 7) {
			if (date[i] != '-') return false;
		} else {
			if (date[i] < '0' || date[i] > '9') return false;
		}
	}

	int year, month, day;
	bool leapyear;
	year = atoi(date.substr(0, 3).c_str());
	month = atoi(date.substr(5, 6).c_str());
	day = atoi(date.substr(9, 10).c_str());

	leapyear = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	if (month < 0 || month > 12) return false;
	return true;
}

float BitcoinExchange::getRate(const std::string& date, std::map<std::string, float>& btcData) {
	std::map<std::string, float>::const_iterator it = btcData.find(date);
	if (it != btcData.end()) {
		return it->second;
	}

	it = btcData.lower_bound(date);
	if (it == btcData.begin())
		return (-1);
	if (it == btcData.end() || it->first != date)
		--it;
	return it->second;
}