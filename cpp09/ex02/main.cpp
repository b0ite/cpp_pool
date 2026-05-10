/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:05:31 by igilbert          #+#    #+#             */
/*   Updated: 2026/05/10 17:13:15 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <numbers...>" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe sorter(argv);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}