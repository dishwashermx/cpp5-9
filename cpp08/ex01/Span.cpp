/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:01:10 by ghwa              #+#    #+#             */
/*   Updated: 2025/05/07 15:16:10 by ghwa             ###   ########.fr       */
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
		throw std::logic_error("Not enough numbers to find a span");
	int difference = INT_MAX;
	std::sort(_data.begin(), _data.end());
	std::vector<int>::iterator it = unique(_data.begin(), _data.end());
	_data.erase(it, _data.end());
	std::vector<int>::const_iterator elem1 = _data.begin();
	std::vector<int>::const_iterator elem2 = ++_data.begin();
	for (; elem2 != _data.end(); elem1++, elem2++) {
		long long1 = *elem1;
		long long2 = *elem2;
		long minus = std::abs(long2 - long1);
		if (minus < difference)
			difference = minus;
	}
	return (difference);
}

long Span::longestSpan() {
	if (_data.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	int difference = INT_MAX;
	std::sort(_data.begin(), _data.end());
	std::vector<int>::iterator it = unique(_data.begin(), _data.end());
	_data.erase(it, _data.end());
	return (std::abs(*(_data.end()) - *(_data.begin())));
}