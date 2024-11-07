/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:50:34 by ghwa              #+#    #+#             */
/*   Updated: 2024/11/07 16:03:14 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


// --------------------------- Default Stuff ----------------------------

ShrubberyCreationForm::ShrubberyCreationForm() : _target("Default"), _signGrade(145), _executeGrade(137), _ifSigned(0) {
	std::cout << "Shrubbery Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name, const int signgrade, const int executegrade) : _name(name), _signGrade(signgrade), _executeGrade(executegrade), _ifSigned(0) {
	std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
	checkGrade(signgrade, executegrade);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : _target(other._target), _signGrade(other._signGrade), _executeGrade(other._executeGrade), _ifSigned(other._ifSigned) {
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}
