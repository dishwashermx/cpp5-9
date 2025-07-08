/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:13:11 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/08 13:25:51 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <string>

class RPN {
	public:
		RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN& other);
		~RPN();

		void calculate(std::string input);

	private:
		std::stack<int> _stack;
} ;
