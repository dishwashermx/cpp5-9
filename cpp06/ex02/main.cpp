/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:57:53 by ghwa              #+#    #+#             */
/*   Updated: 2025/04/11 10:35:28 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void) {
	srand(time(0));
	Base base;
	Base* obj = base.generate();

	std::cout << "identify(Base*): ";
	base.identify(obj);

	std::cout << "identify(Base&): ";
	base.identify(*obj);

	return (0);
}