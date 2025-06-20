/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:01:10 by ghwa              #+#    #+#             */
/*   Updated: 2025/06/20 14:57:14 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits.h>

Span::Span() : _maxSize(0) {
	std::cout << "Default Constructor called." << std::endl;
}

Span::Span(unsigned int N) : _maxSize(N) {
	std::cout << "Parameterized Constructor called." << std::endl;
}

Span::Span(const Span &other) : _data(other._data), _maxSize(other._maxSize) {
	std::cout << "Copy Constructor called." << std::endl;
}

Span& Span::operator=(const Span &other) {
	std::cout << "Copy Assignment Operator called." << std::endl;
	if (this != &other) {
		_data = other._data;
		_maxSize = other._maxSize;
	}
	return *this;
}

Span::~Span() {
	std::cout << "Destructor called" << std::endl;
}

void Span::addNumber(int number) {
	if (_data.size() >= _maxSize)
		throw std::overflow_error("Span is already full");
	_data.push_back(number);
}


long Span::shortestSpan() {
	if (_data.size() < 2)
		throw std::overflow_error("Not enough numbers to find a span");

	std::vector<int> temp = _data;
	std::sort(temp.begin(), temp.end());

	int difference = INT_MAX;
	for (size_t i = 1; i < temp.size(); ++i) {
		int diff = temp[i] - temp[i - 1];
		if (diff < difference)
			difference = diff;
	}
	return difference;
}


long Span::longestSpan() {
	if (_data.size() < 2)
		throw std::overflow_error("Not enough numbers to find a span");

	std::vector<int> temp = _data;
	std::sort(temp.begin(), temp.end());

	return static_cast<long>(temp.back() - temp.front());
}
