/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:26:07 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/10 09:31:49 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		static void run(int argc, char** argv);

	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		static bool validateInput(int argc, char** argv);
		// static std::vector<int> parseInput(int argc, char** argv);
		// static void sortAndMeasure(std::vector<int> vec);
		// static void sortAndMeasure(std::deque<int> deq);
		// static std::vector<int> jacobsthalOrder(int n);

		// template<typename T>
		// 	static void mergeInsertSort(T& container, size_t left, size_t right);
} ;
