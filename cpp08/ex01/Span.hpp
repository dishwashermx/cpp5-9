/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:10:24 by ghwa              #+#    #+#             */
/*   Updated: 2025/05/09 14:00:43 by ghwa             ###   ########.fr       */
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

class Span {
	private:
		std::vector<int> _data;
		std::vector<int> _rand;
		unsigned int _maxSize;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);
		// void populateVector(int size);
		// void addNumberS(std::vector<int> base, int pos1, int pos2);
		long shortestSpan();
		long longestSpan();
};


#endif
