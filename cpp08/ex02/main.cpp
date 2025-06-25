/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:43:04 by ghwa              #+#    #+#             */
/*   Updated: 2025/06/23 09:45:53 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

//push is putting an element on top
//pop is removing the top element
//top is revealing the top element
//size returns number of element
//iterating now gives you the power to see each element

int main() {
	std::cout << "MutantStack Test:" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;  // should be 17

	mstack.pop();

	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	// Iteration
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "Iterating over MutantStack:" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	// Copy into a real std::stack
	std::stack<int> s(mstack);

	// Comparison with std::list
	std::cout << "\nstd::list comparison:" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	lst.pop_back();
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	while (lit != lite) {
		std::cout << *lit << std::endl;
		++lit;
	}

	return 0;
}
