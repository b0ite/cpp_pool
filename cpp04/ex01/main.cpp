/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 01:46:17 by igilbert          #+#    #+#             */
/*   Updated: 2026/01/12 02:29:19 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
	std::cout << "--- Test: création d'un tableau d'animaux ---" << std::endl;
	const int n = 4;
	Animal* animals[n];
	for (int i = 0; i < n; ++i) {
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << std::endl << "--- Test: makeSound() et getType() ---" << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cout << animals[i]->getType() << " : ";
		animals[i]->makeSound();
	}

	std::cout << std::endl << "--- Destruction des animaux ---" << std::endl;
	for (int i = 0; i < n; ++i) {
		delete animals[i];
	}

	std::cout << std::endl << "--- Test: copie et suppression pour vérifier la copie profonde ---" << std::endl;
	Cat* cat1 = new Cat();
	Cat* cat2 = new Cat(*cat1);
	std::cout << "Suppression de cat1..." << std::endl;
	delete cat1;
	std::cout << "cat2 après suppression de cat1 : ";
	cat2->makeSound();
	delete cat2;

	std::cout << std::endl << "--- Test: opérateur= et constructeur de copie pour Dog ---" << std::endl;
	Dog dog1;
	Dog dog2 = dog1;
	dog2.makeSound();
	Dog dog3;
	dog3 = dog1;
	dog3.makeSound();

	std::cout << std::endl << "--- Fin des tests ---" << std::endl;
	return 0;
}

