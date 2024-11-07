/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:12:05 by ghwa              #+#    #+#             */
/*   Updated: 2024/11/07 17:21:56 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
	protected:
		const std::string _name;
		const int _signGrade;
		const int _executeGrade;
		bool _ifSigned;
		void checkGrade(int grade1, int grade2);
	public:
		AForm();
		AForm(const std::string name, const int signgrade, const int executegrade);
		AForm(const AForm &other);
		~AForm();

		std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		std::string getIfSigned() const;
		void beSigned(Bureaucrat &ref);
		virtual void beExecuted(Bureaucrat &ref) const = 0;

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();};
} ;

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif