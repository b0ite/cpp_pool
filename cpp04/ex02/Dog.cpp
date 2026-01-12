/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:55:43 by igilbert          #+#    #+#             */
/*   Updated: 2026/01/12 02:28:14 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog() : AAnimal("Dog"), brain(new Brain) {
	std::cout << "Here comes the Dog !\n";
}

Dog::Dog(const Dog &other) : AAnimal(other), brain(new Brain(*other.brain)) {
	std::cout << "Here comes the Dog !\n";
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		AAnimal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog(){
	std::cout << "The Dog is gone...\n";
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "*bark bark !!!*\n";
}