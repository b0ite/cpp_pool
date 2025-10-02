/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:29:57 by igilbert          #+#    #+#             */
/*   Updated: 2025/07/21 09:13:54 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (++i < argc)
	{
		std::string str(argv[i]);
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
