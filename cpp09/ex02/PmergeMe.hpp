/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:26:07 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/09 15:40:59 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>

template <typename T>
class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		static std::vector<int> sortVector(const std::vector<int>& input);
		static std::deque<int> sortDeque(const std::deque<int>& input);

	private:
		template <typename Container>
		static Container fordJohnson(const Container& input) {
			Container sorted;
			return sorted;
		}
		static std::vector<int> jacobsthalOrder(int n);
} ;
