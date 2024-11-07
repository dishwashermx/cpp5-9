/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:16:31 by ghwa              #+#    #+#             */
/*   Updated: 2024/11/07 16:57:51 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main (void) {
try {
        Bureaucrat bob("Bob", 100);
		AForm plastic("plastic", 100, 100);
		AForm metal("metal", 1, 1);

        std::cout << bob << std::endl;
		std::cout << plastic << std::endl;
		std::cout << metal << std::endl;

		bob.signForm(plastic);
		std::cout << plastic << std::endl;
		bob.signForm(metal);
		std::cout << metal << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}