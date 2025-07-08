/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:20:56 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/04 17:12:02 by ghwa             ###   ########.fr       */
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
#include <iomanip>

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
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	std::getline(inputFile, line); // skipping header line

	while (std::getline(inputFile, line)) {
		std::string date, value;
		if (!splitInputLine(line, date, value)) {
			std::cerr << "Error: bad format input => \"" << line << "\"" << std::endl;
			continue;
		}
		if (!isValidDate(date)) {
			std::cerr << "Error: bad date input => \"" << line << "\"" << std::endl;
			continue;
		}
		if (!isValidValue(value)) {
			std::cerr << "Error: bad value input => \"" << line << "\"" << std::endl;
			continue;
		}

		std::istringstream iss(value);
		float fvalue = 0.0f;
		iss >> fvalue;

		float result = getRate(date, fvalue);
		if (result < 0)
			std::cerr << "Error: date out of range => \"" << line << " \"" << std::endl;
		else
			std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << result << std::endl;
		// std::cout << "[DEBUG]" << " \"" << date << "\" | \"" << value << "\"" << std::endl;
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

bool BitcoinExchange::isValidDate(const std::string dateStr) {
	if (dateStr.length() != 10)
		return false;
	for (int i = 0; i < 10; ++i) {
		if (i == 4 || i == 7) {
			if (dateStr[i] != '-') return false;
		} else {
			if (dateStr[i] < '0' || dateStr[i] > '9') return false;
		}
	}

	int year, month, day;
	year = atoi(dateStr.substr(0, 4).c_str());
	month = atoi(dateStr.substr(5, 7).c_str());
	day = atoi(dateStr.substr(8, 10).c_str());

	// std::cout << "[DEBUG] \"" << year << "\" \"" << month << "\" \"" << day << "\"" << std::endl;
	if (month < 0 || month > 12) return false;
	if (day < 1 || day > getDaysInMonth(year, month)) return false;
	return true;
}

int BitcoinExchange::getDaysInMonth(int year, int month) {
	bool leapyear = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	static const int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	// std::cout << "[DEBUG] " << daysInMonth[month - 1] << std::endl;
	if (month == 2 && leapyear) return 29;
	return daysInMonth[month - 1];
}

bool BitcoinExchange::isValidValue(const std::string& valueStr) {
	std::istringstream iss(valueStr);
	double value = 0.0;

	iss >> value;

	// Conversion failed or there's leftover junk values
	if (iss.fail() || !iss.eof())
		return false;

	if (value < 0.0)
		return false;

	if (value > 1000.0)
		return false;

	return true;
}

float BitcoinExchange::getRate(const std::string& date, float value) {
	std::map<std::string, float>::const_iterator it = btcData.find(date);
	if (it != btcData.end()) {
		return value * it->second;
	}

	it = btcData.lower_bound(date);

	if (it == btcData.begin() && it->first > date)
		return -1.0f;

	if (it == btcData.end() || it->first != date)
		--it;

	return value * it->second;
}
