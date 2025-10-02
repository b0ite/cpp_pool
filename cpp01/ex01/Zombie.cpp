/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:49:26 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/01 15:05:40 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	name = "";
}

void Zombie::setName(std::string n) {
	name = n;
}

Zombie::Zombie( const std::string name ) {
	this->name = name;
	std::cout << name << " has risen from the grave!" << std::endl;
}
Zombie::~Zombie( void ) {
	std::cout << name << " has been slain by Kyle Crane..." << std::endl;
}

void Zombie::announce ( void ) const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie( std::string name ) {
	return new Zombie( name );
}