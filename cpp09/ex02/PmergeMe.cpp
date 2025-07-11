/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:25:48 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/11 22:52:45 by ghwa             ###   ########.fr       */
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
	for (int i = 1; i < argc; ++i) {
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
		std::cout << BLUE << "Before: ";
		for (size_t i = 0; i < container.size(); ++i)
			std::cout << container[i] << " ";
		std::cout << RESET << std::endl;
	}

	clock_t start = clock();
	mergeInsertSort(container, 1);
	clock_t end = clock();

	if (type == "vector") {
		std::cout << BLUE << "\nAfter: ";
		for (size_t i = 0; i < container.size(); ++i)
			std::cout << container[i] << " ";
		std::cout << RESET << std::endl;
	}

	double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	std::cout << std::fixed << std::setprecision(6);
	std::cout << BLUE << "\nTime to process a range of " << container.size() \
	<< " with elements std::" << type << " : " << elapsed << " us" << RESET << std::endl;
}

std::vector<int> PmergeMe::jacobsthalOrder(int n) {
	std::vector<int> jacobOrder;
	if (n <= 0)
		return jacobOrder;

	int j_prev = 0;
	int j_curr = 1;

	std::vector<bool> inserted(n, false);

	while (j_curr < n) {
	if (!inserted[j_curr]) {
		jacobOrder.push_back(j_curr);
		inserted[j_curr] = true;
		}
		int j_next = j_curr + 2 * j_prev;
		j_prev = j_curr;
		j_curr = j_next;
	}

	// add remaining losers in reverse order
	for (int i = n - 1; i >= 0; --i) {
		if (!inserted[i])
			jacobOrder.push_back(i);
	}

	return jacobOrder;
}


template <typename T>
void PmergeMe::mergeInsertSort(T& container, int recursionLevel) {
	size_t size = container.size();

	T winners;
	T losers;

	if (size <= 1) {
		std::cout << "\n[DEBUG] Recursion Unspooling" << std::endl;
		return;
	}

	std::cout << "\n[DEBUG] Recusion Level: " << recursionLevel << std::endl;

	for (size_t i = 1; i < size; i += 2) {
		int a = container[i - 1];
		int b = container[i];
		if (a > b) {
			winners.push_back(a);
			losers.push_back(b);
		} else {
			winners.push_back(b);
			losers.push_back(a);
		}
	}
	if (size % 2 != 0) {
		winners.push_back(container[size - 1]);
	}

	std::cout << "[DEBUG] Winners: ";
	for (size_t i = 0; i < winners.size(); ++i)
		std::cout << winners[i] << " ";
	std::cout << std::endl;
	std::cout << "[DEBUG] Losers: ";
	for (size_t i = 0; i < losers.size(); ++i)
		std::cout << losers[i] << " ";
	std::cout << std::endl;

	mergeInsertSort(winners, recursionLevel + 1);

	std::cout << "\n[DEBUG] Recusion Level: " << recursionLevel << std::endl;

	std::cout << "[DEBUG] Main: ";
	for (size_t i = 0; i < winners.size(); ++i)
		std::cout << winners[i] << " ";
	std::cout << std::endl;
	std::cout << "[DEBUG] Pend: ";
	for (size_t i = 0; i < losers.size(); ++i)
		std::cout << losers[i] << " ";
	std::cout << std::endl;

	std::cout << "\n[DEBUG] Jacobsthal Insertion Sequence: ";
	std::vector<int> jacobOrder = jacobsthalOrder(losers.size());
	for (size_t i = 0; i < jacobOrder.size(); ++i)
		std::cout << jacobOrder[i] << " ";
	std::cout << std::endl;

for (size_t i = 0; i < jacobOrder.size(); ++i) {
	int idx = jacobOrder[i];
	if (idx >= static_cast<int>(losers.size()))
		continue;

	int value = losers[idx];

	// Restrict search range to A[0 .. idx]
	typename T::iterator end = winners.begin() + std::min(static_cast<size_t>(idx + 1), winners.size());
	typename T::iterator pos = std::lower_bound(winners.begin(), end, value);

	std::cout << "[DEBUG] Inserting pend[" << idx << "] = " << value
				<< " into main[0.." << idx << "], at pos "
				<< std::distance(winners.begin(), pos) << std::endl;
	winners.insert(pos, value);
	std::cout << "[DEBUG] New Main: ";
	for (size_t i = 0; i < winners.size(); ++i)
		std::cout << winners[i] << " ";
	std::cout << std::endl;
}


	container = winners;
}