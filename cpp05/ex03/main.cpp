/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:16:31 by ghwa              #+#    #+#             */
/*   Updated: 2024/11/28 12:16:26 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	try {
		Bureaucrat tommy("Tommy", 19);
		ShrubberyCreationForm form1("bub");
		RobotomyRequestForm form2("bib");
		PresidentialPardonForm form3("bob");

		std::cout << tommy << std::endl;
		std::cout << form1 << std::endl;

		std::cout << "Trying to sign the form...\n";
		tommy.signForm(form1);
		std::cout << "Trying to execute the form...\n";
		tommy.executeForm(form1);
		std::cout << form1 << std::endl;

		std::cout << form2 << std::endl;
		std::cout << "Trying to sign the form...\n";
		tommy.signForm(form2);
		std::cout << "Trying to execute the form...\n";
		tommy.executeForm(form2);
		std::cout << form2 << std::endl;

		std::cout << form3 << std::endl;
		std::cout << "Trying to sign the form...\n";
		tommy.signForm(form3);
		std::cout << "Trying to execute the form...\n";
		tommy.executeForm(form3);
		std::cout << form3 << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	return 0;
}
