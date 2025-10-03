/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:06:06 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 14:52:06 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
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
		void attack(const std::string& target) override;
		void guardGate();
};

#endif