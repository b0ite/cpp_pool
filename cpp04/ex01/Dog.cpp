/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:55:43 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/29 16:02:13 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog() : Animal("Dog"), brain(new Brain) {
	std::cout << "Here comes the Dog !\n";
}

Dog::Dog(const Dog &other) : Animal(other), brain(new Brain) {
	std::cout << "Here comes the Dog !\n";
}

Dog::~Dog(){
	std::cout << "The Dog is gone...\n";
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "*bark bark !!!*\n";
}