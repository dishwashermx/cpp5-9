/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:57:53 by ghwa              #+#    #+#             */
/*   Updated: 2025/04/30 20:19:30 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>


int main(void) {
	::srand(static_cast<unsigned int>(std::clock()));
	Base base;
	Base* obj = base.generate();

	std::cout << "identify(Base*): ";
	base.identify(obj);

	std::cout << "identify(Base&): ";
	base.identify(*obj);

	return (0);
}