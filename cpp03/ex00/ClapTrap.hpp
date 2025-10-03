/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:55:21 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 12:23:37 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string name;
		int hp = 10;
		int energy = 10;
		int atk = 0;
	
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &other) : name(other.name), hp(other.hp), energy(other.energy), atk(other.atk) {
		}
		ClapTrap &operator=(ClapTrap &other) {
			if (this != &other) {
				name = other.name;
				hp = other.hp;
				energy = other.energy;
				atk = other.atk;
			}
			return (*this);
		}
		~ClapTrap();
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif