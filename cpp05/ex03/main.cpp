/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:16:31 by ghwa              #+#    #+#             */
/*   Updated: 2025/01/09 09:54:54 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	try {
		Intern *z = new Intern();
		AForm *b = z->makeForm("RobotomyRequestForm", "Blender");
		Bureaucrat *a = new Bureaucrat("Emrpor", 1);

		a->signForm(*b);
		a->executeForm(*b);
	}
	catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	return 0;
}
