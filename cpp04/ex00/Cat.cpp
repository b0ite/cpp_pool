/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:55:49 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/04 13:23:44 by igilbert         ###   ########.fr       */
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

Cat::~Cat(){
	std::cout << "The Cat is gone...\n";
}

void Cat::makeSound() const {
	std::cout << "*meoooow meoooooooooow*\n";
}