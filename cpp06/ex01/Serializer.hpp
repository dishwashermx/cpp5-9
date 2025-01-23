/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:39:03 by ghwa              #+#    #+#             */
/*   Updated: 2025/01/23 14:21:53 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>
#include "Data.hpp"

class Serializer {
	private:
		Serializer();
		Serializer(const std::string &str);
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();

		std::string value;
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
