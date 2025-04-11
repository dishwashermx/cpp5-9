/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:10:01 by ghwa              #+#    #+#             */
/*   Updated: 2025/04/11 14:49:53 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

whatever::whatever() : value("") {
	std::cout << "Default Constructor called." << std::endl;
}

whatever::whatever(const whatever &other) : value(other.value) {
	std::cout << "Copy Constructor called." << std::endl;
}

whatever& whatever::operator=(const whatever &other) {
	std::cout << "Copy Assignment Operator called." << std::endl;
	if (this == &other) {
		return *this;
	}
	value = other.value;
	return *this;
}

whatever::~whatever() {
	std::cout << "Destructor called" << std::endl;
}
