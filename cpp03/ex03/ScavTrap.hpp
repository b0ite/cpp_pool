/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:06:06 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 16:58:47 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	protected:
		static const int SCAV_HP = 100;
        static const int SCAV_ENERGY = 50;
        static const int SCAV_ATTACK = 20;

	public:
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap& other) : ClapTrap(other) {
			std::cout << "ScavTrap copy constructed\n";
		}
		ScavTrap &operator=(const ScavTrap &other) {
			if (this != &other) {
				ClapTrap::operator=(other);
			}
			return (*this);
		}
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
};

#endif