/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:13:11 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/04 17:28:02 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>

class RPN {
	public:
		RPN();
		RPN(const RPN &other);
		RPN& operator=(const RPN& other);
		~RPN();

	private:
		std::stack<int> _stack;
} ;
