/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:06:04 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 14:56:19 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <string>
#include <iostream>

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	setAttack(20);
	setHealth(100);
	setEnergy(50);
	std::cout << "The ScavTrap " << getName() << " has been summoned\n";
}

ScavTrap::~ScavTrap() {
	std::cout << getName() << "the ScavTrap has been destroyed !\n";
}

void ScavTrap::attack(const std::string& target) {
	if (getHealth() <= 0) {
		std::cout << getName() << " the ScavTrap is dead, he can't do anything...\n";
		return ;
	}
	if (getEnergy() > 0) {
		std::cout << getName() << " the ScavTrap attacks " << target << ", causing " << getAttack() << " points of damage !\n";
		setEnergy(getEnergy() - 1);
	}
	else {
		std::cout << getName() << " doesn't have enough energy to attack...\n";
	}
}

void ScavTrap::guardGate() {
	if (getHealth() <= 0) {
		std::cout << getName() << " is dead, it can't enter Gate keeper mode...\n";
	}
	else {
		std::cout << getName() << " is now in Gate keeper mode.\n";
	}
}