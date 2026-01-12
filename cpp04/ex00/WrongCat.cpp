/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:55:34 by igilbert          #+#    #+#             */
/*   Updated: 2026/01/12 02:10:13 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Here comes the WrongCat !\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cout << "Here comes the WrongCat !\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << "The WrongCat is gone...\n";
}

void WrongCat::makeSound() const {
	std::cout << "*meoooow meoooooooooow*\n";
}