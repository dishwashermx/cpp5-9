/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:39:06 by ghwa              #+#    #+#             */
/*   Updated: 2025/05/06 11:13:38 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer() : value("") {
	std::cout << "Default Constructor called." << std::endl;
}

Serializer::Serializer(const std::string &str) : value(str) {
	std::cout << "Parameterized Constructor called." << std::endl;
}

Serializer::Serializer(const Serializer &other) : value(other.value) {
	std::cout << "Copy Constructor called." << std::endl;
}

Serializer& Serializer::operator=(const Serializer &other) {
	std::cout << "Copy Assignment Operator called." << std::endl;
	if (this == &other) {
		return *this;
	}
	value = other.value;
	return *this;
}

Serializer::~Serializer() {
	std::cout << "Destructor called" << std::endl;
}

unsigned long Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<unsigned long>(ptr));
}

Data* Serializer::deserialize(unsigned long raw) {
	return (reinterpret_cast<Data*>(raw));
}
