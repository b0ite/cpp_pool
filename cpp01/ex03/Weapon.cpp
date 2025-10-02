/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:21:20 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/01 17:58:00 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon( std::string type ) {
	this->type = type;
}

std::string &Weapon::getType() {
	return this->type;
}

void Weapon::setType(std::string t) {
	this->type = t;
}
