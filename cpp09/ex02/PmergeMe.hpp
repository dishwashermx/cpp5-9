/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:26:07 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/10 18:24:12 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		static void run(int argc, char** argv);

	private:

		static bool validateInput(int argc, char** argv);
		static std::vector<int> parseInput(int argc, char** argv);

		template<typename T>
			static void startClock(T container, std::string type);

		template<typename T>
			static void mergeInsertSort(T& container);

		// template<typename T>
		// 	static void weirdInsertSort(T& container, size_t left, size_t right);

		// static std::vector<int> jacobsthalOrder(int n);
} ;
