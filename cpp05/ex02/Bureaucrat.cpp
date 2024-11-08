/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:12:07 by ghwa              #+#    #+#             */
/*   Updated: 2024/11/08 13:47:34 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// --------------------------- Default Stuff ----------------------------

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	std::cout << "Bureaucrat Constructor called" << std::endl;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat Copy Constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat Copy Assignment called" << std::endl;
	if (this != &other) {
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

// --------------------------- Getters ----------------------------

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

// --------------------------- Setters ----------------------------

void Bureaucrat::incrementGrade() {
	setGrade(this->getGrade() - 1);
}

void Bureaucrat::decrementGrade() {
	setGrade(this->getGrade() + 1);
}

// --------------------------- Exceptions ----------------------------

void Bureaucrat::setGrade(int newGrade) {
	if (newGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (newGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = newGrade;
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Grade too high");
}

// --------------------------- Misc ----------------------------

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << " is a bureaucrat, grade " << bureaucrat.getGrade() << ".";
	return (out);
}

void Bureaucrat::signForm(AForm &ref) {
	try {
		ref.beSigned(*this);
		std::cout << this->getName() << " signed " << ref.getName() << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << ref.getName() << " because " << e.what() << std::endl;
		throw;
	}
}

void Bureaucrat::executeForm(AForm const &ref) {
	try {
		ref.beExecuted(*this);
		std::cout << this->getName() << " executed " << ref.getName() << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << this->getName() << " couldn't execute " << ref.getName() << " because " << e.what() << std::endl;
		throw;
	}
}