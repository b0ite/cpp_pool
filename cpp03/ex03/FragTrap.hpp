/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:11:21 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/03 16:59:41 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	protected:
		static const int FRAG_HP = 100;
        static const int FRAG_ENERGY = 100;
        static const int FRAG_ATTACK = 30;
	public:
		FragTrap(const std::string name);
		FragTrap(const FragTrap& other) : ClapTrap(other) {
			std::cout << "FragTrap copy constructed\n";
		}
		FragTrap &operator=(const FragTrap &other) {
			if (this != &other) {
				ClapTrap::operator=(other);
			}
			return (*this);
		}
		~FragTrap();
		void  highFivesGuys();
};

#endif