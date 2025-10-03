/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:11:19 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 17:00:13 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	setAttack(FRAG_ATTACK);
	setHealth(FRAG_HP);
	setEnergy(FRAG_ENERGY);
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