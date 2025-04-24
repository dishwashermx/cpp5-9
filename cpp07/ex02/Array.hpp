/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:10:24 by ghwa              #+#    #+#             */
/*   Updated: 2025/04/24 14:05:27 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[36m"
#define GREY    "\033[90m"
#include <iostream>

template <typename T>
class Array {
	private:
		T* _data;
		unsigned int _size;

	public:
		Array() : _data(NULL), _size(0) {};
		Array(unsigned int n) : _data(new T[n]()), _size(n) {};
		Array(const Array &other) : _data(new T[other._size]()), _size(other._size) {
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = other._data[i];
		};
		Array &operator=(const Array &other) {
			if (this != &other) {
				delete[] _data;
				_size = other._size;
				_data = new T[_size]();
					for (unsigned int i = 0; i < _size; i++)
						_data[i] = other._data[i];
			}
			return (*this);
		};
		~Array() {
			delete[] _data;
		};
		T& operator[](unsigned int index) {
			if (index >= _size) {
				throw std::out_of_range("Index out of bounds!");
			}
			return _data[index];
		}
		unsigned int size() const {
			return (this->_size);
		}
};


#endif
