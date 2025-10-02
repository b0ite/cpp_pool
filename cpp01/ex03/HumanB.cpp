/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:20:59 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/01 17:58:35 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
#include <string>
#include <iostream>

HumanB::HumanB( std::string name ) : name(name), weapon(nullptr) {}

void HumanB::attack() {
	if (!weapon) {
		std::cout << this->name << " attacks with... With nothing... " << std::endl;
	}
	else {
		std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
	}
}

void HumanB::setWeapon( Weapon weapon ) {
	this->weapon = &weapon;
}
