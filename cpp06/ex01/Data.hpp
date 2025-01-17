/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:47:28 by ghwa              #+#    #+#             */
/*   Updated: 2025/01/17 15:47:44 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
	private:
		Data();
		Data(const std string &str);
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data();

		std::string value;
};

#endif