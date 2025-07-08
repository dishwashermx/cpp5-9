/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:14:43 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/08 14:17:06 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
	if (argc != 2)
		return std::cerr << "Usage: ./RPN [number] [number] [operator]" << std::endl, -1;
	RPN StackA;
	std::string string(argv[1]);
	StackA.calculate(string);
return 0;
}
