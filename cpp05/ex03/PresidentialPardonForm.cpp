/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:22:32 by ghwa              #+#    #+#             */
/*   Updated: 2024/11/28 09:54:31 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// --------------------------- Default Stuff ----------------------------

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Random Bureaucrat") {
	std::cout << "Robotomy Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "Robotomy Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target){
	std::cout << "Robotomy Copy Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Robotomy Destructor called" << std::endl;
}

// --------------------------- Misc ----------------------------

void PresidentialPardonForm::beExecuted(Bureaucrat const &executor) const {
	int grade = getExecuteGrade();

	if (executor.getGrade() > grade) {
		throw (GradeTooLowException());
		return ;
	}
	else
		std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return;
}

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& form) {
    out << form.getName() << form.getIfSigned()
        << ", signable by grade " << form.getSignGrade()
        << ", executable by grade " << form.getExecuteGrade() << ".";
    return out;
}

