/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:21:12 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/01 17:43:07 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include <string>
#include <iostream>

HumanA::HumanA( std::string name, Weapon &weapon ) : name(name), weapon(weapon) {}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}