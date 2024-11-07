/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:16:31 by ghwa              #+#    #+#             */
/*   Updated: 2024/11/06 15:11:02 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main (void) {
try {
        Bureaucrat bob("Bob", 150);
        Bureaucrat alice("Alice", 1);
		Bureaucrat jane(alice);

        // Print using the overloaded << operator
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

		bob = alice;
		jane.decrementGrade();
		std::cout << jane << std::endl;

        alice.incrementGrade();  // Should throw GradeTooHighException
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}