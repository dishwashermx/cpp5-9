/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 17:12:05 by ghwa              #+#    #+#             */
/*   Updated: 2025/04/17 10:41:56 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		const int _signGrade;
		const int _executeGrade;
		bool _ifSigned;
		void checkGrade(int grade1, int grade2);
	public:
		Form();
		Form(const std::string name, const int signgrade, const int executegrade);
		Form(const Form &other);
		~Form();

		std::string getName() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		std::string getIfSigned() const;
		void beSigned(Bureaucrat &ref);

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();};
} ;

std::ostream& operator<<(std::ostream& out, const Form& Form);

#endif