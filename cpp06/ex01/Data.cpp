/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:39:06 by ghwa              #+#    #+#             */
/*   Updated: 2025/01/17 15:48:04 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"


Data::Data() : value("") {
	std::cout << "Default Constructor called." << std::endl;
}

Data::Data(const std::string &str) : value(str) {
	std::cout << "Parameterized Constructor called." << std::endl;
}

Data::Data(const Data &other) : value(other.value) {
	std::cout << "Copy Constructor called." << std::endl;
}

Data& Data::operator=(const Data &other) {
	std::cout << "Copy Assignment Operator called." << std::endl;
	if (this == &other) {
		return *this;
	}
	value = other.value;
	return *this;
}

Data::~Data() {
	std::cout << "Destructor called" << std::endl;
}