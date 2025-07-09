/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghwa <ghwa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:25:32 by ghwa              #+#    #+#             */
/*   Updated: 2025/07/09 14:52:03 by ghwa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(int argc, char** argv) {
	if (argc < 2 || !argv)
		return std::cerr << "Error: No Arguments" << std::endl, -1;
	return 0;
}