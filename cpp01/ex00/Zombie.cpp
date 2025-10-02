/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:15:35 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/01 12:54:30 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

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
