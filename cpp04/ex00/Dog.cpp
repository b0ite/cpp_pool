/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:55:43 by igilbert          #+#    #+#             */
/*   Updated: 2026/01/12 02:16:40 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << "Here comes the Dog !\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Here comes the Dog !\n";
}

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog(){
	std::cout << "The Dog is gone...\n";
}

void Dog::makeSound() const {
	std::cout << "*bark bark !!!*\n";
}