/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:27:53 by ghwa              #+#    #+#             */
/*   Updated: 2025/04/24 13:59:53 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
	try {
		std::cout << BOLD << CYAN << "[Empty array test]" << RESET << std::endl;
		Array<int> empty;
		std::cout << "Size: " << empty.size() << std::endl;

		std::cout << BOLD << CYAN << "\n[Array with 5 ints]" << RESET << std::endl;
		Array<int> nums(5);
		for (unsigned int i = 0; i < nums.size(); i++)
			nums[i] = i * 10;

		for (unsigned int i = 0; i < nums.size(); i++)
			std::cout << "nums[" << i << "] = " << nums[i] << std::endl;

		std::cout << BOLD << CYAN << "\n[Copy constructor test]" << RESET << std::endl;
		Array<int> copy(nums);
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << "copy[" << i << "] = " << copy[i] << std::endl;

		std::cout << BOLD << CYAN << "\n[Assignment operator test]" << RESET << std::endl;
		Array<int> assigned;
		assigned = nums;
		for (unsigned int i = 0; i < assigned.size(); i++)
			std::cout << "assigned[" << i << "] = " << assigned[i] << std::endl;

		std::cout << BOLD << CYAN << "\n[Out of bounds test]" << RESET << std::endl;
		std::cout << assigned[6] << std::endl; // should throw
	}
	catch (const std::exception &e) {
		std::cerr << GREY << "Caught exception: " << e.what() << RESET << std::endl;
	}

	return 0;
}

