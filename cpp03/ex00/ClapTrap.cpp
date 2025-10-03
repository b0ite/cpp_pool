/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:55:23 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 12:37:43 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(std::string name) {
	std::cout << name << " has been summoned !\n";
	this->name = name;
}

ClapTrap::~ClapTrap() {
	std::cout << name << " has been destroyed !\n";
}

void ClapTrap::attack(const std::string& target) {
	if (energy > 0) {
		std::cout << name << " attacks " << target << ", causing " << atk << " points of damage !\n";
		energy--;
	}
	else {
		std::cout << name << " doesn't have enough energy to attack...\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << name << " has taken " << amount << " damages ! *Please repair shortly*\n";
	hp -= amount;
	if (hp <= 0) {
		std::cout << name << " died...\n";
		this->reset();
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energy > 0) {
		std::cout << name << " is fixing itself... " << amount << " health points regained ! (health: " << hp << ")\n";
		hp += amount;
		energy--;
	}
	else {
		std::cout << name << " doesn't have enough energy to repair itself...\n";
	}
}