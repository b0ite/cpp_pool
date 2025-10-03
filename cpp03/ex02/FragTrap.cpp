/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:11:19 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 15:30:59 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	setAttack(30);
	setHealth(100);
	setEnergy(100);
	std::cout << "The FragTrap " << getName() << " has been summoned !\n";
}

FragTrap::~FragTrap() {
	std::cout << "The FragTrap " << getName() << " has been destroyed !\n";
}

void FragTrap::highFivesGuys() {
	if (getHealth() <= 0) {
		std::cout << getName() << " is dead, he can't high five...\n";
	}
	else if (getEnergy() <= 0)
	{
		std::cout << getName() << " doesn't have the energy to high five anymore...\n";
	}
	else {
		std::cout << getName() << ": Come here buddy, let's high five !\n";
	}
}