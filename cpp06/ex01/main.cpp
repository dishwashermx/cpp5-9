/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:38:17 by ghwa              #+#    #+#             */
/*   Updated: 2025/01/23 14:21:05 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
	Data data;
	data.id = 1001;
	data.name = "OG";
	std::cout << "Original Data Address: " << &data << std::endl;
	std::cout << "ID: " << data.id << ", Name: " << data.name << std::endl;

	unsigned long pointer = Serializer::serialize(&data);
	std::cout << std::endl << "Serialized Data: " << pointer << std::endl;

	Data* unpointer = Serializer::deserialize(pointer);
	std::cout << std::endl << "De-serialized Serialized Data Address: " << unpointer << std::endl;

	std::cout << std::endl << "Serialisation and De-serialisation ";
	if (&data == unpointer)
		std::cout << "was successful!" << std::endl;
	else
		std::cout << "was unsuccessful :(" << std::endl;
	return (0);
}
