/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:12:05 by ghwa              #+#    #+#             */
/*   Updated: 2024/11/07 17:20:36 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		void setGrade(int newGrade);
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &ref);
		void executeForm(AForm const &ref);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();};
} ;

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif