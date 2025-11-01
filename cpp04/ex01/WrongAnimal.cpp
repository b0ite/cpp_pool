/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:54:54 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/04 14:07:38 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal() {
	std::cout << "Here comes the... The WrongAnimal...\n";
}
WrongAnimal::WrongAnimal(const std::string type) : type(type) {
	std::cout << "Here comes the... The WrongAnimal of type " << type << " !\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
	std::cout << "Here comes the... The WrongAnimal...\n";
}

WrongAnimal::~WrongAnimal() {
	if (!type.empty()) {
		std::cout << "The hunter got the " << type << "... I'm sorry...\n";
	}
	else {
		std::cout << "The hunter got something...\n";
	}
}

void WrongAnimal::makeSound() const {
	if (!type.empty()) {
		std::cout << "You hear a noise... You think it\'s a " << type << "\n";
	}
	else {
		std::cout << "You hear a noise but can't tell from which animal it is...\n";
	}
}

std::string WrongAnimal::getType() const {
	return (type);
}

void WrongAnimal::setType(std::string type) {
	this->type = type;
}