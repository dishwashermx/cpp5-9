/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:22:32 by ghwa              #+#    #+#             */
/*   Updated: 2024/11/28 12:16:44 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// --------------------------- Default Stuff ----------------------------

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Random Bureaucrat") {
	std::cout << "Robotomy Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Robotomy Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target){
	std::cout << "Robotomy Copy Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy Destructor called" << std::endl;
}

// --------------------------- Misc ----------------------------

void RobotomyRequestForm::beExecuted(Bureaucrat const &executor) const {
	srand(static_cast<unsigned int>(time(0)));
	int grade = getExecuteGrade();
	int drill = rand() % 2;

	if (executor.getGrade() > grade) {
		throw (GradeTooLowException());
		return ;
	}
	std::cout << "**brain drilling noise**" << std::endl;
	if (drill == 0)
		std::cout << executor.getName() << " has been successfully robotomized." << std::endl;
	else
		std::cout << executor.getName() << "'s robotomy has failed." << std::endl;
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& form) {
	out << form.getName() << form.getIfSigned()
		<< ", signable by grade " << form.getSignGrade()
		<< ", executable by grade " << form.getExecuteGrade() << ".";
	return out;
}

