/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:12:07 by ghwa              #+#    #+#             */
/*   Updated: 2024/11/06 14:50:53 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// --------------------------- Default Stuff ----------------------------

Form::Form() : _name("Paper"), _signGrade(150), _executeGrade(150), _ifSigned(0) {
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const std::string name, const int signgrade, const int executegrade) : _name(name), _signGrade(signgrade), _executeGrade(executegrade), _ifSigned(0) {
	std::cout << "Form Constructor called" << std::endl;
	checkGrade(signgrade, executegrade);
}

Form::Form(const Form &other) : _name(other._name), _signGrade(other._signGrade), _executeGrade(other._executeGrade), _ifSigned(other._ifSigned) {
	std::cout << "Form Copy Constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form Destructor called" << std::endl;
}

// --------------------------- Getters ----------------------------

std::string Form::getName() const {
	return (this->_name);
}

int Form::getSignGrade() const {
	return (this->_signGrade);
}

int Form::getExecuteGrade() const {
	return (this->_executeGrade);
}

std::string Form::getIfSigned() const {
	if (_ifSigned == 0)
		return (" is not signed");
	else
		return (" is signed");
}

// --------------------------- Setters ----------------------------

void Form::checkGrade(int grade1, int grade2) {
	if (grade1 > 150 || grade2 > 150)
		throw Form::GradeTooLowException();
	else if (grade1 < 1 || grade2 < 1)
		throw Form::GradeTooHighException();
}

const char *Form::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
}

const char *Form::GradeTooHighException::what(void) const throw() {
	return ("Grade too high");
}

// --------------------------- Misc ----------------------------

std::ostream& operator<<(std::ostream& out, const Form& Form) {
	out << "Form " << Form.getName() << Form.getIfSigned() << ", signable by grade " << Form.getSignGrade() << ", executable by grade " << Form.getExecuteGrade() << ".";
	return (out);
}

void Form::beSigned(Bureaucrat& ref) {
	int grade = getSignGrade();

	if (ref.getGrade() > grade) {
		throw (GradeTooLowException());
		return ;
	}
	_ifSigned = true;
}

void Form::beExecuted(Bureaucrat& ref) {
	int grade = getExecuteGrade();

	if (ref.getGrade() > grade) {
		throw (GradeTooLowException());
		return ;
	}
}