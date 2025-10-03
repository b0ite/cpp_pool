/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:55:23 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 15:07:57 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

ClapTrap::ClapTrap(const std::string& name) {
	std::cout << name << " has been summoned !\n";
	this->name = name;
	hp = 10;
	atk = 0;
	energy = 10;
}

ClapTrap::~ClapTrap() {
	std::cout << name << " has been destroyed !\n";
}

void ClapTrap::attack(const std::string& target) {
	if (hp <= 0) {
		std::cout << name << " is dead, he can't do anything...\n";
		return ;
	}
	if (energy > 0) {
		std::cout << name << " attacks " << target << ", causing " << atk << " points of damage !\n";
		energy--;
	}
	else {
		std::cout << name << " doesn't have enough energy to attack...\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hp <= 0) {
		std::cout << name << " is dead, he can't take more damage\n";
		return ;
	}
	std::cout << name << " has taken " << amount << " damages ! *Please repair shortly*\n";
	hp -= amount;
	if (hp <= 0) {
		std::cout << name << " died...\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hp <= 0) {
		std::cout << name << " is dead, he can't do anything...\n";
		return ;
	}
	if (energy > 0) {
		hp += amount;
		std::cout << name << " is fixing itself... " << amount << " health points regained ! (health: " << hp << ")\n";
		energy--;
	}
	else {
		std::cout << name << " doesn't have enough energy to repair itself...\n";
	}
}