/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:21:16 by igilbert          #+#    #+#             */
/*   Updated: 2025/10/01 17:40:09 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA {
	private:
		std::string name;
		Weapon &weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		void attack();
};
