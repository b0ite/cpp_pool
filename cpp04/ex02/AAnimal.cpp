/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:21:02 by igilbert          #+#    #+#             */
/*   Updated: 2026/01/12 02:16:40 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <string>
#include <iostream>

AAnimal::AAnimal() {
	std::cout << "Here comes the... The AAnimal...\n";
}
AAnimal::AAnimal(const std::string& type) : type(type) {
	std::cout << "Here comes the... The AAnimal of type " << type << " !\n";
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type) {
	std::cout << "Here comes the... The AAnimal...\n";
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	if (this != &other) {
		type = other.type;
	}
	return (*this);
}

AAnimal::~AAnimal() {
	if (!type.empty()) {
		std::cout << "The hunter got the " << type << "... I'm sorry...\n";
	}
	else {
		std::cout << "The hunter got something...\n";
	}
}

std::string AAnimal::getType() const {
	return (type);
}

void AAnimal::setType(const std::string& type) {
	this->type = type;
}