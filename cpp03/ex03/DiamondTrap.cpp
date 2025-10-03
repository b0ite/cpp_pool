/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:57:14 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 17:03:14 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

DiamondTrap::DiamondTrap( const std::string &name ) :
	ClapTrap(name + "_clap_name"),
	FragTrap(name),
	ScavTrap(name),
	name(name) {
		setHealth(FragTrap::FRAG_HP);
		setEnergy(ScavTrap::SCAV_ENERGY);
		setAttack(FragTrap::FRAG_ATTACK);
		std::cout << "The DiamondTrap " << this->name << " has been summoned !\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name) {
	std::cout << "DiamondTrap copy constructed\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		name = other.name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "The DiamondTrap " << this->name << " has been destroyed !\n";
}

void DiamondTrap::attack( const std::string &target ) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
}