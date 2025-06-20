/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:10:24 by ghwa              #+#    #+#             */
/*   Updated: 2025/06/20 15:04:46 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define GREY    "\033[90m"
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span {
	private:
		std::vector<int> _data;
		unsigned int _maxSize;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);

		template <typename Iterator>
		void addNumber(Iterator begin, Iterator end) {
			if (std::distance(begin, end) + _data.size() > _maxSize)
				throw std::overflow_error("Not enough space in Span to add the range");
			_data.insert(_data.end(), begin, end);
		}
		
		long shortestSpan();
		long longestSpan();
};


#endif
