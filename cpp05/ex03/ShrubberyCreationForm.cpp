/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:22:56 by ghwa              #+#    #+#             */
/*   Updated: 2024/11/28 09:23:48 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// --------------------------- Default Stuff ----------------------------

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Random Bureaucrat") {
	std::cout << "Shrubbery Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "Shrubbery Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target){
	std::cout << "Shrubbery Copy Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery Destructor called" << std::endl;
}

// --------------------------- Misc ----------------------------

void ShrubberyCreationForm::beExecuted(Bureaucrat const &executor) const {
	int grade = getExecuteGrade();

	if (executor.getGrade() > grade) {
		throw (GradeTooLowException());
		return ;
	}
	std::ofstream outFile((_target + "_shrubbery").c_str());

	if (!outFile.is_open()) {
		std::cerr << "Error opening file" << std::endl;
		return;
	}
 	outFile << generateTree();
	outFile.close();
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form) {
    out << form.getName() << form.getIfSigned()
        << ", signable by grade " << form.getSignGrade()
        << ", executable by grade " << form.getExecuteGrade() << ".";
    return out;
}


std::string ShrubberyCreationForm::generateTree() const {
    return
        "                     ccee88oo\n"
        "                  C8O8O8Q8PoOb o8oo\n"
        "               dOB69QO8PdUOpugoO9bD\n"
        "              CgggbU8OU qOp qOdoUOdcb\n"
        "                 6OuU  /p u gcoUodpP\n"
        "                   \\\\//  /douUP\n"
        "                     ||||| \n"
        "                     |||||\n"
        "                     |||||\n"
        "           , -=-~  .-^- _\n";
}
