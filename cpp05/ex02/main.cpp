/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:16:31 by ghwa              #+#    #+#             */
/*   Updated: 2024/11/08 14:10:38 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
    try {
        Bureaucrat Tommy("Tommy", 10); // Tommy has the lowest possible grade
        ShrubberyCreationForm Form1("LAckey");

        std::cout << Tommy << std::endl;
        std::cout << Form1 << std::endl;

        std::cout << "Trying to sign the form...\n";
        Tommy.signForm(Form1);  // Expecting an exception if Tommy's grade is too low

        std::cout << "Trying to execute the form...\n";
        Tommy.executeForm(Form1);  // Expecting an exception if Tommy's grade is too low

        std::cout << Form1 << std::endl;  // This line won't be reached if exceptions are thrown
    }
    catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
