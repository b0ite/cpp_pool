/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:55:21 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 14:47:59 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string name;
		int hp;
		int energy;
		int atk;

	protected:
    	void setEnergy(int e) {
			energy = e;
		}
		void setHealth(int h) {
			hp = h;
		}
		void setAttack(int a) {
			atk = a;
		}
	
	public:
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& other) : name(other.name), hp(other.hp), energy(other.energy), atk(other.atk) {
			std::cout << name << " has been summoned !\n";
		}
		ClapTrap &operator=(const ClapTrap& other) {
			if (this != &other) {
				name = other.name;
				hp = other.hp;
				energy = other.energy;
				atk = other.atk;
			}
			return (*this);
		}
		virtual ~ClapTrap();
		
		const std::string getName() const { return name; }
		const int getHealth() const { return hp; }
		const int getEnergy() const { return energy; }
		const int getAttack() const { return atk; }
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif