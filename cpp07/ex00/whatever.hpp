/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:10:24 by ghwa              #+#    #+#             */
/*   Updated: 2025/05/09 13:01:08 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
T max(T a, T b) {
	return (a > b) ? a : b;
}

template <typename T>
T min(T a, T b) {
	return (a < b) ? a : b;
}

template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

// class whatever {
// 	public:
// 		whatever();
// 		whatever(const whatever &other);
// 		whatever &operator=(const whatever &other);
// 		~whatever();

// 	private:
// 		std::string value;
// };


#endif
