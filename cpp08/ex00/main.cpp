/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:27:53 by ghwa              #+#    #+#             */
/*   Updated: 2025/04/29 10:23:38 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <set>

int main() {
	try {
		std::cout << CYAN << BOLD << "Testing Vector" << RESET << std::endl;
		std::vector<int> v;
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);

		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << CYAN << BOLD << "\nTesting List" << RESET << std::endl;
		std::list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);

		std::list<int>::iterator it = easyfind(l, 4); // Should throw
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << CYAN << BOLD << "\nTesting Deque" << RESET << std::endl;
		std::deque<int> d;
		d.push_back(5);
		d.push_back(15);
		d.push_back(25);

		std::deque<int>::iterator it = easyfind(d, 15);
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << CYAN << BOLD << "\nTesting Set" << RESET << std::endl;
		std::set<int> s;
		s.insert(100);
		s.insert(200);
		s.insert(300);

		std::set<int>::iterator it = easyfind(s, 250); // Should throw
		std::cout << "Found: " << *it << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
