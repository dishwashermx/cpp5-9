/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:25:48 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/10 09:46:24 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::run(int argc, char** argv) {
	if (!validateInput(argc, argv))
		return ;
	// _vector = parseInput(argc, argv);
	// _deque(vec.begin(), vec.end());

	// sortAndMeasure(_vector);
	// sortAndMeasure(_deque);
}

bool PmergeMe::validateInput(int argc, char**argv) {
	if (argc < 2)
		return std::cerr << "Not Enough Arguments" << std::endl, 0;
	for (int i = 0; i < argc; i++) {
		
	}
	return 1;
}
