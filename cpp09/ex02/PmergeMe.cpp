/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:25:48 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/10 16:54:26 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this;}

PmergeMe::~PmergeMe() {}

void PmergeMe::run(int argc, char** argv) {
	if (!validateInput(argc, argv))
		return ;
	std::vector<int> vec = parseInput(argc, argv);
	std::deque<int> deq(vec.begin(), vec.end());

	startClock(vec, "vector");
	startClock(deq, "deque");
}

bool PmergeMe::validateInput(int argc, char**argv) {
	std::set<int> set;
	if (argc < 2)
		return std::cerr << "Error: Not Enough Arguments" << std::endl, 0;
	for (int i = 1; i < argc; i++) {
		long val = atol(argv[i]);
		if (val > INT_MAX)
			return std::cerr << "Error: Argument too large" << std::endl, 0;

		if (set.count(val))
			return std::cerr << "Error: Non Unique Argument: " << argv[i] << std::endl, 0;
		set.insert(val);

		for (int j = 0; argv[i][j] != '\0'; j++) {
			if (isdigit(argv[i][j]) == 0)
				return std::cerr << "Error: Non Numeric Argument: " << argv[i] << std::endl, 0;
		}
	}
	return 1;
}

std::vector<int> PmergeMe::parseInput(int argc, char**argv) {
	std::vector<int> vec;

	for (int i = 1; i < argc; ++i) {
		int num = std::atoi(argv[i]);
		vec.push_back(num);
	}

	return vec;
}

template <typename T>
void PmergeMe::startClock(T container, std::string type) {
	if (type == "vector") {
		std::cout << "Before: ";
		for (size_t i = 0; i < container.size(); ++i)
			std::cout << container[i] << " ";
		std::cout << std::endl;
	}

	clock_t start = clock();
	clock_t end = clock();

	if (type == "vector") {
		std::cout << "After: ";
		for (size_t i = 0; i < container.size(); ++i)
			std::cout << container[i] << " ";
		std::cout << std::endl;
	}

	double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of " << container.size() \
	<< " with elements std::" << type << " : " << elapsed << " us" << std::endl;
}