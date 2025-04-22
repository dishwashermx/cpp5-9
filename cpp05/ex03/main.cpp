/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:16:31 by ghwa              #+#    #+#             */
/*   Updated: 2025/04/22 11:51:47 by ghwa             ###   ########.fr       */
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
		AForm *b = z->makeForm("s", "Blender");
		Bureaucrat *a = new Bureaucrat("Emrpor", 1);

		if (b) {
			a->signForm(*b);
			a->executeForm(*b);
		}

		delete a;
		delete z;
	}

	catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	return 0;
}
