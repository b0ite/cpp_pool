/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 01:46:17 by igilbert          #+#    #+#             */
/*   Updated: 2026/01/12 02:29:30 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
	// AAnimal test;  // Ne compile pas car AAnimal est abstraite.

	std::cout << "=== Tableau d'animaux ===" << std::endl;
	const int n = 4;
	AAnimal* animals[n];
	for (int i = 0; i < n; i++) {
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << "\n=== Sons ===" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	std::cout << "\n=== Destruction ===" << std::endl;
	for (int i = 0; i < n; i++)
		delete animals[i];

	std::cout << "\n=== Deep copy Cat ===" << std::endl;
	Cat* c1 = new Cat();
	Cat* c2 = new Cat(*c1);
	delete c1;
	std::cout << "c2 apres delete c1: ";
	c2->makeSound();
	delete c2;

	std::cout << "\n=== Copy Dog ===" << std::endl;
	Dog d1;
	Dog d2(d1);
	d2.makeSound();
	Dog d3;
	d3 = d1;
	d3.makeSound();

	std::cout << "\n=== Fin ===" << std::endl;
	return 0;
}

