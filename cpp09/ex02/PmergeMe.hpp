/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:26:07 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/12 14:17:49 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <string>

#define BLUE    "\033[34m"
#define RESET   "\033[0m"
#define DEBUG_MODE false

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

		static std::vector<int> jacobsthalOrder(int n);

		template<typename T>
			static void startClock(T container, std::string type);

		template<typename T>
			static void mergeInsertSort(T& container, int recursionLevel);
} ;
