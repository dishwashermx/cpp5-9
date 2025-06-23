/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:10:24 by ghwa              #+#    #+#             */
/*   Updated: 2025/06/23 10:03:59 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
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
		const T& operator[](unsigned int index) {
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
