/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:01:10 by ghwa              #+#    #+#             */
/*   Updated: 2025/04/29 17:44:56 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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

int Span::shortestSpan() {
	if (_data.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
}

int Span::longestSpan() {
	if (_data.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
}