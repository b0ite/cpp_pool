/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:52:56 by igilbert          #+#    #+#             */
/*   Updated: 2026/04/08 18:04:10 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "../includes/easyfind.hpp"

int main()
{
	std::cout << "--- Test avec std::vector ---" << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	try {
		std::cout << "Recherche de 20 : Trouvé à l'itérateur -> " << *easyfind(vec, 20) << std::endl;
		std::cout << "Recherche de 42 : ";
		std::cout << *easyfind(vec, 42) << std::endl; // Va lancer une exception
	} catch (const std::exception& e) {
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	}

	std::cout << "\n--- Test avec std::list ---" << std::endl;
	std::list<int> lst;
	lst.push_back(100);
	lst.push_back(200);

	try {
		std::cout << "Recherche de 100 : Trouvé à l'itérateur -> " << *easyfind(lst, 100) << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception attrapée : " << e.what() << std::endl;
	}
	return 0;
}
