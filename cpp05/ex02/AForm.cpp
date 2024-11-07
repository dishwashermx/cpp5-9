/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:12:07 by ghwa              #+#    #+#             */
/*   Updated: 2024/11/06 14:50:53 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// --------------------------- Default Stuff ----------------------------

AForm::AForm() : _name("Paper"), _signGrade(150), _executeGrade(150), _ifSigned(0) {
	std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int signgrade, const int executegrade) : _name(name), _signGrade(signgrade), _executeGrade(executegrade), _ifSigned(0) {
	std::cout << "AForm Constructor called" << std::endl;
	checkGrade(signgrade, executegrade);
}

AForm::AForm(const AForm &other) : _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade), _ifSigned(other._ifSigned) {
	std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm Destructor called" << std::endl;
}

// --------------------------- Getters ----------------------------

std::string AForm::getName() const {
	return (this->_name);
}

int AForm::getSignGrade() const {
	return (this->_signGrade);
}

int AForm::getExecuteGrade() const {
	return (this->_executeGrade);
}

std::string AForm::getIfSigned() const {
	if (_ifSigned == 0)
		return (" is not signed");
	else
		return (" is signed");
}

// --------------------------- Setters ----------------------------

void AForm::checkGrade(int grade1, int grade2) {
	if (grade1 > 150 || grade2 > 150)
		throw AForm::GradeTooLowException();
	else if (grade1 < 1 || grade2 < 1)
		throw AForm::GradeTooHighException();
}

const char *AForm::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
}

const char *AForm::GradeTooHighException::what(void) const throw() {
	return ("Grade too high");
}

// --------------------------- Misc ----------------------------

std::ostream& operator<<(std::ostream& out, const AForm& AForm) {
	out << "AForm " << AForm.getName() << AForm.getIfSigned() << ", signable by grade " << AForm.getSignGrade() << ", executable by grade " << AForm.getExecuteGrade() << ".";
	return (out);
}

void AForm::beSigned(Bureaucrat &ref) {
	int grade = getSignGrade();

	if (ref.getGrade() > grade) {
		throw (GradeTooLowException());
		return ;
	}
	_ifSigned = true;
}

void AForm::beExecuted(Bureaucrat &ref) const {
	int grade = getExecuteGrade();

	if (ref.getGrade() > grade) {
		throw (GradeTooLowException());
		return ;
	}
}