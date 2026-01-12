/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:55:49 by igilbert          #+#    #+#             */
/*   Updated: 2026/01/12 02:16:40 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <string>
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "Here comes the Cat !\n";
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Here comes the Cat !\n";
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat(){
	std::cout << "The Cat is gone...\n";
}

void Cat::makeSound() const {
	std::cout << "*meoooow meoooooooooow*\n";
}