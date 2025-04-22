/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:45:04 by ghwa              #+#    #+#             */
/*   Updated: 2025/04/17 10:44:08 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// --------------------------- Default Stuff ----------------------------

Intern::Intern() {
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
	std::cout << "Intern Copy Constructor called" << std::endl;
	*this = other;
}

Intern::~Intern() {
	std::cout << "Intern Destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other) {
	std::cout << "Intern Copy Assignement Operator called" << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}

static AForm	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string form_to_create, const std::string target_for_form)
{
	AForm *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (form_to_create == forms[i])
		{
			std::cout << "Intern creates " << form_to_create << std::endl;
			return (all_forms[i](target_for_form));
		}
	}

	std::cout << "Intern can not create a form called " << form_to_create << std::endl;
	return (NULL);
}