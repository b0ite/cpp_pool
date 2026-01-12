/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:55:49 by igilbert          #+#    #+#             */
/*   Updated: 2026/01/12 02:28:14 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <string>
#include <iostream>

Cat::Cat() : Animal("Cat"), brain(new Brain()) {
	std::cout << "Here comes the Cat !\n";
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "Here comes the Cat !\n";
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat(){
	std::cout << "The Cat is gone...\n";
	delete brain;
}

void Cat::makeSound() const {
	std::cout << "*meoooow meoooooooooow*\n";
}