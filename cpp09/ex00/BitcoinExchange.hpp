/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:20:56 by ghwa              #+#    #+#             */
/*   Updated: 2025/06/30 14:59:15 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <string>
#include <map>

class BitcoinExchange {
	private:
		std::string dataFileAddress;
		std::string inputFileAddress;
		std::map<std::string, float> btcData;

	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange& operator= (const BitcoinExchange& other);
		~BitcoinExchange();

		void processInput(std::string filename);
} ;

