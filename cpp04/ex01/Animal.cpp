/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:21:02 by igilbert          #+#    #+#             */
/*   Updated: 2026/01/12 02:41:25 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal() {
	std::cout << "Here comes the... The Animal...\n";
}
Animal::Animal(const std::string& type) : type(type) {
	std::cout << "Here comes the... The Animal of type " << type << " !\n";
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Here comes the... The Animal...\n";
}

Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		type = other.type;
	}
	return (*this);
}

Animal::~Animal() {
	if (!type.empty()) {
		std::cout << "The hunter got the " << type << "... I'm sorry...\n";
	}
	else {
		std::cout << "The hunter got something...\n";
	}
}

void Animal::makeSound() const {
	if (!type.empty()) {
		std::cout << "You hear a noise... You think it\'s a " << type << "\n";
	}
	else {
		std::cout << "You hear a noise but can't tell from which animal it is...\n";
	}
}

std::string Animal::getType() const {
	return (type);
}

void Animal::setType(const std::string& type) {
	this->type = type;
}